#include <bits/stdc++.h>
using namespace std;
int board[11][11], N, M;
int ans=0;
bool cross[35];

void btk(int k, int tot) {
    if(k==M) {
        if(ans<tot) ans=tot;
        return;
    }
    for(int r=0; r<N; r++) {
        int c = abs(r-k+N-1);
        if(board[r][c]==0) continue;
        if(cross[r+c]) continue;
        board[r][c] = 0;
        cross[r+c] = true;
        btk(k+1, tot+1);
        board[r][c] = 1;
        cross[r+c] = false;
    }
    btk(k+1, tot);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    M = N+N-1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cin >>board[i][j];
    }
    btk(0, 0);
    cout << ans;

    return 0;
}