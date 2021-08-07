#include <bits/stdc++.h>
using namespace std;
int N;
int* cnt = new int[101]();

int func2(int arr[], int N) {
    for(int i=0; i<N; i++) cnt[arr[i]]++;
    for(int i=0; i<N; i++) {
        if(arr[i]==50) {
            if(cnt[50]>=2) return 1;
            else continue;
        }
        if(cnt[100-arr[i]]>0) {
            return 1;
        }
    }
    return 0;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int* arr = new int[N]();
    for(int i=0; i<N; i++) cin >> arr[i];
    cout << func2(arr, N);

    return 0;
}