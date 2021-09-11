#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> arr[17];
int dp[17];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i].first >> arr[i].second;
        if(i+arr[i].first>N+1) {
            arr[i].first=0; arr[i].second=0;
        }
        dp[i] = arr[i].second;
    }
    for(int i=1; i<=N; i++) {
        if(arr[i].first==0) continue;
        int r = i+arr[i].first;
        for(int j=r; j<=N; j++) dp[j] = max(dp[j], dp[i]+arr[j].second);
    }

    int ans = 0;
    for(int i=1; i<=N+1; i++) ans = max(ans, dp[i]);
    cout << ans;
    

    return 0;
}