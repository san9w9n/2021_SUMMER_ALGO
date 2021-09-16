#include <bits/stdc++.h>
using namespace std;
long long dp[1000002];
int N;

void plusfibo() {
    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<=N; i++) dp[i] = dp[i-2]%1000000000 + dp[i-1]%1000000000;
    if(dp[N]==0) cout << 0 <<'\n' << 0;
    else cout << 1 << '\n' << dp[N]%1000000000;
}
void minusfibo() {
    dp[0] = 0; dp[1] = 1;
    N=-N;
    // F(-2) = F(0) - F(-1) =>  F(2) = F(0) - F(1)
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-2] - dp[i-1];
        if(dp[i]>=0) dp[i]%=1000000000;
        else dp[i] = -((-dp[i])%1000000000);
    }
    if(dp[N]==0) cout << 0 <<'\n' << 0;
    else if(dp[N]>0) cout << 1 << '\n' << dp[N]%1000000000;
    else {
        cout << -1 <<'\n' << (-dp[N])%1000000000;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    // F(n-2) = F(n) - F(n-1)
    cin >> N;
    int ans;
    if(N>=0) plusfibo();
    else minusfibo();

    return 0;
}