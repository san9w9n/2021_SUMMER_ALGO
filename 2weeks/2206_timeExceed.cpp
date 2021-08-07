#include <bits/stdc++.h>
using namespace std;
int N, M, tx, ty;
int dist[1002][1002];
stack<pair<int, int>> Wall;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void copy(int** tmp) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) tmp[i][j] = dist[i][j];
    }
}

int main(void) {
    cin >> N >> M;
    tx = N-1;
    ty = M-1;

    for(int i=0; i<N; i++) {
        string line;
        cin >> line;
        for(int j=0; j<M; j++) {
            int e = line[j]-'0';
            if(e==1) {
                Wall.push({i,j});
                e=-1;
            }
            dist[i][j] = e;
        }
    }
    int cnt=0;
    int wallX, wallY;
    int mini = 1987654321;

    while(!Wall.empty()) {
        if(cnt>0) {
            wallX = Wall.top().first;
            wallY = Wall.top().second;
            dist[wallX][wallY] = 0;
            Wall.pop();
        }
        int** tmp = new int*[N]();
        for(int i=0; i<N; i++) tmp[i] = new int[M]();
        queue<pair<int, int>> Q;
        copy(tmp);
        Q.push({0, 0});
        tmp[0][0] = 1;
        while(!Q.empty()) {
            int x, y;
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for(int i=0; i<4; i++) {
                int r, c;
                r = x + dx[i];
                c = y + dy[i];
                if(r==tx && c==ty) {
                    if(mini>tmp[x][y]+1) mini = tmp[x][y]+1;
                    break;
                }
                if(r<0 || c<0 || r>=N || c>=M) continue;
                if(tmp[r][c]==-1) continue;
                if(tmp[r][c]!=0 && tmp[r][c]<=tmp[x][y]+1) continue;
                tmp[r][c] = tmp[x][y] + 1;
                Q.push({r, c});
            }
        }
        for(int i=0; i<N; ++i) delete [] tmp[i];
        delete [] tmp;
        if(cnt>0) dist[wallX][wallY] = -1;
        cnt++;
    }
    if(mini == 1987654321) cout << -1;
    else cout << mini;
    return 0;
}