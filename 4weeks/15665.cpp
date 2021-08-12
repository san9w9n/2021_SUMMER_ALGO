#include <bits/stdc++.h>
using namespace std;
int N, M, idx=0;
int counting[10002];
int arr[9];
int visited[9];
vector<int> ans;

void btk(int k) {
    if(k==M) {
        for(int i=0; i<k; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<idx; i++) {
        ans.push_back(arr[i]);

        btk(k+1);
        ans.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        counting[num]++;
    }
    for(int i=1; i<=10000; i++) {
        if(counting[i]>0) {
            arr[idx]=i;
            idx++;
        }
    }
    btk(0);

    return 0;
}