#include <bits/stdc++.h>
using namespace std;
int T, n;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        string worldstar;
        int maxi = 0;
        cin >> maxi >> worldstar;
        n--;
        while(n--) {
            string p;
            int cost;
            cin >> cost >> p;
            if(maxi<cost) {
                maxi = cost;
                worldstar = p;
            }
        }
        cout << worldstar << '\n';
    }
    return 0;
}