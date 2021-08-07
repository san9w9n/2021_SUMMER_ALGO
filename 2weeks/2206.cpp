#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define X first
#define Y second

int N, M;
int dist[MAX][MAX][2];
int wall[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int bfs() {
    queue<pair<pair<int, int>,int>> Q;
    Q.push({{0, 0}, 1});
    dist[0][0][1]=1;

    while(!Q.empty()) {
        int x = Q.front().first.X;
        int y = Q.front().first.Y;
        int able = Q.front().second;
        if(x==N-1 && y==M-1) return dist[x][y][able];
        Q.pop();
        for(int d=0; d<4; d++) {
            int r = x+dx[d];
            int c = y+dy[d];
            if(r<0||c<0||r>=N||c>=M) continue;
            if(able==1 && wall[r][c]==-1) {
                dist[r][c][0] = dist[x][y][1]+1;
                Q.push({{r, c}, 0});
            }
            if(wall[r][c]==0 && dist[r][c][able]==0) {
                dist[r][c][able] = dist[x][y][able]+1;
                Q.push({{r, c}, able});
            }
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string line;
        cin >> line;
        for(int j=0; j<M; j++) {
            int e = line[j]-'0';
            if(e==1) e=-1;
            wall[i][j] = e;
        }
    }
    cout << bfs();
    return 0;
}