#include <bits/stdc++.h>
using namespace std;
int N, maxi = -99999;
int arr[9];

int calculate(int* array) {
    int total=0;
    for(int i=0; i<N-1; i++) total+=abs(array[i]-array[i+1]);
    return total;
}

void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}

void permutation(int k) {
    if (k == N) {
        maxi = max(maxi, calculate(arr));
        return;
    }
    for(int i = k; i < N; i++) {
        swap(arr[k], arr[i]);
        permutation(k+1);
        swap(arr[k], arr[i]);
    }
}
int main(void) {
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    permutation(0);
    cout << maxi;

    return 0;
}