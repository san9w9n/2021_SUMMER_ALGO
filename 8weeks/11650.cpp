#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N;
vector<pair<int, int>> V;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.X>b.X) return false;
    if(a.X==b.X) {
        if(a.Y>b.Y) return false;
    }
    return true;
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--) {
        int x, y;
        cin >> x >> y;
        V.push_back({x, y});
    }
    
    sort(V.begin(), V.end(), cmp);
    for(int i=0; i<V.size(); i++) cout << V[i].X << ' ' << V[i].Y << '\n';

    return 0;
}