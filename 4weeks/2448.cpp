#include <bits/stdc++.h>
using namespace std;
int N;
char board[10000][10000];

void printBoard() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N*2-1; j++) {
            if(board[i][j]=='*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}
void recursion(int r, int c, int K) {
    if(K==3) {
        board[r][c] = '*';
        board[r+1][c-1] = '*';
        board[r+1][c+1] = '*';
        board[r+2][c-2] = '*';
        board[r+2][c-1] = '*';
        board[r+2][c] = '*';
        board[r+2][c+1] = '*';
        board[r+2][c+2] = '*';
        return;
    }
    recursion(r, c, K/2);
    recursion(r+K/2, c-K/2, K/2);
    recursion(r+K/2, c+K/2, K/2);

}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    recursion(0, N-1, N);
    printBoard();

    return 0;
}