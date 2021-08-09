#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N, M;
vector<pair<int, int>> swit[102][102];
bool room[102][102];
bool visited[102][102];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

void initarr() {
    for(int i=0; i<102; i++) {
        for(int j=0; j<102; j++) {
            visited[i][j] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int ans = 0;
    for(int i=0; i<M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        swit[x-1][y-1].push_back({a-1, b-1});
    }

    
    while(1) {
        int x, y, r, c;
        initarr();
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        room[0][0] = true;
        visited[0][0] = true;
        bool check = false;
        while(!Q.empty()) {
            x = Q.front().X; y = Q.front().Y;
            Q.pop();
            if(!swit[x][y].empty()) {
                for(int i=0; i<swit[x][y].size(); i++) {
                    auto cur = swit[x][y][i];
                    room[cur.X][cur.Y] = true;
                }
                swit[x][y].clear();
                check = true;
            }
            for(int d=0; d<4; d++) {
                r=x+dx[d]; c=y+dy[d];
                if(r<0||c<0||r>=N||c>=N) continue;
                if(visited[r][c] || !room[r][c]) continue;
                Q.push({r, c});
                visited[r][c] = true;
            }
        }
        if(!check) break;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(room[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}