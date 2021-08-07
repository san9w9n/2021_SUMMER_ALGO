#include <bits/stdc++.h>
using namespace std;
int arr[2000002];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, t;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> t;
        arr[t + 1000000]++;
    }
    for(int i=0; i<=2000000; i++) {
        while(arr[i]--) cout << i-1000000 << "\n";
    }
    
    return 0;
}