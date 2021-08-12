#include <bits/stdc++.h>
using namespace std;
int N, ans=0;
int board[16][16];
bool column[16], lcross[35], rcross[35];

void btk(int r) {
    if(r==N) {
        ans++;
        return;
    }
    for(int c=0; c<N; c++) {
        if(column[c] || lcross[r+c] || rcross[r-c+N-1]) continue;
        column[c] = lcross[r+c] = rcross[r-c+N-1] = true;
        btk(r+1);
        column[c] = lcross[r+c] = rcross[r-c+N-1] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    btk(0);
    cout << ans;
    return 0;
}