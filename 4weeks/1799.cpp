#include <bits/stdc++.h>
using namespace std;
int board[11][11], N;
int ans[2];
bool lcross[35];
bool rcross[35];

void btk(int r, int c, int tot, int bw) {
    if(ans[bw]<tot) ans[bw] = tot;
    if(c>=N) {
        r++;
        if(r>=N) return;
        if(bw==0) c=r%2;
        else c=1-r%2;
    }
    if(board[r][c]==1 && !lcross[r+c] && !rcross[r-c+N-1]) {
        lcross[r+c] = true; rcross[r-c+N-1] = true;
        btk(r, c+2, tot+1, bw);
        lcross[r+c] = false; rcross[r-c+N-1] = false;
    }
    btk(r, c+2, tot, bw);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cin >>board[i][j];
    }
    btk(0, 0, 0, 0);
    btk(0, 1, 0, 1);
    cout << ans[0]+ans[1];

    return 0;
}