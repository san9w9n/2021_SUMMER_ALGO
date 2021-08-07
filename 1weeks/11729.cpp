#include <bits/stdc++.h>
using namespace std;

void hanoi(int from, int to, int N) {
    if(N==1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    hanoi(from, 6-from-to, N-1);
    cout << from << ' ' << to << '\n';
    hanoi(6-from-to,to, N-1);
}

int main() {
    int N;
    cin >> N;
    cout << (1<<N) - 1 << '\n';
    hanoi(1,3,N);
}