#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int M, N, ans=1e9;
string room[22];
vector<pair<pair<int, int>, int>> dust;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int graph[11][11];
int visited[11];
bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
    return p1.Y < p2.Y;
}
void dfs(int cur, int dist, int cnt) {
    
    if(dist > ans) return;
    
    if(cnt == dust.size()) {
        if(ans > dist) ans = dist;
        return;
    }
    
    for(int next=0; next<dust.size(); next++) {
        if(cur==next || graph[cur][next]==1e9 || visited[next]) continue;
        visited[next] = true;
        dfs(next, dist + graph[cur][next], cnt+1);
        visited[next] = false;
    }
}

int bfs(int x, int y, int tx, int ty) {
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
            if(r==tx && c==ty) return dist[x][y];
            dist[r][c] = dist[x][y] + 1;
            Q.push({r, c});
        }
    }
    return 1e9;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    while(1) {
        ans=1e9;
        int x, y;
        cin >> M >> N;
        if(M==0 && N==0) break;
        for(int i=0; i<N; i++) {
            cin >> room[i];
            for(int j=0; j<M; j++) {
                if(room[i][j]=='o') {
                    x=i; y=j;
                } else if(room[i][j]=='*') {
                    dust.push_back({{i, j},0});
                }
            }
        }
        int st = dust.size();
        for(int i=0; i<dust.size(); i++) {
            dust[i].Y = bfs(x, y, dust[i].X.X, dust[i].X.Y);
            graph[st][i] = dust[i].Y; graph[i][st] = dust[i].Y;
        }
        sort(dust.begin(), dust.end(), cmp);
        if(dust[0].Y==1e9) {
            cout << -1 << '\n';
            continue;
        }
        
        for(int i=0; i<st; i++) {
            for(int j=i+1; j<st; j++) {
                int dist = bfs(dust[i].X.X, dust[i].X.Y, dust[j].X.X, dust[j].X.Y);
                graph[i][j] = graph[j][i] = dist;
            }
        }
        
        //debug
        // for(int i=0; i<dust.size(); i++) {
        //     for(int j=0; j<dust.size(); j++) {
        //         if(graph[i][j]==1e9) cout << "IN  ";
        //         else cout << graph[i][j] << "  ";
        //     }
        //     cout << '\n';
        // }

        
        for(int i=0; i<dust.size(); i++) {
            if(dust[i].Y == 1e9) continue;
            memset(visited, 0, sizeof(visited));
            visited[i] = true;
            dfs(i, dust[i].Y, 1);
            visited[i] = false;
        }

        if(ans==1e9) cout << -1 << '\n';
        else cout << ans << '\n';

        dust.clear();
        ans = 1e9;
    }
    
    return 0;
}