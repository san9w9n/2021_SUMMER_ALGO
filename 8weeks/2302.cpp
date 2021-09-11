#include <bits/stdc++.h>
using namespace std;
int N, M;
bool vip[45];
vector<int> V;
int dp[45];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int n;
        cin >> n;
        vip[n] = true;
    }
    dp[1] = 1; dp[2] = 2;
    for(int i=3; i<=N; i++) dp[i] = dp[i-2] + dp[i-1];

    int start = 1, last = 1;
    while(1) {
        if(vip[last]) {
            if(last-start>0) V.push_back(last-start);
            start = last+1;
            last++;
        } else last++;
        if(last>N) {
            if(last-start>0) V.push_back(last-start);
            break;
        }
    }

    int ans = 1;
    for(int i=0; i<V.size(); i++) ans*=dp[V[i]];
    cout << ans;
    
    return 0;
}