#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N, K;
bool visited[500002][2];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    queue<pair<int, int>> Q;
    Q.push({N, 0});
    visited[N][0] = true;
    int cnt=0;
    while(1) {
        int x, time, loop = Q.size();
        K+=cnt;
        if(K>500000) {
            cnt=-1;
            break;
        }
        while(loop--) {
            x = Q.front().X; time = Q.front().Y;
            Q.pop();
            if(x==K || visited[K][cnt%2]) goto answer;
            for(int cur : {x-1, x+1, 2*x}) {
                if(cur<0 || cur>500000) continue;
                if(visited[cur][(time+1)%2]) continue;
                Q.push({cur, time+1});
                visited[cur][(time+1)%2] = true;
            }
        }
        cnt++;
    }
    answer:
        cout << cnt;

    return 0;
}