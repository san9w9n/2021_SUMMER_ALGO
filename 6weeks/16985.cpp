#include <bits/stdc++.h>
using namespace std;
const int N=5;
int maze[N][N][N], ans=1e9; // 층 -> 행 -> 열
int dx[6]={1,-1,0,0,0,0}, dy[6]={0,0,1,-1,0,0}, dz[6]={0,0,0,0,1,-1};
int brute[5] = {0, 1, 2, 3, 4};

void rotateMaze(int k, int cnt) {
    if(cnt==1) {
        int tmp1[4], tmp2[4];
        for(int j=0; j<4; j++) tmp1[j] = maze[k][0][j];
        for(int i=1; i<5; i++) maze[k][0][4-i] = maze[k][i][0];
        for(int j=1; j<5; j++) maze[k][j][0] = maze[k][4][j];
        for(int i=1; i<5; i++) maze[k][4][i] = maze[k][4-i][N-1];
        for(int j=0; j<4; j++) maze[k][j][N-1] = tmp1[j];
    
        for(int j=1; j<3; j++) tmp2[j] = maze[k][1][j];
        for(int i=2; i<4; i++) maze[k][1][4-i] = maze[k][i][1];
        for(int j=2; j<4; j++) maze[k][j][1] = maze[k][N-2][j];
        for(int i=2; i<4; i++) maze[k][N-2][i] = maze[k][4-i][N-2];
        for(int j=1; j<3; j++) maze[k][j][N-2] = tmp2[j];
    } else if(cnt==2) {
        int tmp[5];
        for(int j=0; j<5; j++) tmp[j] = maze[k][0][j];
        for(int j=0; j<5; j++) maze[k][0][j] = maze[k][N-1][4-j];
        for(int j=0; j<5; j++) maze[k][N-1][4-j] = tmp[j];
        for(int j=0; j<5; j++) tmp[j] = maze[k][1][j];
        for(int j=0; j<5; j++) maze[k][1][j] = maze[k][N-2][4-j];
        for(int j=0; j<5; j++) maze[k][N-2][4-j] = tmp[j];
        for(int j=0; j<2; j++) tmp[j] = maze[k][2][j];
        for(int j=0; j<2; j++) maze[k][2][j] = maze[k][2][4-j];
        for(int j=0; j<2; j++) maze[k][2][4-j] = tmp[j];
    } else if(cnt==3) {
        int tmp1[4], tmp2[4];
        for(int j=0; j<4; j++) tmp1[j] = maze[k][0][j];
        for(int i=0; i<4; i++) maze[k][0][i] = maze[k][i][4];
        for(int i=0; i<4; i++) maze[k][i][4] = maze[k][4][4-i];
        for(int i=0; i<4; i++) maze[k][4][4-i] = maze[k][4-i][0];
        for(int i=0; i<4; i++) maze[k][4-i][0] = tmp1[i];

        for(int j=1; j<3; j++) tmp2[j] = maze[k][1][j];
        for(int i=1; i<3; i++) maze[k][1][i] = maze[k][i][3];
        for(int i=1; i<3; i++) maze[k][i][3] = maze[k][3][4-i]; 
        for(int i=1; i<3; i++) maze[k][3][4-i] = maze[k][4-i][1];
        for(int i=1; i<3; i++) maze[k][4-i][1] = tmp2[i];
    }
}

int bfs() {
    int x, y, z, r, c, k;
    int dist[5][5][5];
    memset(dist, 0, sizeof(dist));
    queue<pair<pair<int, int>, int>> Q;
    if(maze[brute[0]][0][0]==0 || maze[brute[4]][4][4]==0) return 1e9;
    Q.push({{0, 0}, 0});
    dist[brute[0]][0][0] = 1;

    while(!Q.empty()) {
        auto P = Q.front();
        x=P.first.first; y=P.first.second; z=P.second;
        Q.pop();
        for(int d=0; d<6; d++) {
            r=x+dx[d]; c=y+dy[d]; k=z+dz[d];
            if(r<0||c<0||k<0||r>=5||c>=5||k>=5||maze[brute[k]][r][c]==0) continue;
            if(dist[brute[k]][r][c]!=0) continue;
            if(k==4 && r==4 && c==4) {
                return dist[brute[z]][x][y];
            }
            dist[brute[k]][r][c] = dist[brute[z]][x][y] + 1;
            Q.push({{r, c}, k});

        }
    }
    return 1e9;
}


void dfs(int k) {
    if(k>=5) {
        ans = min(ans,bfs());
        return;
    }
    
    for(int d=0; d<4; d++) {
        rotateMaze(brute[k], d);
        dfs(k+1);
        rotateMaze(brute[k], 4-d);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int k=0; k<5; k++) for(int i=0; i<5; i++) for(int j=0; j<5; j++) cin >> maze[k][i][j];

    do {
        dfs(0);
    } while(next_permutation(brute, brute+5));
    
    if(ans>=9999) cout << -1;
    else cout << ans;
    return 0;
}