#include <bits/stdc++.h>
using namespace std;
int N, M;
deque<int> D;
int ans=0;

void L(int index) {
    while(index--) {
        D.push_back(D.front());
        D.pop_front();
        ans++;
    }
    D.pop_front();
}

void R(int index) {
    while(index--) {
        D.push_front(D.back());
        D.pop_back();
        ans++;
    }
    D.pop_back();
}

void find(int k) {
    int s = D.size();
    for(int i=0; i<s; i++) {
        if(D[i]==k) {
            if(i<=s/2) L(i);
            else {
                R(s-1-i);
                ans+=1;
            }
            break;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) D.push_back(i);
    while(M--) {
        int n;
        cin >> n;
        find(n);
    }
    cout << ans;
    return 0;
}