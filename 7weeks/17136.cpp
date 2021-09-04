#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int ans=1e9;
int board[N+1][N+1];

bool one(int x, int y) {
    if(x<0 || y<0 || x>=N || y>=N) return false;
    if(board[x][y]==0) return false;
    board[x][y] = 0;
    return true;
}
bool two(int x, int y) {
    if(y+2>N || x+2>N) return false;
    for(int i=x; i<=x+1; i++) {
        for(int j=y; j<=y+1; j++) {
            if(i<0 || j<0 || i>=N || j>=N) return false;
            if(board[i][j]==0) return false;
        }
    }
    for(int i=x; i<=x+1; i++)
        for(int j=y; j<=y+1; j++)
            board[i][j] = 0;
    return true;
}
bool three(int x, int y) {
    if(y+3>N || x+3>N) return false;
    for(int i=x; i<=x+2; i++) {
        for(int j=y; j<=y+2; j++) {
            if(i<0 || j<0 || i>=N || j>=N) return false;
            if(board[i][j]==0) return false;
        }
    }
    for(int i=x; i<=x+2; i++)
        for(int j=y; j<=y+2; j++)
            board[i][j] = 0;
    return true;
}
bool four(int x, int y) {
    if(y+4>N || x+4>N) return false;
    for(int i=x; i<=x+3; i++) {
        for(int j=y; j<=y+3; j++) {
            if(i<0 || j<0 || i>=N || j>=N) return false;
            if(board[i][j]==0) return false;
        }
    }
    for(int i=x; i<=x+3; i++)
        for(int j=y; j<=y+3; j++)
            board[i][j] = 0;
    return true;
}
bool five(int x, int y) {
    if(y+5>N || x+5>N) return false;
    for(int i=x; i<=x+4; i++) {
        for(int j=y; j<=y+4; j++) {
            if(i<0 || j<0 || i>=N || j>=N) return false;
            if(board[i][j]==0) return false;
        }
    }
    for(int i=x; i<=x+4; i++)
        for(int j=y; j<=y+4; j++)
            board[i][j] = 0;
    return true;
}
void debug() {
    cout << "-----------------------------\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void btk(int r, int c, int on, int tw, int th, int fo, int fi) {
    if (c==N) { 
        btk(r+1, 0, on, tw, th, fo, fi); 
        return; 
    } // 마지막 줄까지 다 확인했으므로 현재 색종이 개수 확인 
    if (r==N) { 
        ans = min(ans, on+tw+th+fo+fi); 
        return; 
    }

    if(board[r][c]==0) {
        btk(r, c+1, on, tw, th, fo, fi);
        return;
    }
    if(fi<5 && five(r, c)) {
        btk(r, c+5, on, tw, th, fo, fi+1);
        for(int x=r; x<=r+4; x++)
            for(int y=c; y<=c+4; y++)
                board[x][y] = 1;
    }
    if(fo<5 && four(r, c)) {
        btk(r, c+4, on, tw, th, fo+1, fi);
        for(int x=r; x<=r+3; x++)
            for(int y=c; y<=c+3; y++)
                board[x][y] = 1;
    }
    if(th<5 && three(r, c)) {
        btk(r, c+3, on, tw, th+1, fo, fi);
        for(int x=r; x<=r+2; x++)
            for(int y=c; y<=c+2; y++)
                board[x][y] = 1;
    }
    if(tw<5 && two(r, c)) {
        btk(r, c+2, on, tw+1, th, fo, fi);
        for(int x=r; x<=r+1; x++)
            for(int y=c; y<=c+1; y++)
                board[x][y] = 1;
    }
    if(on<5 && one(r, c)) {
        btk(r, c+1, on+1, tw, th, fo, fi);
        board[r][c] = 1;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> board[i][j];
    btk(0, 0, 0,0,0,0,0);
    if(ans==1e9) cout << -1;
    else cout << ans;

    return 0;
}