#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll A, B, C;

ll mod(int a, int k, int m) {
    if(k==1) return a%m;
    ll res = mod(a, k/2, m);
    res = res * res % m;
    if(k%2 == 0) return res;
    else return res * a % m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    cout << mod(A,B,C);
    return 0;
}