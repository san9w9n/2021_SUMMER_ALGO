#include <bits/stdc++.h>
using namespace std;

void recursion(int N, int r, int c, int cnt) {
    if(N==2) {
        if(r<N/2 && c<N/2) { //1
            cout << cnt;
        } else if(r<N/2 && c>=N/2) { //2
            cout << cnt+1;
        } else if(r>=N/2 && c<N/2) { //3
            cout << cnt+2;
        } else if(r>=N/2 && c>=N/2) { //4
            cout << cnt+3;
        }
        return;
    }
    int square = (N/2)*(N/2);
    if(r<N/2 && c<N/2) { //1
        recursion(N/2, r, c,cnt);
    } else if(r<N/2 && c>=N/2) { //2
        recursion(N/2, r, c-N/2,cnt+square);
    } else if(r>=N/2 && c<N/2) { //3
        recursion(N/2, r-N/2, c,cnt+square*2);
    } else if(r>=N/2 && c>=N/2) { //4
        recursion(N/2, r-N/2, c-N/2, cnt+square*3);
    }
}


int main(void) {
    int N, r, c;
    cin >> N >> r >> c;
    int num = int(1<<N);
    recursion(num, r, c, 0);
    return 0;
}