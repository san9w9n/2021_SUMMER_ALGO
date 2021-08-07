#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N, M;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string input[1002];
queue<pair<int, int>> J;
queue<pair<int, int>> F;
int Jdist[1002][1002];
int Fdist[1002][1002];


void doubleBFS() {
    int cnt=0;
    int r, c;
    while(!F.empty()) {
        auto pos = F.front();
        F.pop();
        for(int i=0; i<4; i++) {
            r = pos.X + dx[i];
            c = pos.Y + dy[i];
            if(r<0 || r>=N || c<0 || c>=M || input[r][c]=='#' || Fdist[r][c]>=0) continue;
            Fdist[r][c] = Fdist[pos.X][pos.Y] + 1;
            F.push({r,c});
        }
    }

    while(!J.empty()) {
        auto pos = J.front();
        J.pop();
        for(int i=0; i<4; i++) {
            r = pos.X + dx[i];
            c = pos.Y + dy[i];
            if(r<0 || r>=N || c<0 || c>=M) {
                cout << Jdist[pos.X][pos.Y] + 1;
                return;
            }
            if(Jdist[r][c] >= 0 || input[r][c] == '#') continue;
            if(Fdist[r][c] != -1 && Fdist[r][c] <= Jdist[pos.X][pos.Y] + 1) continue;
            Jdist[r][c] = Jdist[pos.X][pos.Y] + 1;
            J.push({r,c});
        }
    }
    cout << "IMPOSSIBLE";
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        fill(Fdist[i], Fdist[i]+M, -1);
        fill(Jdist[i], Jdist[i]+M, -1);    
    }
    for(int i = 0; i < N; i++) cin >> input[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(input[i][j] == 'F'){
                F.push({i,j});
                Fdist[i][j] = 0;        
            }
            if(input[i][j] == 'J'){
                J.push({i,j});
                Jdist[i][j] = 0;
            }
        }
    }
    doubleBFS();
    return 0;
}