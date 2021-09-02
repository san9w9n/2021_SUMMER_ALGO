#include <bits/stdc++.h>
using namespace std;
int N, ans;
int MAP[20][20];

//상태는 가로, 세로, 대각선이 있다.
//각각 0 1 2 라고 하고
typedef struct {
    pair<int, int> rearD;
    pair<int, int> frontD;
    int nextState;
} Dir;

vector<Dir> dir[3];


void btk(int state, int rx, int ry, int fx, int fy) {
    int nrx, nry, nfx, nfy, nstate;
    if(fx==N-1 && fy==N-1) {
        ans++;
        return;
    }

    for(int d=0; d<dir[state].size(); d++) {
        nrx=rx+dir[state][d].rearD.first; nry=ry+dir[state][d].rearD.second;
        nfx=fx+dir[state][d].frontD.first; nfy=fy+dir[state][d].frontD.second;
        nstate = dir[state][d].nextState;

        if(nrx<0||nry<0||nrx>=N||nry>=N||MAP[nrx][nry]==1) continue;
        if(nfx<0||nfy<0||nfx>=N||nfy>=N||MAP[nfx][nfy]==1) continue;
        if(nstate==2) {
            if(MAP[nrx][nry+1] == 1) continue;
            if(MAP[nrx+1][nry] == 1) continue;
        }
        btk(nstate, nrx, nry, nfx, nfy);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> MAP[i][j];

    //방향 정보.
    dir[0].push_back({make_pair(0, 1), make_pair(0, 1), 0});
    dir[0].push_back({make_pair(0, 1), make_pair(1, 1), 2});
    dir[1].push_back({make_pair(1, 0), make_pair(1, 0), 1});
    dir[1].push_back({make_pair(1, 0), make_pair(1, 1), 2});
    dir[2].push_back({make_pair(1, 1), make_pair(0, 1), 0});
    dir[2].push_back({make_pair(1, 1), make_pair(1, 0), 1});
    dir[2].push_back({make_pair(1, 1), make_pair(1, 1), 2});
    
    btk(0, 0, 0, 0, 1);

    cout << ans;
    return 0;
}