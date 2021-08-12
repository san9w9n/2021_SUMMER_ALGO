#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ans;
bool visited[9];

void btk(int k) {
    if(k==M) {
        for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++) {
        ans.push_back(i);
        btk(k+1);
        ans.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    btk(0);
    return 0;
}