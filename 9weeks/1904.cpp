#include <bits/stdc++.h>
using namespace std;
int N;
unsigned int dp[1000002];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    dp[1] = 1; dp[2] = 2;
    // 1 : 1
    // 2 : 11 00
    // 3: 100 111 001
    // 4: 1100 0000 1001 1111 0011
    for(int i=3; i<=N; i++) dp[i] = dp[i-2]%15746 + dp[i-1]%15746;
    cout << dp[N] % 15746;
    return 0;
}