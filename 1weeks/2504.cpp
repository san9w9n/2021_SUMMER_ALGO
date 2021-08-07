#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string input;
    stack<char> chr;
    int answer=0, small=0, big=0;
    bool calculated = false;

    cin >> input;
    for(int i=0; i<input.length(); i++) {
        if(input[i] == ')') {
            if(chr.size()>0 && chr.top()=='(') {
                if(!calculated) {
                    answer+= (int(pow(2,small)) * int(pow(3,big)));
                    calculated = true;
                }
                small-=1;
                chr.pop();
            } else {
                cout << 0;
                return 0;
            }
        } else if(input[i] == ']') {
            if(chr.size()>0 && chr.top()=='[') {
                if(!calculated) {
                    answer+= (int(pow(2,small)) * int(pow(3,big)));
                    calculated = true;
                }
                big-=1;
                chr.pop();
            } else {
                cout << 0;
                return 0;
            }
        } else if(input[i] == '(') {
            calculated = false;
            small+=1;
            chr.push('(');
        } else {
            calculated = false;
            big+=1;
            chr.push('[');
        }
    }
    if(chr.empty()) cout << answer;
    else cout << 0;
    
    return 0;
}