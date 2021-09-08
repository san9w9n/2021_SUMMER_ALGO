#include <bits/stdc++.h>
using namespace std;
int N;
typedef struct {
    int R;
    int G;
    int B;
} Home;
Home home[1001];
int dp[1001][3];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> home[i].R >> home[i].G >> home[i].B;
    dp[0][0] = home[0].R; dp[0][1] = home[0].G; dp[0][2] = home[0].B;

    for(int i=1; i<N; i++) {
        dp[i][0] = home[i].R + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = home[i].G + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = home[i].B + min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});

    return 0;
}