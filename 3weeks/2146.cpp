#include <bits/stdc++.h>
using namespace std;
int N, island=2;
int field[102][102];
vector<pair<int, int>> edge[10002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int ans=1e9;

void dfs(int x, int y) {
    int r, c;
    for(int d=0; d<4; d++) {
        r=x+dx[d]; c=y+dy[d];
        if(r<0 || c<0 || r>=N || c>=N) continue;
        if(field[r][c]==0) {
            if(!edge[island].empty()) {
                if(edge[island].back().first!=x || edge[island].back().second!=y) {
                    edge[island].push_back({x, y});
                }
            }
            else edge[island].push_back({x, y});
            continue;
        }
        if(field[r][c]!=1) continue;
        field[r][c] = island;
        dfs(r, c);
    }
}

void bfs(int x, int y, int cnt) {
    queue<pair<int, int>> Q;
    int dist[102][102];
    int r, c;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            dist[i][j]=0;
    Q.push({x, y});
    dist[x][y] = 1;
    while(!Q.empty()) {
        x=Q.front().first; y=Q.front().second;
        Q.pop();
        if(field[x][y]!=0 && field[x][y]!=cnt) {
            if(ans>dist[x][y]) ans=dist[x][y];
            return;
        }
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0 || c<0 || r>=N || c>=N) continue;
            if(field[r][c]!=cnt) {
                if(dist[r][c]!=0 && dist[r][c]<=dist[x][y]+1) continue;
                dist[r][c] = dist[x][y] + 1;
                Q.push({r, c});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> field[i][j];
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(field[i][j]==1) {
                field[i][j] = island;
                dfs(i, j);
                island++;
            }
        }
    }

    for(int i=2; i<=island; i++) {
        for(int j=0; j<edge[i].size(); j++) {
            bfs(edge[i][j].first, edge[i][j].second, i);
        }
    }

    cout << ans-2;
    return 0;
}