#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N, M, cnt=2, ans=1e9;
int MAP[11][11];
int dist[7][7];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
vector<pair<int,int>> graph;
int brute[10];
vector<pair<int,int>> selected;

void go(int x, int y, int d) {
    int r=x, c=y;
    int cur = MAP[x][y];
    int di = 0;
    while(1) {
        r+=dx[d]; c+=dy[d];
        if(r<0||r>=N||c<0||c>=M||MAP[r][c]==cur) break;
        if(MAP[r][c]!=0) {
            if(di<=1) break;
            dist[cur-2][MAP[r][c]-2] = min(di,dist[cur-2][MAP[r][c]-2]);
            break;
        }
        di++;
    }
}

bool dfs() {
    vector<int> G[10];
    queue<int> Q;
    bool check[10];
    fill(check, check+10, false);

    for(int i=0; i<selected.size(); i++) {
        G[selected[i].X].push_back(selected[i].Y);
        G[selected[i].Y].push_back(selected[i].X);
    }

    Q.push(0);
    check[0] = true;
    int n, c=1;
    while(!Q.empty()) {
        n=Q.front(); Q.pop();
        for(int i=0; i<G[n].size(); i++) {
            if(check[G[n][i]]) continue;
            check[G[n][i]] = true;
            Q.push(G[n][i]);
            c++;
        }
    }
    if(c==cnt-2) return true;
    return false;
}

void bfs(int x, int y) {
    int r, c;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    MAP[x][y] = cnt;

    while(!Q.empty()) {
        x=Q.front().X; y=Q.front().Y;
        Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||r>=N||c<0||c>=M) continue;
            if(MAP[r][c]==0) {
                go(x, y, d);
            }
            if(MAP[r][c]==1) {
                MAP[r][c] = cnt;
                Q.push({r, c});
            }
        }
    }

    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<7; i++) for(int j=0; j<7; j++) dist[i][j] = 1e9;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> MAP[i][j];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(MAP[i][j]==1) {
                MAP[i][j]=cnt;
                bfs(i, j);
                cnt++;
            }
        }
    }
    for(int i=cnt-3; i<10; i++) brute[i] = 1;

    for(int i=0; i<cnt-2; i++) {
        for(int j=0; j<cnt-2; j++) {
            if(dist[i][j]==1e9) continue;
            graph.push_back({i, j});
        }
    }

    do {
        int total = 0;
        for(int i=0; i<graph.size(); i++) {
            if(brute[i]==0) { 
                selected.push_back(graph[i]);
                total+=dist[graph[i].X][graph[i].Y];
            }
        }
        if(dfs()) ans = min(ans, total);
        selected.clear();
    } while(next_permutation(brute, brute+graph.size()));

    if(ans==1e9) cout << -1;
    else cout << ans;

    return 0;
}