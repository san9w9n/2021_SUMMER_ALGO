#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int arr[302][302];
queue<pair<int, int>> Q;
int L, x, y, tx, ty, ans=0;

int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};


void init() {
    while(!Q.empty()) Q.pop();
    for(int i=0; i<302; i++) {
        for(int j=0; j<302; j++) arr[i][j] = 0;
    }
}

void bfs() {
    int nx, ny;
    Q.push({x, y});
    arr[x][y] = 1;
    while(!Q.empty()) {
        nx = Q.front().X; ny = Q.front().Y;
        if(nx==tx && ny==ty) break;
        Q.pop();
        for(int i=0; i<8; i++) {
            int r, c;
            r = nx + dx[i]; c = ny + dy[i];
            if(r<0 || c<0 || r>=L || c>=L) continue;
            if(arr[r][c]!=0 && arr[r][c]<=arr[nx][ny]+1) continue;
            arr[r][c] = arr[nx][ny] + 1;
            Q.push({r, c});
        }
    }
    cout << arr[tx][ty]-1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        init();
        cin >> L;
        cin >> x >> y;
        cin >> tx >> ty;
        bfs();
    }
    return 0;
}