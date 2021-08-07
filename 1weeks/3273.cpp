#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[100002];
int arr[2000002];
int main(void) {
    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        a[i] = num;
        arr[num] = i;
    }
    cin >> x;

    int ans=0;
    for(int i=0; i<n; i++) {
        if(x<a[i]) continue;
        if(arr[x-a[i]]>arr[a[i]]) ans++;
    }
    cout << ans;
    return 0;
}