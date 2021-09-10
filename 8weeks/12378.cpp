#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> lis;

void debug() {
    for(int i=0; i<lis.size(); i++) cout << lis[i] << ' ';
    cout << '\n';
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        if(lis.empty()) lis.push_back(n);
        else {
            if(lis[lis.size()-1]<n) lis.push_back(n);
            else *(lower_bound(lis.begin(), lis.end(), n)) = n;
        }
    }
    cout << lis.size();

    return 0;
}