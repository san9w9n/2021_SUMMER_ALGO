#include <bits/stdc++.h>
using namespace std;
string tv[65];

char check(int lx, int ly, int k) {
    char cmp = tv[lx][ly];
    for(int i=lx; i<lx+k; i++) {
        for(int j=ly; j<ly+k; j++) {
            if(cmp!=tv[i][j]) return ' ';
        }
    }
    return cmp;
}

void recursion(int x,int y, int k) {
    char flag = check(x, y, k);
    if(k==1) {
        cout << tv[x][y];
        return;
    }
    if(flag!=' ') {
        cout << flag;
        return;
    }
    cout << '(';
    recursion(x, y, k/2);
    recursion(x, y+k/2, k/2);
    recursion(x+k/2, y, k/2);
    recursion(x+k/2, y+k/2, k/2);
    cout << ')';
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> tv[i];
    recursion(0,0,N);

    return 0;
}