#include <bits/stdc++.h>
using namespace std;
int N, K;
int dx[3] = {-1,1,2};

int main() {
    cin >> N >> K;
    int* dist = new int[2*(K+1)]();
    fill(dist, dist+ 2*K+1, -1);
    queue<int> Q;
    if(K<=N) {
        cout << N-K;
        return 0;
    }
    Q.push(N);
    dist[N] = 0;
    int move, nx;
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        for(int i=0; i<3; i++) {
            move = dx[i];
            if(i==2) move = pos;
            nx = pos + move;
            if(nx<0 || nx>=2*K+1) continue;
            if(dist[nx]!=-1 && dist[nx] <= dist[pos] + 1) continue;
            if(nx==K) {
                cout << dist[pos] + 1;
                return 0;
            }
            dist[nx] = dist[pos] + 1;
            Q.push(nx);
        }
    }
}