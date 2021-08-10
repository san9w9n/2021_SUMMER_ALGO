#include <bits/stdc++.h>
using namespace std;
int N;
char board[2190][2190];

void recursion(int lx, int ly, int K) {
    if(K==1) {
        board[lx][ly]='*';
        return;
    }

    recursion(lx+0, ly+0, K/3);
    recursion(lx+0, ly+K/3, K/3);
    recursion(lx+0, ly+2*K/3, K/3);

    recursion(lx+K/3, ly+0, K/3);
    recursion(lx+K/3, ly+2*K/3, K/3);

    recursion(lx+2*K/3, ly+0, K/3);
    recursion(lx+2*K/3, ly+K/3, K/3);
    recursion(lx+2*K/3, ly+2*K/3, K/3);
}

void printBoard() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    memset(board, ' ', sizeof(board));
    recursion(0,0,N);
    
    printBoard();

    return 0;
}