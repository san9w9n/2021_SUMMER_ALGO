#include <bits/stdc++.h>
#define dist(r1, c1, r2, c2) abs((r1)-(r2)) + abs((c1)-(c2));
using namespace std;
int N, M, h=0, c=0, ans=1e9;
int field[52][52];
int house[102][2];
int bbq[15][2];


int findDist(int *visit) {
    int res = 0;
    for(int i=0; i<h; i++) {
        int min = 1e9;
        for(int j=0; j<c; j++) {
            if(visit[j]==1) continue;
            int d = dist(house[i][0], house[i][1], bbq[j][0], bbq[j][1]);
            if(min > d) min = d;
        }
        res+=min;
    }
    return res;
}

void btk(int k, int cnt, int* visit) {
    if(k>=c) {
        if(cnt==c-M) ans = min(ans, findDist(visit));
        return;
    }
    if(cnt==c-M) {
        ans = min(ans, findDist(visit));
        return;
    }
    int* tmp1 = new int[c]();
    int* tmp2 = new int[c]();
    for(int i=0; i<c; i++) tmp1[i] = tmp2[i] =  visit[i];
    tmp1[k] = 1;
    btk(k+1, cnt+1, tmp1);
    btk(k+1, cnt,  tmp2);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        int t;
        for(int j=0; j<N; j++) {
            cin >> t;
            field[i][j] = t;
            if(t==1) {
                house[h][0] = i;
                house[h++][1] = j;
            } else if(t==2) {
                bbq[c][0] = i;
                bbq[c++][1] = j;
            }
        }
    }
    int* visit = new int[c]();
    btk(0, 0, visit);
    cout << ans;
    return 0;
}