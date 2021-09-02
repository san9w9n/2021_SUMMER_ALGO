#include <bits/stdc++.h>
using namespace std;
int N, ans;
int MAP[501][501];
int rate[9] = {1,7,10,2,5,10,7,1,2};
int sdx[4][9]={{-1,-1,-1,-2,0,1,1,1,2},
                {-1,0,1,0,2,1,0,-1,0},
                {-1,-1,-1,-2,0,1,1,1,2},
                {1,0,-1,0,-2,-1,0,1,0}};
int sdy[4][9]={{1,0,-1,0,-2,-1,0,1,0},
                {-1,-1,-1,-2,0,1,1,1,2},
                {-1,0,1,0,2,1,0,-1,0},
                {-1,-1,-1,-2,0,1,1,1,2}};
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> MAP[i][j];

    int x=N/2, y=N/2, r, c;
    int move=1, d=0;
    while(1) { 
        for(int i=0; i<move; i++) {
            int sand, windy, tmp;
            x+=dx[d]; y+=dy[d];
            sand = tmp = MAP[x][y];
            MAP[x][y] = 0;
            for(int j=0; j<9; j++) {
                r=x+sdx[d][j]; c=y+sdy[d][j];
                windy = (sand*rate[j]/100);
                if(r<0||c<0||r>=N||c>=N) {
                    ans+=windy; tmp-=windy;
                    continue;
                }
                MAP[r][c] += windy;
                tmp-=windy;
            }
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=N||c>=N) ans+=tmp;
            else MAP[r][c]+=tmp;
            if(x==0 && y==0) goto PRINT;
        }
        d=(d+1)%4;
        if(d%2==0) move++;   
    }

    PRINT: cout << ans;

    return 0;
}