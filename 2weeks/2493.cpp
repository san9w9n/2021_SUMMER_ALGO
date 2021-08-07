#include <bits/stdc++.h>
#define no first
#define h second

using namespace std;
int N;
stack<pair<int, int>> tower;
stack<pair<int, int>> tmp;
int ans[500002];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int n;
    for(int i=1; i<=N; i++) {
        cin >> n;
        tower.push({i, n});
    }
    tmp.push(tower.top());
    tower.pop();
    while(!tower.empty()) {
        if(!tmp.empty()) {
            if(tmp.top().h<=tower.top().h) {
                ans[tmp.top().no-1] = tower.top().no;
                tmp.pop();
                continue;
            }
        }
        tmp.push(tower.top());
        tower.pop();
    }
    while(!tmp.empty()) {
        ans[tmp.top().no-1] = 0;
        tmp.pop();
    }
    for(int i=0; i<N; i++) cout << ans[i] << " ";
    return 0;
}