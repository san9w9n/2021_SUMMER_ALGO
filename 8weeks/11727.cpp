#include <bits/stdc++.h>
using namespace std;
int N;
int tile[1002];
// 1 / 11, 2, 4 / 12, 14, 111, 21, 41
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    tile[1] = 1; tile[2] = 3;
    for(int i=3; i<=N; i++) tile[i] = ((tile[i-2])*2 + tile[i-1])%10007;
    cout << tile[N];
    return 0;
}