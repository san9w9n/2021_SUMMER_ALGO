#include <bits/stdc++.h>
using namespace std;
int N;
int dp[101][10];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int j=1; j<10; j++) dp[1][j] = 1;

    for(int i=1; i<N; i++) {
        for(int j=0; j<10; j++) {
            if(j==0) dp[i+1][1] += dp[i][0];
            else if(j==9) dp[i+1][8] += dp[i][9];
            else {
                dp[i+1][j-1] += dp[i][j]%1000000000;
                dp[i+1][j+1] += dp[i][j]%1000000000;
            }
        }
    }
    
    long long total = 0;
    for(int j=0; j<10; j++) total+=dp[N][j];
    cout << total%1000000000;

    return 0;
}