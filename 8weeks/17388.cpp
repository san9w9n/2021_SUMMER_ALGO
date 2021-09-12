#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(a+b+c>=100) cout << "OK";
    else {
        int mini = min({a, b, c});
        if(a==mini) cout << "Soongsil";
        else if(b==mini) cout << "Korea";
        else cout << "Hanyang";
    }
    return 0;
}