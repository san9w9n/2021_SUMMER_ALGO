#include <bits/stdc++.h>
using namespace std;
int N, stick[2][200000];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0; i<2; i++) for(int j=0; j<N; j++) cin >> stick[i][j];
        if(N==1) {
            cout << max(stick[0][N-1], stick[1][N-1]) << '\n';
            continue;
        }
        stick[0][1]+=stick[1][0]; stick[1][1]+=stick[0][0];
        for(int j=2; j<N; j++) {
            for(int i=0; i<2; i++) {
                stick[i][j] += max(stick[1-i][j-1], max(stick[0][j-2], stick[1][j-2]));
            }
        }
        cout << max(stick[0][N-1], stick[1][N-1]) << '\n';
    }

    return 0;
}