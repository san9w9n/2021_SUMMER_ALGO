#include <bits/stdc++.h>
using namespace std;
int T;

int main(void) {
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        stack<char> S;
        int l = str.length();
        if(l%2==1) {
            cout << "NO\n";
            continue;
        } else if(l>=2) {
            if(!str[0]=='(' || !str[l-1]==')') {
                cout << "NO\n";
                continue;
            }
        }

        bool check = true;
        for(char c : str) {
            if(c=='(') S.push('(');
            else if(c==')') {
                if(S.empty() || S.top()!='(') {
                    cout << "NO\n";
                    check = false;
                    break;
                } else S.pop();
            }
        }
        if(!check) continue;
        if(!S.empty()) {
            cout << "NO\n";
            continue;
        } else cout << "YES\n";
    }

    return 0;
}