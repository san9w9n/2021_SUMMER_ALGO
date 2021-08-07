#include <bits/stdc++.h>
using namespace std;

int main(void) {
    stack<int> idx;
    idx.push(0);
    int left = 1, answer = 0;

    string input;
    cin >> input;

    for(int i=1; i<input.length(); i++) {
        if(input[i]=='(') {
            idx.push(i);
            left++;
        } else {
            if(idx.top()==i-1) {
                left--;
                answer+=left;
                idx.pop();
            } else {
                idx.pop();
                left--;
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}