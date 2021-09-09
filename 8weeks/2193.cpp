#include <bits/stdc++.h>
using namespace std;
#define zero first
#define one second
int N;
pair<long long, long long> pNum[92];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    pNum[1].one = 1;
    pNum[2].first = 1;
    for(int i=3; i<=N; i++) {
        pNum[i].zero = pNum[i-1].one + pNum[i-1].zero;
        pNum[i].one = pNum[i-1].zero;
    }
    cout << pNum[N].one + pNum[N].zero;

    return 0;
}