#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int N, L;
int field[102][102];
int dx[2]={0,1}, dy[2]={1,0};
int ans;

void bfs(int x, int y, int d) {
    int r, c, jump;
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{x, y}, 0});
    Q.push({{x, y}, 1});

    while(!Q.empty()) {
        x=Q.front().F.F; y=Q.front().F.S;
        jump=Q.front().S; Q.pop();

        r=x+dx[d]; c=y+dy[d];
        if(r>=N || c>=N) {
            if(jump==0) ans++;
            return;
        }
        if(field[r][c]==field[x][y]-1) {
            if(jump==0) {
                int nr, nc, l=1;
                bool flag = true;
                while(l<L) {
                    nr=r+dx[d]; nc=c+dy[d];
                    if(nr>=N || nc>=N || field[nr][nc]!=field[r][c]) {
                        flag = false;
                        break;
                    }
                    r=nr; c=nc;
                    l++;
                }
                if(!flag) continue;
                int nnr=r+dx[d], nnc=c+dy[d];
                if(nnr>=N || nnc>=N) {
                    ans++;
                    return;
                }
                if(field[nnr][nnc]==field[r][c]) {
                    Q.push({{nnr, nnc} ,0});
                    Q.push({{nnr, nnc} ,1});
                } else if(field[nnr][nnc]==field[r][c]-1) {
                    Q.push({{r, c}, 0});
                }
            }
            continue;
        }
        if(jump==L) {
            if(field[r][c]==field[x][y]+1) {
                Q.push({{r, c}, 0});
                Q.push({{r, c}, 1});
            }
        } else if(jump<L && jump>0) {
            if(field[r][c]==field[x][y]) Q.push({{r, c}, jump+1});
        } else if(jump==0) {
            if(field[r][c]==field[x][y]) {
                Q.push({{r, c}, 0});
                Q.push({{r, c}, 1});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> field[i][j];
    for(int i=0; i<N; i++) bfs(i, 0, 0);
    for(int j=0; j<N; j++) bfs(0, j, 1);
    cout << ans;
    return 0;
}