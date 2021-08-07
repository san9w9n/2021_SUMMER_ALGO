#include <bits/stdc++.h>
using namespace std;
string input;
int* alpha = new int[26]();

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    for(int i=0; i<input.length(); i++) alpha[int(input[i]) - 97]++;
    for(int i=0; i<26; i++) cout << alpha[i] << " ";
    
    return 0;
}