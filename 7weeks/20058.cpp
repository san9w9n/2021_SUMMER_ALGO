#include <bits/stdc++.h>
using namespace std;
int N, Q;
int MAP[70][70], ans1, ans2, cnt;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

void rotateMAP(int x, int y, int L) {
    int tmp1[70][70], tmp2[70][70];
    for(int i=x; i<x+L; i++) for(int j=y; j<y+L; j++) tmp1[i-x][j-y] = MAP[i][j];

    for(int i=0; i<L; i++) for(int j=0; j<L; j++) tmp2[j][L-i-1] = tmp1[i][j];
        
    for(int i=0; i<L; i++) for(int j=0; j<L; j++) MAP[i+x][j+y] = tmp2[i][j];
}

void DivideConquer(int x, int y, int L, int S) {
    if(L==S) {
        rotateMAP(x, y, L);
        return;
    }
    S/=2;
    DivideConquer(x, y, L, S);
    DivideConquer(x, y+S, L, S);
    DivideConquer(x+S, y, L, S);
    DivideConquer(x+S, y+S, L, S);
}

void melt() {
    int r, c, cnt;
    int tmp1[70][70];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(MAP[i][j]==0) {
                tmp1[i][j] = MAP[i][j];
                continue;
            }
            cnt = 0;
            for(int d=0; d<4; d++) {
                r=i+dx[d]; c=j+dy[d];
                if(r<0||c<0||r>=N||c>=N||MAP[r][c]==0) continue;
                cnt++;
            }
            if(cnt<3) {
                tmp1[i][j] = MAP[i][j]-1;
            } else {
                tmp1[i][j] = MAP[i][j];
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            MAP[i][j] = tmp1[i][j];
        }
    }
}

void dfs(int x, int y) {
    int r, c;
    for(int d=0; d<4; d++) {
        r=x+dx[d]; c=y+dy[d];
        if(r<0||c<0||r>=N||c>=N||MAP[r][c]==0) continue;
        MAP[r][c] = 0;
        cnt++;
        dfs(r, c);
    }
}

void debug() {
    cout << "----------------------\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cout << MAP[i][j] << ' ';
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    N = pow(2,N);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> MAP[i][j];
    
    while(Q--) {
        int L;
        cin >> L;
        L = pow(2, L);
        DivideConquer(0, 0, L, N);
        melt();
    }
    


    for(int i=0; i<N; i++) for(int j=0; j<N; j++) ans1+=MAP[i][j];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(MAP[i][j]==0) continue;
            cnt=1;
            MAP[i][j]=0;
            dfs(i, j);
            ans2 = max(cnt, ans2);
        }
    }

    cout << ans1 << '\n' << ans2;

    return 0;
}