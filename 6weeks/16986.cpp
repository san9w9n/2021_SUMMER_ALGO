#include <bits/stdc++.h>
using namespace std;
int N, K;
int fight[10][10];
int player[3][20]; //지우는 0, 경희는 1, 민호는 2
bool ans;
int brute[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

int play(int a, int b, int vs1, int vs2) { //vs1이 vs2 상대로 이기나 지나.
    if(fight[a][b]==2) return 1;
    else if(fight[a][b]==0) return -1;
    else { //비겼을때
        if(vs1<vs2) return -1;
        else return 1;
    }
}


bool solve() {
    int k1=0, k2=0, cnt=0;
    int win0=0, win1=0, win2=0;
    int v1=0, v2=1;
    while(1) {
        if(v1!=0 && v2!=0) {
            if(k1>=20 || k2>=20) return false;
            int n = play(player[v1][k1], player[v2][k2], v1, v2);
            k1++; k2++;
            if(n==1) {
                v2=v1;
                v1=0;
                win1++;
                if(win1>=K) return false;
            } else {
                v1=0;
                win2++;
                if(win2>=K) return false;
            }
        } else {
            int n;
            if(v2==1) {
                if(k1>=20) return false;
                n = play(brute[cnt], player[v2][k1], 0, v2);
                k1++;
            } else {
                if(k2>=20) return false;
                n = play(brute[cnt], player[v2][k2], 0, v2);
                k2++;
            }
            if(n==1) {
                v2=3-v2;
                win0++;
                if(win0>=K) return true;
            } else {
                if(v2==1) win1++;
                else win2++;
                if(win1>=K || win2>=K) return false;

                v1=3-v2;
                if(v2<v1) {
                    int tmp=v2;
                    v2=v1; v1=tmp;
                }
            }
            cnt++;
            if(cnt>=N) return false;
        }
    }
    return false;
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> fight[i][j];
    for(int i=0; i<20; i++) {
        cin >> player[1][i];
        player[1][i]--;
    }
    for(int i=0; i<20; i++) {
        cin >> player[2][i];
        player[2][i]--;
    }

    bool check = false;
    do {
        for(int i=0; i<N; i++) player[0][i] = brute[0];
        check = solve();
        if(check) break;
    } while(next_permutation(brute, brute+N)); 
    
    if(check) cout << 1;
    else cout << 0;

    return 0;
}