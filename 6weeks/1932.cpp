#include <bits/stdc++.h>
using namespace std;
int N, ans;
int board[502][502];


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int cnt=0;
    for(int i=0; i<N; i++) {
        cnt++;
        for(int j=0; j<cnt; j++) cin >> board[i][j];
    }
    
    cnt=1;
    for(int i=1; i<N; i++) {
        cnt++;
        for(int j=0; j<cnt; j++) {
            if(j==0) board[i][j] += board[i-1][j];
            else if(j==cnt-1) board[i][j] += board[i-1][j-1];
            else {
                int sum = max(board[i-1][j-1], board[i-1][j]);
                board[i][j]+=sum;
            }
        }
    }
    for(int i=0; i<N; i++) ans = max(ans,board[N-1][i]);
    
    cout << ans;

    return 0;
}