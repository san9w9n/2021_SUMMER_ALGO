#include <bits/stdc++.h>
using namespace std;
string a, b;
int alpha[26];
int main(void) {
    cin >> a >> b;
    for(char c: a) alpha[c-'a']++;
    for(char c: b) alpha[c-'a']--;
    int total=0;
    for(int i=0; i<26; i++) {
        if(alpha[i]<0) total-=alpha[i];
        else total+=alpha[i];
    }
    cout << total;
    return 0;
}