#include <bits/stdc++.h>
using namespace std;
string num;
int digit[10];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(digit, digit+10, 0);
    cin >> num;
    for(char c : num) {
        int n = c-'0';
        if(n==9) digit[6]++;
        else digit[n]++;
    }

    int maxi = 0;
    for(int i=0; i<12; i++) {
        int n = digit[i];
        if(i==9) continue;
        if(i==6) {
            int tmp = n;
            n = tmp/2;
            n += (tmp%2==0) ? 0 : 1;
        }
        if(maxi<n) maxi=n;
    }
    cout << maxi;
    return 0;
}