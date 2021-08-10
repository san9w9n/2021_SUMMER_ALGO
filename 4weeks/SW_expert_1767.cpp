#include <iostream>
#include <vector>
using namespace std;
int N, ans, ansDist=1e9;
int board[13][13];
vector<pair<int, int>> cell;
int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};

int drawRoad(int x, int y, int d) {
    int r=x, c=y;
    int dist = 0;
    while(1) {
        r=r+dx[d]; c=c+dy[d];
        if(r<0 || c<0 || r>=N || c>=N) break;
        if(board[r][c]!=0) {
            dist = 0;
            break;
        }
        dist++;
    }
    if(dist>0) {
        r=x; c=y;
        while(1) {
            r=r+dx[d]; c=c+dy[d];
            if(r<0 || c<0 || r>=N || c>=N) break;
            board[r][c] = 1;
        }
    }
    return dist;
}

void recoverRoad(int x, int y, int d) {
    int r=x, c=y;
    while(1) {
        r=r+dx[d]; c=c+dy[d];
        if(r<0 || c<0 || r>=N || c>=N) break;
        board[r][c] = 0;
    }
}

void btk(int k, int cnt, int dist) {
    if(k==cell.size()) {
        if(ansDist!=1e9) {
            if(ans<cnt) {
                ans=cnt;
                ansDist = dist;
            } else if(ans==cnt) {
                if(ansDist>dist) ansDist = dist;
            }
        } else {
            ans = cnt;
            ansDist = dist;
        }
        return;
    }
    int x=cell[k].first, y=cell[k].second;
    for(int d=0; d<4; d++) {
        int check = drawRoad(x, y, d);
        if(check>0) btk(k+1, cnt+1, dist+check);
        else btk(k+1, cnt, dist);
        if(check>0) recoverRoad(x, y, d);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        if(!cell.empty()) cell.clear();
        ansDist=1e9;
        ans = 0;
        cin >> N;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> board[i][j];
                if(board[i][j]==1) {
                    if(i==0 || j==0 || i==N-1 || j==N-1) ans++;
                    else cell.push_back({i, j});
                }
                
            }
        }
        btk(0, 0, 0);
        cout << '#' << t << ' ' << ansDist << '\n';
    }

    return 0;
}