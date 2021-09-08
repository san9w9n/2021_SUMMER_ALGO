#include <bits/stdc++.h>
using namespace std;
int dist[13];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    dist[1] = 1;
    dist[2] = 2;
    dist[3] = 4;

    for(int i=4; i<11; i++) dist[i] = dist[i-3] + dist[i-2] + dist[i-1];

    int N;
    cin >> N;
    while(N--) {
        int n;
        cin >> n;
        cout << dist[n] << '\n';
    }
    
    return 0;
}