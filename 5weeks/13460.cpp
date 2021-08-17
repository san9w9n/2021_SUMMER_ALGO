#include <bits/stdc++.h>
using namespace std;
int N, M, tx, ty, ans=1e9;
string board[15];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

bool precedure(int rx, int ry, int bx, int by, int d) {
    int rrx, rry;
    while(1) {
        rrx=rx+dx[d]; rry=ry+dy[d];
        if(board[rrx][rry]=='#') return true;
        if(rrx==bx && rry==by) return false;
        rx=rrx; ry=rry;
    }
    return false;
    //만약 false가 return 되면, 빨강이 파랑보다 뒤에있다는 것. 파랑먼저 움직여야함
    //true가 return 되면 빨강이 먼저있으니까 빨강먼저 움직여도 된당.
}

vector<int> move(int d, int rx, int ry, int bx, int by) {
    int rrx, rry, bbx, bby;
    int flag = 0; //-1:파란색 먼저 나감, 1:빨간색 먼저나감, 0: 아직 둘다 못나감
    bool check = precedure(rx, ry, bx, by, d);
    if(check) {
        while(1) { //빨강 이동
            rrx=rx+dx[d]; rry=ry+dy[d];
            if(rrx==tx && rry==ty) {
                rx=rrx; ry=rry;
                flag=1;
                break;
            }
            if(board[rrx][rry]=='#') break;
            rx=rrx; ry=rry;
        }
        while(1) {
            bbx=bx+dx[d]; bby=by+dy[d];
            if(bbx==tx && bby==ty) {
                flag = -1;
                break;
            }
            if(board[bbx][bby]=='#' || (bbx==rx && bby==ry)) break;
            bx=bbx; by=bby;
        }
    } else {
        while(1) {
            bbx=bx+dx[d]; bby=by+dy[d];
            if(bbx==tx && bby==ty) {
                flag = -1;
                bx=bbx; by=bby;
                break;
            }
            if(board[bbx][bby]=='#') break;
            bx=bbx; by=bby;
        }
        if(flag!=-1) {
            while(1) { //빨강 이동
                rrx=rx+dx[d]; rry=ry+dy[d];
                if(rrx==tx && rry==ty) {
                    flag=1;
                    break;
                }
                if(board[rrx][rry]=='#' || (rrx==bx && rry==by)) break;
                rx=rrx; ry=rry;
            }
        }
    }
    return {flag, rx, ry, bx, by};
}

void btk(int prevD, int cnt, int rx, int ry, int bx, int by) {
    if(cnt > 11) return;
    for(int d=0; d<4; d++) {
        // if(prevD==d) continue;
        vector<int> ret = move(d, rx, ry, bx, by);
        if(ret[0]==-1) continue;
        if(ret[0]==1) {
            if(ans>cnt+1) ans=cnt+1;
            return;
        }
        if(ret[1]!=rx || ret[2]!=ry || ret[3]!=bx || ret[4]!=by) btk(d, cnt+1, ret[1], ret[2], ret[3], ret[4]);
    }

}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int bx, by, rx, ry;
    for(int i=0; i<N; i++) {
        cin >> board[i];
        for(int j=0; j<M; j++) {
            if(board[i][j]=='B') {
                bx=i; by=j;
            } else if(board[i][j]=='R') {
                rx=i; ry=j;
            } else if(board[i][j]=='O') {
                tx=i; ty=j;
            }
        }
    }
    btk(-1, 0, rx, ry, bx, by);
    if(ans>10) cout << -1;
    else cout << ans;

    return 0;
}