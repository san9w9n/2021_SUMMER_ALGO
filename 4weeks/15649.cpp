#include <bits/stdc++.h>
using namespace std;
int N, M;
bool visited[9];
vector<int> ans;
void btk(int k) {
    if(k==M) {
        for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        ans.push_back(i);
        btk(k+1);
        visited[i] = false;
        ans.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    btk(0);
    return 0;
}