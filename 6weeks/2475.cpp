#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, total=0;
    for(int i=0; i<5; i++) {
        cin >> n;
        total += pow(n, 2);
    }
    cout << total%10;
    
    return 0;
}