#include <bits/stdc++.h>
using namespace std;

void recursion(int x, int y, int n, int m, int prev) {
    int sub = pow(n/2, 2);
    int pos = n/2;
    // cout << "x: " << x << ", y: " << y <<", n: " << n << ", m: " << m << ", prev: "  << prev << '\n';
    if(n==1) {
        cout << x << ' ' << y;
        return;
    }
    
    if(prev==1) {
        if(m>3*sub) {
            recursion(x+pos, y, pos, m-3*sub, 3);
        } else if(m>2*sub) {
            recursion(x+pos, y+pos, pos, m-2*sub, 1);
        } else if(m>sub) {
            recursion(x, y+pos, pos, m-sub, 1);
        } else {
            recursion(x, y, pos, m, 2);
        }
    } else if(prev==2) {
        if(m>3*sub) {
            recursion(x, y+pos, pos, m-3*sub, 4);
        } else if(m>2*sub) {
            recursion(x+pos, y+pos, pos, m-2*sub, 2);
        } else if(m>sub) {
            recursion(x+pos, y, pos, m-sub, 2);
        } else {
            recursion(x, y, pos, m, 1);
        }
    } else if(prev==3) {
        if(m>3*sub) {
            recursion(x+pos, y, pos, m-3*sub, 1);
        } else if(m>2*sub) {
            recursion(x, y, pos, m-2*sub, 3);
        } else if(m>sub) {
            recursion(x, y+pos, pos, m-sub, 3);
        } else {
            recursion(x+pos, y+pos, pos, m, 4);
        }
    } else {
        if(m>3*sub) {
            recursion(x, y+pos, pos, m-3*sub, 2);
        } else if(m>2*sub) {
            recursion(x, y, pos, m-2*sub, 4);
        } else if(m>sub) {
            recursion(x+pos, y, pos, m-sub, 4);
        } else {
            recursion(x+pos, y+pos, pos, m, 3);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    recursion(1, 1, n, m, 1);
    return 0;
}