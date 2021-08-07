#include <bits/stdc++.h>
#define W first
#define V second
using namespace std;
int N, K;
int dist[250000];
priority_queue<pair<int, int>> pq;
int dx[2] = {1,-1};

void dijkstra() {
    int w, v;
    pq.push({0, N});
    dist[N] = 0;

    while(!pq.empty()) {
        w = (-1)*pq.top().W; v = pq.top().V;
        pq.pop();
        if(w>dist[v]) continue;
        for(int d=0; d<3; d++) {
            int cost, next;
            if(d==2) {
                next=2*v;
                cost=w;
            } else {
                next=v+dx[d];
                cost=1+w;
            }
            if(next<0 || next>100000) continue;
            if(dist[next]<=cost) continue;
            dist[next]=cost;
            pq.push({-cost, next});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(dist, dist+250000, 1e9);
    cin >> N >> K;
    dijkstra();
    cout << dist[K];
    return 0;
}