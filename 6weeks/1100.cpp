#include <bits/stdc++.h>
using namespace std;
int ans;


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<8; i++) {
        string line;
        cin >> line;
        for(int j=0; j<8; j++) {
            if(i%2==0) {
                if(j%2==0 && line[j]=='F') ans++;
            } else {
                if(j%2==1 && line[j]=='F') ans++;
            }
        }
    }
    cout << ans;

    return 0;
}