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
        for(int j=1; j<=i; j++) {
            visited[j] = true;
        }
        ans.push_back(i);
        btk(k+1);
        ans.pop_back();
        for(int j=1; j<=i; j++) {
            visited[j] = false;
        }
    }

}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    btk(0);
    return 0;
}