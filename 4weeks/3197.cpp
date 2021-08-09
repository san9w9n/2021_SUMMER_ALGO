#include <bits/stdc++.h>
using namespace std;
int R, C, sx=-1, sy=-1, tx=-1, ty=-1, ans=0;
int field[1502][1502];
bool visited[1502][1502];
queue<pair<int, int>> water;
queue<pair<int, int>> waterTmp;
queue<pair<int, int>> swan;
queue<pair<int, int>> swanTmp;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

void melt() {
    int x, y, r, c;
    while(!waterTmp.empty()) {
        water.push(waterTmp.front());
        waterTmp.pop();
    }
    while(!water.empty()) {
        x=water.front().first; y=water.front().second;
        water.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=R||c>=C) continue;
            if(field[r][c]==1) {
                waterTmp.push({r, c});
                field[r][c] = 0;
                continue;
            }
        }
    }
}

bool bfs() {
    int x, y, r, c;
    while(!swanTmp.empty()) {
        swan.push(swanTmp.front());
        swanTmp.pop();
    }
    while(!swan.empty()) {
        x=swan.front().first; y=swan.front().second;
        if(x==tx && y==ty) return true;
        swan.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0 || c<0 || r>=R || c>=C) continue;
            if(visited[r][c]) continue;
            if(field[r][c]==1) {
                swanTmp.push({r, c});
                visited[r][c] = true;
                continue;
            }
            visited[r][c] = true;
            swan.push({r, c});
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            visited[i][j] = false;
        }
    }
    string line;
    for(int i=0; i<R; i++) {
        cin >> line;
        for(int j=0; j<C; j++) {
            if(line[j]=='.') {
                field[i][j] = 0;
                water.push({i, j});
            } else if(line[j]=='X') field[i][j] = 1;
            else {
                field[i][j] = 0;
                water.push({i, j});
                if(sx!=-1) {
                    tx=i; ty=j;
                } else {
                    sx=i; sy=j;
                }
            }
        }
    }
    bool check = false;
    swan.push({sx, sy});
	visited[sx][sy] = true;
    while(!check) {
        check = bfs();
        if(check) break;
        melt();
        ans++;
    }
    cout << ans;
    return 0;
}