#include <bits/stdc++.h>
using namespace std;
priority_queue<int> P;
int N;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--) {
        int n;
        cin >> n;
        P.push(n);
    }

    while(!P.empty()) {
        cout << P.top() << '\n';
        P.pop();
    }

    return 0;
}