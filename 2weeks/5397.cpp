#include <bits/stdc++.h>
using namespace std;
vector<char> v;
vector<char> tmp;

void init() {
    v.clear();
    tmp.clear();
}
void left() {
    tmp.push_back(v.back());
    v.pop_back();
}

void right() {
    v.push_back(tmp.back());
    tmp.pop_back();
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string input;
        cin >> input;
        for(char c : input) {
            if(c=='<') {
                if(!v.empty()) left();
            } else if(c=='>') {
                if(!tmp.empty()) right();
            } else if(c=='-') {
                if(!v.empty()) v.pop_back();
            } else v.push_back(c);
        }
        while(!tmp.empty()) {
            v.push_back(tmp.back());
            tmp.pop_back();
        }
        for(char c : v) cout << c;
        cout << "\n";
        init();
    }
    return 0;
}