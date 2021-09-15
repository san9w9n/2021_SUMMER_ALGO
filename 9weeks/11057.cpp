#include <bits/stdc++.h>
using namespace std;
int N;
unsigned long long dp[1002][10];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<10; i++) dp[1][i] = 1;
    
    for(int i=1; i<N; i++) {
        for(int n=0; n<10; n++) {
            if(n==9) {
                dp[i+1][9]=dp[i][9]%10007 + dp[i+1][9]%10007;
                dp[i+1][9];
                continue;
            }
            for(int t=n; t<10; t++) {
                dp[i+1][t]=dp[i][n]%10007 + dp[i+1][t]%10007;
                dp[i+1][t];
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i<10; i++) ans+=dp[N][i];
    cout << ans%10007;
    return 0;
}