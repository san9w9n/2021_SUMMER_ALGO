#include <bits/stdc++.h>
using namespace std;
string arr[1002];

bool cmp(string a, string b) {
    if(a.length() != b.length()) return a.length() < b.length();
    int totalA=0, totalB=0;
    for(int i=0; i<a.length(); i++) {
        int na = a[i]-'0';
        int nb = b[i]-'0';
        if(na>=0 && na<10) totalA+=na;
        if(nb>=0 && nb<10) totalB+=nb;
    }
    if(totalA!=totalB) return totalA < totalB;
    return a<b;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr + N, cmp);
    for(int i=0; i<N; i++) cout << arr[i] << "\n";
    return 0;
}