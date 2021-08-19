#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N, L, R, cnt, ans;
int country[52][52];
bool visited[52][52];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

vector<pair<int, int>> V;

void organized() {
    int total=0;
    for(int i=0; i<V.size(); i++) total+=country[V[i].X][V[i].Y];
    total/=V.size();
    for(int i=0; i<V.size(); i++) country[V[i].X][V[i].Y] = total;
}

void bfs(int x, int y) {
    int r, c;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    V.push_back({x, y});
    visited[x][y] = true;
    while(!Q.empty()) {
        x=Q.front().X; y=Q.front().Y;
        Q.pop();

        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=N||c>=N||visited[r][c]) continue;
            int div = abs(country[r][c]-country[x][y]);
            if(div<L || div>R) continue;
            visited[r][c] = true;
            V.push_back({r, c});
            Q.push({r, c});
        }
    }
    if(V.size()>1) organized();
    V.clear();
}



int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> country[i][j];
    while(1) {
        memset(visited, false, sizeof(visited));
        int cnt=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(visited[i][j]) continue;
                bfs(i, j);
                cnt++;

            }
        }
        if(cnt>=N*N) break;
        ans++;
    }
    cout << ans;
    return 0;
}