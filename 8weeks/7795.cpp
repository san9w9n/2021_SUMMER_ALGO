#include <bits/stdc++.h>
using namespace std;
int N, M;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        vector<int> A, B;
        cin >> N >> M;
        for(int i=0; i<N; i++) {
            int a;
            cin >> a;
            A.push_back(a);
        }
        for(int i=0; i<M; i++) {
            int b;
            cin >> b;
            B.push_back(b);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int last = 0, ans = 0;
        for(int i=0; i<N; i++) {
            ans+=last;
            for(int j=last; j<M; j++) {
                if(A[i]<=B[j]) break;
                last++;
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}