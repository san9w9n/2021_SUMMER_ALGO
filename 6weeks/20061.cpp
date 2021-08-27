#include <bits/stdc++.h>
using namespace std;
int N;
deque<deque<int>> B(6, deque<int>(4)), G(6, deque<int>(4));
int dx[3]={0,0,1}, dy[3]={0,1,0}, now=1, score;


void debug() {
    cout << "---------------------\n";
    cout << "Green: \n";
    for(int i=0; i<6; i++) {
        for(int j=0; j<4; j++) cout << G[i][j] << "  ";
        cout << "\n";
    }
    cout << "Blue: \n";
    for(int i=0; i<6; i++) {
        for(int j=0; j<4; j++) cout << B[i][j] << "  ";
        cout << "\n";
    }
}

int status(deque<int> row) {
    int cnt=0;
    for(int i=0; i<4; i++) if(row[i]==0) cnt++;
    if(cnt==0) return 1;
    if(cnt==4) return 0;
    return 2;
}

void add_Block(int t, int x, int y, deque<deque<int>> &board) {
    while(1) {
        if(board[x][y] || board[x+dx[t]][y+dy[t]]) { x--; break; }
        if(t==2 && x==4) break;
        if(x==5) break;
        x++;
    }
    board[x][y] = board[x+dx[t]][y+dy[t]] = now;
    now++;
}


void findFUll(deque<deque<int>> &board) {
    int idxSave[6] = {0, 1, 2, 3, 4, 5};
    int deleted = 0;
    while(true) {
        int idx = 2;
        while(idx<6 && status(board[idx])!=1) idx++;
        if(idx==6) break;
        idxSave[idx] = -1;
        deleted++;
        score++;
        board[idx] = deque<int>(4);
    }

    if(deleted==0) return;
    int r = deleted;
    deque<deque<int>> tmp(6, deque<int>(4));
    for(int i=0; i<6; i++) {
        if(idxSave[i]==-1) continue;
        for(int j=0; j<4; j++) tmp[r][j] = board[i][j];
        r++;
    }

    for(int i=0; i<6; i++) for(int j=0; j<4; j++) board[i][j] = tmp[i][j];

}

void deleteLine(deque<deque<int>> &board) {
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
            add_Block(0, 0, y, G);
            add_Block(0, 0, x, B);
        } else if(t==2) {
            add_Block(1, 0, y, G);
            add_Block(2, 0, x, B);
        } else {
            add_Block(2, 0, y, G);
            add_Block(1, 0, x, B);
        }

        findFUll(G); findFUll(B);
        deleteLine(G); deleteLine(B);
    }

    int cnt = 0;
    for(int i=0; i<6; i++) for(int j=0; j<4; j++) cnt+=(B[i][j]!=0) + (G[i][j]!=0);
    
    cout << score << '\n' << cnt;
    return 0;
}