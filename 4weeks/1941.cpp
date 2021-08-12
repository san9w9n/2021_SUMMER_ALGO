#include <bits/stdc++.h>
using namespace std;
int k, arr[14];
bool visited[14];
vector<int> ans;

void btk(int cnt) {
    if(cnt==6) {
        for(int i=0; i<6; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<k; i++) {
        if(visited[i]) continue;
        for(int j=0; j<=i; j++) visited[j] = true;
        ans.push_back(arr[i]);
        btk(cnt+1);
        ans.pop_back();
        for(int j=0; j<=i; j++) visited[j] = false;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(1) {
        cin >> k;
        if(k==0) break;
        for(int i=0; i<k; i++) cin >> arr[i];
        sort(arr, arr+k);
        btk(0);
        ans.clear();
        cout << '\n';
    }
    return 0;
}