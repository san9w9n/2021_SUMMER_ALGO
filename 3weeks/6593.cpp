#include <bits/stdc++.h>
using namespace std;
int L, R, C;
int sx, sy, sl, tx, ty, tl;
string field[32][32];
int dist[32][32][32];
int du[6] = {0,0,0,0,1,-1};
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,-1,0,1,0,0};

int bfs() {
    int r, c, h, x, y, l;
    queue<pair<int, pair<int, int>>> Q; //{층, {x, y}}
    Q.push({sl, {sx, sy}});
    dist[sl][sx][sy] = 1;
    while(!Q.empty()) {
        l = Q.front().first;
        x = Q.front().second.first;
        y = Q.front().second.second;
        Q.pop();
        if(l==tl && x==tx && y==ty) return dist[l][x][y]-1;
        for(int d=0; d<6; d++) {
            h=l+du[d]; r=x+dx[d]; c=y+dy[d];
            if(h<0 || r<0 || c<0 || h>=L || r>=R || c>=C || field[h][r][c]=='#') continue;
            if(dist[h][r][c]!=0 && dist[h][r][c]<=dist[l][x][y]+1) continue;
            dist[h][r][c]=dist[l][x][y]+1;
            Q.push({h, {r, c}});
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    while(true) {
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0) break;
        for(int i=0; i<L; i++) {
            for(int j=0; j<R; j++) {
                cin >> field[i][j];
                for(int k=0; k<C; k++) {
                    dist[i][j][k] = 0;
                    if(field[i][j][k]=='S')  {
                        sl=i; sx=j; sy=k;
                    } else if(field[i][j][k]=='E') {
                        tl=i; tx=j; ty=k;
                    }
                }
            }
        }
        int ans = bfs();
        if(ans!=-1) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}