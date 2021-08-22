#include <bits/stdc++.h>
using namespace std;
int M, N;
string room[22];
vector<pair<int, int>> dust; 
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int bfs(int x, int y, int tx, int ty, int cnt, int idx) {
    int r, c;
    int dist[22][22];
    memset(dist, 0, sizeof(dist));
    queue<pair<int,int>> Q;
    Q.push({x, y});
    dist[x][y] = 1;

    while(!Q.empty()) {
        x=Q.front().first; y=Q.front().second; Q.pop();

        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=N||c>=M||room[r][c]=='x'||dist[r][c]!=0) continue;
            if(r==tx && c==ty) {
                if(idx==dust.size()-1) return cnt+dist[x][y];
                else return bfs(tx, ty, dust[idx+1].first, dust[idx+1].second, cnt+dist[x][y], idx+1);
            }
            dist[r][c] = dist[x][y] + 1;
            Q.push({r, c});
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    while(1) {
        int ans=1e9;
        int x, y;
        cin >> M >> N;
        if(M==0 && N==0) break;
        for(int i=0; i<N; i++) {
            cin >> room[i];
            for(int j=0; j<M; j++) {
                if(room[i][j]=='o') {
                    x=i; y=j;
                } else if(room[i][j]=='*') {
                    dust.push_back({i, j});
                }
            }
        }

        do {
            int n = bfs(x, y, dust[0].first, dust[0].second, 0, 0);
            if(n==-1) {
                ans=-1;
                break;
            }
            if(ans>n) ans=n;
        } while(next_permutation(dust.begin(), dust.end()));
        cout << ans << '\n';
        dust.clear();
    }
    
    return 0;
}