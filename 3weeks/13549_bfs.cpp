#include <bits/stdc++.h>
using namespace std;
int N, K;
int dist[250000];
bool visited[250000];

int bfs() {
    queue<int> Q;
    int x, r;
    Q.push(N);
    dist[N] = 0;
    visited[N] = true;
    while(!Q.empty()) {
        x = Q.front(); Q.pop();
        if(x==K) return dist[K];
        for(int d=-1; d<2; d++) {
            if(d==0) r=x*2;
            else r=x+d;
            if(r<0 || r>100000) continue;

            if(d==0) {
                if(dist[r]!=-1 && dist[r]<=dist[x]) continue;
                dist[r]=dist[x];
            } else {
                if(dist[r]!=-1 && dist[r]<=dist[x]+1) continue;
                dist[r]=dist[x]+1;
            }
            Q.push(r);
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(dist, dist+250000, -1);
    fill(visited, visited+250000, false);
    cin >> N >> K;
    cout << bfs();
    

    return 0;
}