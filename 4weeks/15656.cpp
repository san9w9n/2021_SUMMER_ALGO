#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[9];
vector<int> ans;

void btk(int k) {
    if(k==M) {
        for(int i=0; i<k; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<N; i++) {
        ans.push_back(arr[i]);
        btk(k+1);
        ans.pop_back();
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    btk(0);

    return 0;
}