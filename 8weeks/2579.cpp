#include <bits/stdc++.h>
using namespace std;
int N;
int stair[302];
pair<int, int> stairs[302];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> stair[i];

    if(N==1) {
        cout << stair[1];
        return 0;
    }
    stairs[1] ={stair[1], stair[1]};
    stairs[2].first = stairs[1].first + stair[2];
    stairs[2].second = stair[2];
    stairs[3].first = stairs[2].second + stair[3];
    stairs[3].second = stairs[1].first + stair[3];
    for(int i=4; i<=N; i++) {
        stairs[i].first = stairs[i-1].second+stair[i];
        stairs[i].second = max(stairs[i-2].first,stairs[i-2].second) + stair[i];
    }

    cout << max(stairs[N].first, stairs[N].second);
    
    return 0;
}