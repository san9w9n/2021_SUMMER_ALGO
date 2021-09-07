#include <bits/stdc++.h>
using namespace std;
string S;
vector<string> dic;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    dic.push_back(S);
    for(int i=1; i<S.size(); i++) {
        vector<char> V;
        for(int j=i; j<S.size(); j++) V.push_back(S[j]);
        string s(V.begin(), V.end());
        dic.push_back(s);
    }

    sort(dic.begin(), dic.end());
    for(int i=0; i<dic.size(); i++) cout << dic[i] << '\n';

    return 0;
}