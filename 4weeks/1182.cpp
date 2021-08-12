#include <bits/stdc++.h>
using namespace std;
int N, S, ans=0;
int arr[22];
void btk(int k, int total) {
    if(k>=N) {
        if(total==S) ans++;
        return;
    }
    btk(k+1, total+arr[k]);
    btk(k+1, total);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    btk(0, 0);
    if(S== 0) ans--;
    cout << ans;
    return 0;
}