#include <bits/stdc++.h>
using namespace std;
int N, M, P;
int len[10];
int field[1002][1002];
queue<pair<pair<int, int>, int>> player[10];
queue<pair<pair<int, int>, int>> playerTmp[10];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int ans[10];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> P;
    for(int i=1; i<=P; i++) cin >> len[i];

    string line;
    for(int i=0; i<N; i++) {
        cin >> line;
        for(int j=0; j<M; j++) {
            if(line[j]=='.') {
                field[i][j] = 0;
            } else if(line[j]=='#') {
                field[i][j] = -1;
            } else {
                int t = line[j]-'0';
                field[i][j] = t;
                player[t].push({{i,j}, len[t]});
            }
        }
    }
    int t=1;
    bool check=true;
    while(check) {
        check = false;
        for(int t=1; t<=P; t++) {
            while(!playerTmp[t].empty()) {
                player[t].push(playerTmp[t].front());
                playerTmp[t].pop();
            }
            while(!player[t].empty()) {
                int x, y, r, c, go;
                x = player[t].front().first.first;
                y = player[t].front().first.second;
                go = player[t].front().second;
                player[t].pop();
                if(go==0) {
                    if(playerTmp[t].front().first.first==x &&
                        playerTmp[t].front().first.second==y &&
                        playerTmp[t].front().second==len[r]) continue;
                    playerTmp[t].push({{x, y}, len[t]});
                    check = true;
                    continue;
                }
                for(int d=0; d<4; d++) {
                    r=x+dx[d]; c=y+dy[d];
                    if(r<0 || c<0 || r>=N || c>=M || field[r][c]!=0) continue;
                    field[r][c]=t;
                    player[t].push({{r,c}, go-1});
                }
            }
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(field[i][j]>0) ans[field[i][j]]++;
        }
    }
    for(int i=1; i<P; i++) cout << ans[i] << ' ';
    cout << ans[P];
    return 0;
}