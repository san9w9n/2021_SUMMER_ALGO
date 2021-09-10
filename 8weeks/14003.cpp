#include <bits/stdc++.h>
using namespace std;
int N;
pair<int,int> arr[1000002];
vector<int> lis;
vector<int> ans;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        if(lis.empty()) {
            lis.push_back(n);
            arr[i].first = 0;
            arr[i].second = n;
        } else {
            if(lis[lis.size()-1]<n) {
                lis.push_back(n);
                arr[i].first = lis.size()-1;
                arr[i].second = n;
            } else {
                vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), n);
                (*it) = n;
                arr[i].first = distance(lis.begin(), it);
                arr[i].second = n;

            }
        }
    }
    int len = lis.size()-1;
    for(int i=N-1; i>=0; i--) {
        if(arr[i].first==len) {
            ans.push_back(arr[i].second);
            len--;
        }
    }

    cout << lis.size() << '\n';
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << ' ';

    return 0;
}