#include <bits/stdc++.h>
using namespace std;
int board[2190][2190];
int ans[3];

int check(int x, int y, int k) {
    int cmp = board[x][y];
    for(int i=x; i<x+k; i++) {
        for(int j=y; j<y+k; j++) {
            if(cmp!=board[i][j]) return -2;
        }
    }
    return cmp;
}

void recursion(int x, int y, int k) {
    if(k==1) {
        ans[board[x][y]+1]++;
        return;
    }
    int flag = check(x, y, k);
    if(flag!=-2) {
        ans[flag+1]++;
        return;
    }
    k/=3;
    recursion(x, y, k);
    recursion(x, y+k, k);
    recursion(x, y+2*k, k);
    recursion(x+k, y, k);
    recursion(x+k, y+k, k);
    recursion(x+k, y+2*k, k);
    recursion(x+2*k, y, k);
    recursion(x+2*k, y+k, k);
    recursion(x+2*k, y+2*k, k);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    recursion(0, 0, N);
    for(int i=0; i<3; i++) cout << ans[i] << '\n';
    return 0;
}