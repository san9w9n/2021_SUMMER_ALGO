#include <bits/stdc++.h>
using namespace std;
int N;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--) {
        string a, b;
        int A[27];
        fill(A, A+27, 0);
        cin >> a >> b;
        if(a.length()!=b.length()) {
            cout << "Impossible\n";
            continue;
        }
        int len = a.length();
        bool check = true;
        for(int i=0; i<len; i++) A[a[i]-'a']++;
        for(int i=0; i<len; i++) A[b[i]-'a']--;
        for(int i=0; i<len; i++) {
            if(A[a[i]-'a']!=0) {
                check = false;
                break;
            }
        }
        
        if(check) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    return 0;
}