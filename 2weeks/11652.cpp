#include <bits/stdc++.h>
using namespace std;
int N, num;
long long arr[100002];
int main(void) {
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr+N);
    int con = 1, mxcnt = 0;
    long long mxval = -(111 << 62)-1, last;

    last = arr[0];
    for(int i=1; i<N; i++) {
        if(arr[i]!=last) {
            if(mxcnt < con) {
                mxcnt = con;
                mxval = last;
            }
            con = 1;
            last = arr[i];
        } else con++;
    }
    if(con > mxcnt) mxval = arr[N-1];
    cout << mxval;

    return 0;
}