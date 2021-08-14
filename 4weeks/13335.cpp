#include <bits/stdc++.h>
#define T first
#define W second
using namespace std;
int n, len, maxW, nowW, ans;
int Left, Right;
pair<int, int> truck[1003];

void debug() {
    cout << "------------------\n";
    cout << "Left: " << Left << ", Right: " << Right << '\n';
    cout << ans << ": ";
    for(int i=0; i<n; i++) {
        cout << truck[i].T << ' ';
    }
    cout << '\n';
}

void gotime() {
    while(1) {
        int Ltmp=Left, Rtmp=Right;
        for(int i=Left; i<Right; i++) {
            truck[i].T++;
            if(truck[i].T>len) {
                nowW-=truck[i].W;
                Ltmp++;
            }
        }
        for(int i=Right; i<n; i++) {
            if(maxW-nowW>=truck[i].W) {
                nowW+=truck[i].W;
                truck[i].T = 1;
                Rtmp++;
                break;
            } else break;
        }
        Left=Ltmp; Right=Rtmp;
        ans++;
        if(Left>=n) break;
    }
    cout << ans;
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> len >> maxW;
    for(int i=0; i<n; i++) cin >> truck[i].W;
    gotime();
    return 0;
}