#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int K, C, R;
int board[202][202];
int dist[32][202][202]; //3점프당 거리

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int ddx[8] = {2,2,1,1,-2,-2,-1,-1};
int ddy[8] = {1,-1,2,-2,1,-1,2,-2};

int bfs() {
    int x, y, jump, r, c;
    queue<pair<pair<int, int>, int>> Q; //{{x, y}, 점프횟수}
    Q.push({{0,0},0});
    dist[0][0][0] = 1;
    while(!Q.empty()) {
        x = Q.front().first.X; y = Q.front().first.Y;
        jump = Q.front().second;
        if(x==R-1 && y==C-1) return dist[jump][x][y]-1;
        Q.pop();

        if(jump<K) { //점프 다 안 사용
            for(int d=0; d<8; d++) {
                r=x+ddx[d]; c=y+ddy[d];
                if(r<0 || c<0 || r>=R || c>=C || board[r][c]==1) continue;
                if(dist[jump+1][r][c]!=0 && dist[jump+1][r][c] <= dist[jump][x][y] + 1) continue;
                dist[jump+1][r][c] = dist[jump][x][y] + 1;
                Q.push({{r, c}, jump+1});
            }
        }
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0 || c<0 || r>=R || c>=C || board[r][c]==1) continue;
            if(dist[jump][r][c]!=0 && dist[jump][r][c] <= dist[jump][x][y] + 1) continue;
            dist[jump][r][c] = dist[jump][x][y] + 1;
            Q.push({{r, c}, jump});
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<32; i++) {
        for(int j=0; j<202; j++) {
            for(int k=0; k<202; k++) {
                dist[i][j][k]=0;
            }
        }
    }
    cin >> K;
    cin >> C >> R;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++)
            cin >> board[i][j];
    }
    cout << bfs();
    
    return 0;
}