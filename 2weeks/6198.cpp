#include <bits/stdc++.h>
using namespace std;
int N;
int arr[80002];
vector<int> B;
vector<int> tmp;

int main(void) {
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=N-1; i>=0; i--) B.push_back(arr[i]);

    long long ans = 0;
    tmp.push_back(B.back()); 
    B.pop_back();
    while(!B.empty()) {
        if(!tmp.empty()) {
            if(tmp.back()>B.back()) {
                ans+=tmp.size();
                tmp.push_back(B.back()); 
                B.pop_back();
            } else {
                tmp.pop_back();
            }
        } else {
            tmp.push_back(B.back()); 
            B.pop_back();
        }
    }

    cout << ans;

    return 0;
}