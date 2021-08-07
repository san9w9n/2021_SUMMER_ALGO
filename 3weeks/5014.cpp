#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;
int dist[1000005];

int bfs() {
    int r, x;
    queue<int> Q;
    Q.push(S);
    dist[S] = 1;
    while(!Q.empty()) {
        x = Q.front(); Q.pop();
        if(x==G) return dist[G];
        for(int i=0; i<2; i++) {
            if(i==0) r=x+U;
            else r=x-D;
            if(r<=0 || r>F) continue;
            if(dist[r]!=0 && dist[r]<=dist[x]+1) continue;
            dist[r]=dist[x]+1;
            Q.push(r);
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    fill(dist, dist+F+2, 0);

    int ans = bfs();
    if(ans==-1) cout << "use the stairs";
    else cout << ans-1;


    return 0;
}