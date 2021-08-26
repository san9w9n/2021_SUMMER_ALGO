#include <bits/stdc++.h> 
using namespace std;
int N;
deque<deque<int>> Blue(6, deque<int>(4)), Green(6, deque<int>(4));
int dx[3]={0,0,1}, dy[3]={0,1,0}, now=1, score;

int status(deque<int>& x){
    int cnt0 = 0;
    for(int i=0; i<4; i++) if(x[i]==0) cnt0++;
    if(cnt0 == 4) return 0;
    if(cnt0 == 0) return 1;
    return 2;
}

void addBlock(int t, int v, deque<deque<int>>& color, int row) {
    while(true) {
        if(color[row][v] || color[row+dx[t]][v+dy[t]]) { row--; break; }
        if(t==2 && row==4) break;
        if(row==5) break;
        row++;
    }
    color[row][v] = color[row+dx[t]][v+dy[t]] = now++;
}

void add(int t, int x, deque<deque<int>>& board) {
    addBlock(t, x, board, 0);

    while(true) {
        int idx = 2;
        while(idx<6 && status(board[idx])!=1) idx++;
        if(idx==6) break;
        score++;
        board[idx] = deque<int>(4);
        for(int i=idx-1; i>=0; i--) {
            for(int j=0; j<4; j++) {
                if(board[i][j]==0) continue;
                if(j!=3 && board[i][j] == board[i][j+1]) {
                    board[i][j] = board[i][j+1] = 0;
                    addBlock(1, j, board, i);
                } else if(i!=0 && board[i-1][j] == board[i][j]) {
                    board[i][j] = board[i-1][j] = 0;
                    addBlock(2, j, board, i-1);
                } else {
                    board[i][j] = 0;
                    addBlock(0, j, board, i);
                }
            }
        }
    }

    if(status(board[0])!=0) {
        board.pop_back(); board.pop_back();
        board.push_front(deque<int>(4)); board.push_front(deque<int>(4));
    } else if(status(board[1])!=0) {
        board.pop_back();
        board.push_front(deque<int>(4));
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t==1) {
            add(0, y, Green);
            add(0, x, Blue);
        } else if(t==2) {
            add(1, y, Green);
            add(2, x, Blue);
        } else {
            add(2, y, Green);
            add(1, x, Blue);
        }
    }
    int cnt = 0;
    for(int i=0; i<6; i++) for(int j=0; j<4; j++) cnt+=(Blue[i][j]!=0) + (Green[i][j]!=0);
    
    cout << score << '\n' << cnt;
    return 0;
}