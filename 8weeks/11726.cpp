#include <bits/stdc++.h>
using namespace std;
int n;
int square[1001];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    square[1] = 1;
    square[2] = 2;
    for(int i=3; i<=n; i++) square[i] = (square[i-2] + square[i-1])%10007;
    cout << square[n];

    return 0;
}