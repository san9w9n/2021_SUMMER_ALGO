#include <bits/stdc++.h>
using namespace std;
int N, arr[1002];
int dp[1002];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];

    dp[1] = arr[1];
    dp[2] = max(2*arr[1], arr[2]);
    for(int i=3; i<=N; i++) {
        dp[i] = arr[i];
        for(int j=1; j<i; j++) dp[i] = max(dp[i], dp[j]+arr[i-j]);
    }
    cout << dp[N];
    
    return 0;
}