#include <bits/stdc++.h>
using namespace std;
int L, C;
char arr[16];
bool visited[16];
vector<char> ans;
bool check() {
    char moum[5] = {'a', 'e', 'i', 'o', 'u'};
    int mo = 0, ja = 0;
    for(int i=0; i<L; i++) {
        bool flag = false;
        for(int j=0; j<5; j++) {
            if(ans[i]==moum[j]) {
                flag = true;
                break;
            }
        }
        if(flag) mo++;
        else ja++;
    }
    return mo>0 && ja>1;
}
void btk(int k) {
    if(k==L) {
        if(!check()) return;
        for(int i=0; i<k; i++) cout << ans[i];
        cout <<'\n';
        return;
    }
    for(int i=0; i<C; i++) {
        if(visited[i]) continue;
        for(int j=0; j<=i; j++) visited[j] = true;
        ans.push_back(arr[i]);
        btk(k+1);
        for(int j=0; j<=i; j++) visited[j] = false;
        ans.pop_back();
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> L >> C;
    for(int i=0; i<C; i++) cin >> arr[i];
    sort(arr, arr+C);
    btk(0);
    return 0;
}