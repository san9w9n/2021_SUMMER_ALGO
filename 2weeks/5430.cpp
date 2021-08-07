#include <bits/stdc++.h>
using namespace std;

int T, N;

void parse(string& tmp, deque<int>& D) {
    int cur = 0;
    for(int i=1; i<tmp.size()-1; i++) {
        if(tmp[i]==',') {
            D.push_back(cur);
            cur = 0;
        } else cur = 10*cur+(tmp[i]-'0');
    }
    if(cur!=0) D.push_back(cur);
}

void printDeque(deque<int> D, bool check) {
    if(check) {
        cout << "[";
        for(int i = 0; i < D.size(); i++) {
            cout << D[i];
            if(i+1 != D.size()) cout << ',';
        }
        cout << "]\n";
    } else cout << "error\n";
}

void RD(string query, deque<int>& D) {
    bool check = true;
    int rev=0;
    for(char c : query) {
        if(c=='R') {
            rev = 1 - rev;
        } else {
            if(D.empty()) {
                check = false;
                break;
            }
            if(rev==0) D.pop_front();
            else D.pop_back();
        }
    }
    if(check && !D.empty() && rev==1) reverse(D.begin(), D.end());
    printDeque(D, check);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {
        string query;
        string tmp;
        deque<int> D;

        cin >> query;
        cin >> N;
        cin >> tmp;

        parse(tmp, D);
        RD(query, D);
    }
    return 0;
}