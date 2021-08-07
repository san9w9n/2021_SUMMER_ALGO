#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100002];
int state[100002];

void run(int x) {
    int cur = x;
    while(true) {
        state[cur] = x;
        cur = arr[cur];
        if(state[cur] == x) {
            while(state[cur] != -1) {
                state[cur] = -1;
                cur = arr[cur];
            }
            return;
        } else if(state[cur] != 0) return;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        fill(state+1, state+1+N, 0);
        for(int i=1; i<=N; i++) cin >> arr[i];

        for(int i=1; i<=N; i++) {
            if(state[i]==0) run(i);
        }
        int cnt = 0;
        for(int i=1; i<=N; i++) {
            if(state[i] != -1) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}