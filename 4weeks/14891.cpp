#include <bits/stdc++.h>
using namespace std;
int eles[4][8], K;
void debug() {
    for(int i=0; i<4; i++) {
        cout << i << ": ";
        for(int j=0; j<8; j++) {
            cout << eles[i][j];
        }
        cout << '\n';
    }
}

void rotateONE(int n, int d) {
    if(d==-1) {
        int tmp = eles[n][0];
        for(int i=0; i<7; i++) eles[n][i]=eles[n][i+1];
        eles[n][7] = tmp;
    } else {
        int tmp = eles[n][7];
        for(int i=7; i>0; i--) eles[n][i]=eles[n][i-1];
        eles[n][0] = tmp;
    }
}

void rotateALL(int n, int d) {
    int m[4][2];
    for(int i=0; i<4; i++) {
        m[i][0] = eles[i][6];
        m[i][1] = eles[i][2];
    }
    rotateONE(n, d);
    int tmpd = d;
    for(int i=n+1; i<4; i++) {
        if(m[i][0]!=m[i-1][1]) {
            rotateONE(i, 0-d);
            d=0-d;
        } 
        else break;
    }
    d = tmpd;
    for(int i=n-1; i>=0; i--) {
        if(m[i][1]!=m[i+1][0]) {
            rotateONE(i, -d);
            d=-d;
        }
        else break;
    }
    // debug();
}



int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<4; i++) {
        string line;
        cin >> line;
        for(int j=0; j<8; j++) eles[i][j] = line[j]-'0';
    }
    cin >> K;
    for(int i=0; i<K; i++) {
        int n, d;
        cin >> n >> d;
        rotateALL(n-1, d);
    }
    int ans = 0;
    int score[4] = {1, 2, 4, 8};
    for(int i=0; i<4; i++) {
        if(eles[i][0]==1) ans+=score[i];
    }
    cout << ans;
    return 0;
}