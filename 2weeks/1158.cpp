#include <bits/stdc++.h>
using namespace std;
int N, K;
queue<int> q;
int ans[5002];
void rotate() {
    q.push(q.front());
    q.pop();
}

int main(void) {
    cin >> N >> K;
    for(int i=1; i<=N; i++) q.push(i);
    int cnt=0;
    int index=0;
    while(!q.empty()) {
        if(cnt==K-1) {
            ans[index] = q.front();
            index++;
            q.pop();
            cnt=0;
            continue;
        }
        rotate();
        cnt++;
    }
    cout << "<";
    for(int i=0; i<N-1; i++) cout << ans[i] << ", ";
    cout << ans[N-1] << ">";
    return 0;
}