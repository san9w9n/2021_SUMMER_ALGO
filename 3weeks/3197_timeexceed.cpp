#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int R, C, ax, ay, bx, by, ans=0;
int field[1502][1502];
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool bfs(int time) {
    int x,y,r,c;
    queue<pair<int, int>> move;
    bool visited[1502][1502];
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            visited[i][j] = false;
        }
    }
    move.push({ax, ay});
    visited[ax][ay] = true;
    while(!move.empty()) {
        x=move.front().X; y=move.front().Y;
        move.pop();
        if(x==bx && y==by) return true;
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=R||c>=C) continue;
            if(visited[r][c]) continue;
            if(field[r][c]>time) continue;
            visited[r][c]=true;
            move.push({r, c});
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    int cnt=0;
    for(int i=0; i<R; i++) {
        string line;
        cin >> line;
        for(int j=0; j<C; j++) {
            if(line[j]=='L') {
                field[i][j] = 0;
                if(cnt==0) {
                    ax=i; ay=j;
                    cnt++;
                } else {
                    bx=i; by=j;
                    cnt++;
                }
            } else if(line[j]=='.') {
                field[i][j] = 0;
                Q.push({i, j});
            } else {
                field[i][j] = -1;
            }
        }
    }
    while(!Q.empty()) {
        int x, y, r, c;
        x = Q.front().X; y = Q.front().Y; Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=R||c>=C) continue;
            if(field[r][c]!=-1 && field[r][c]<=field[x][y]+1) continue;
            field[r][c] = field[x][y]+1;
            Q.push({r, c});
        }
    }
    bool check = false;
    while(!check) { 
        check = bfs(ans);
        ans++;
    }
    cout << ans-1;
    return 0;
}