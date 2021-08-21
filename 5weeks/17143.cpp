#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int R, C, M,fisher, ans;
int space[102][102];
deque<pair<pair<pair<int, int>, pair<int,int>>, int>> fish;
int dx[4]={-1,1,0,0}, dy[4]={0,0,1,-1};

void getFish() {
    for(int i=0; i<R; i++) {
        if(space[i][fisher]>0) {
            ans+=space[i][fisher];
            space[i][fisher]=0;
            break;
        }
    }
}

void swimFish() {
    int r, c, x, y, d, s, z;
    int size = fish.size();
    while(size--) {
        x=fish.front().F.F.F; y=fish.front().F.F.S;
        s=fish.front().F.S.F; d=fish.front().F.S.S;
        z=fish.front().S;
        fish.pop_front();
        if(x==-1 && y==-1) continue; //먹힌 것
        if(space[x][y]!=z) continue; //잡힌 것
        space[x][y] = 0;

        if (d==0 || d==1) {
            int Rotate = (R-1)*2;
            if (s>=Rotate) s=s%Rotate;
            for(int j=0; j<s; j++) {
                r=x+dx[d]; c=y+dy[d];
                if(r<0) {
                    d=1;
                    r+=2;
                }
                if(r>=R) {
                    d=0;
                    r-=2;
                }
                x=r; y=c;
            }
        } else {
            int Rotate = (C-1)*2;
            if (s>=Rotate) s=s%Rotate;
            for(int j=0; j<s; j++) {
                r=x+dx[d]; c=y+dy[d];
                if(c<0) {
                    d=2;
                    c+=2;
                }
                if (c>=C) {
                    d=3;
                    c-=2;
                }
                x=r; y=c;
            }
        }

        fish.push_back({{{x,y},{s,d}}, z});
    }

    for(int i=0; i<fish.size(); i++) {
        x=fish[i].F.F.F; y=fish[i].F.F.S;
        z=fish[i].S;
        if(x==-1 && y==-1) continue;
        if(space[x][y]==0) {
            space[x][y] = z;
        } else {
            if(space[x][y]>=z) {
                fish[i].F.F.F=-1;
                fish[i].F.F.S=-1;
            } else {
                space[x][y]=z;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> M;
    for(int i=0; i<M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r--; c--; d--;
        space[r][c] = z;
        fish.push_back({{{r,c},{s,d}}, z});
    }

    while(fisher<C) {
        getFish();
        swimFish();
        fisher++;
    }
    cout << ans;
    return 0;
}