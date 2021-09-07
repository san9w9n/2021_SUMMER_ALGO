#include <bits/stdc++.h>
using namespace std;
int N, C;
typedef struct {
    int num;
    int idx;
    int cnt;
} Password;
vector<Password> pass;

bool cmp(Password &a, Password &b) {
    if(a.cnt>b.cnt) return true;
    if(a.cnt==b.cnt) if(a.idx<b.idx) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    for(int t=0; t<N; t++) {
        int n;
        bool flag = false;
        cin >> n;
        for(int i=0; i<pass.size(); i++) {
            if(pass[i].num==n) {
                pass[i].cnt++;
                flag = true;
                break;
            }
        }
        if(!flag) pass.push_back({n, t, 1});
    }
    sort(pass.begin(), pass.end(), cmp);
    for(int i=0; i<pass.size(); i++) {
        for(int j=0; j<pass[i].cnt; j++) cout << pass[i].num <<' ';
    }

    return 0;
}