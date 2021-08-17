#include <bits/stdc++.h>
using namespace std;
int N, M, ans, d; // 북, 동, 남, 서
int board[52][52];
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

bool RotateFind(int r, int c) {
    d-=1;
    if(d==-1) d=3;
    r+=dx[d], c+=dy[d];
    if(r<0 || c<0 || r>=N || c>= M || board[r][c]!=0) return false;
    return true;
}
void move(int& r, int& c) {
    r+=dx[d]; c+=dy[d];
}
void clean(int r, int c) {
    if(board[r][c]!=2) {
        board[r][c] = 2;
        ans++;
    }
}
bool back(int& r, int& c) {
    int tmpD =(d+2)%4;
    int x, y;
    x=r+dx[tmpD]; y=c+dy[tmpD];
    if(x<0 || y<0 || x>=N || y>=M || board[x][y]==1) return false;
    r=x; c=y;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int r, c;
    cin >> N >> M >> r >> c >> d;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> board[i][j];
    while(1) {
        clean(r, c);
        bool check = false;
        for(int i=0; i<4; i++) {
            check = RotateFind(r, c);
            if(check) break;
        }
        if(check) {
            move(r, c);
            continue;
        } else {
            bool flag = back(r, c);
            if(!flag) break;
        }
    }
    cout << ans;
    return 0;
}