#include <bits/stdc++.h>
using namespace std;
int N;
int arr[202];

int main(void) {
    int i;
    cin >> N;
    while(N--) {
        cin >> i;
        arr[i+100]++;
    }
    cin >> i;
    cout << arr[i+100];
    return 0;
}