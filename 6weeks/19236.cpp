#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};


typedef struct {
    int x;
    int y;
    int d;
    bool alive=false;
} Fish;

int ans;

void copyFish(Fish* tmp, Fish* origin) {
    tmp->d = origin->d;
    tmp->x = origin->x;
    tmp->y = origin->y;
    tmp->alive = origin->alive;
}


void fishMove(int (*board)[4], Fish* fish) {
    for(int i=1; i<=16; i++) {
        int r, c, firstD=fish[i].d;
        if(!fish[i].alive) continue;
        while(1) {
            r = fish[i].x+dx[fish[i].d];
            c = fish[i].y+dy[fish[i].d];
            if(r>=0 && r<4 && c>=0 && c<4 && board[r][c]!=-1) break;
            fish[i].d=(fish[i].d+1)%8;
            if(fish[i].d==firstD) {
                r=fish[i].x; c=fish[i].y;
                break;
            }
        }
        int n = board[r][c];
        if(n!=0) {
            fish[n].x = fish[i].x;
            fish[n].y = fish[i].y;
        }
        board[fish[i].x][fish[i].y] = n;
        fish[i].x = r;
        fish[i].y = c;
        board[r][c] = i;
    }
}

void btk(int depth, int sx, int sy, int sd, int total, int (*board)[4], Fish* fish) {
    int r, c;
    int tmpBoard[4][4];
    Fish tmpFish[17];
    fishMove(board, fish);
    
    
    for(int i=1; i<=16; i++) copyFish(&tmpFish[i], &fish[i]);
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) tmpBoard[i][j] = board[i][j];
    
    bool flag = false;
    for(int i=1; i<=5; i++) {
        r=sx+(i*dx[sd]); c=sy+(i*dy[sd]);
        if(r<0 || c<0 || r>=4 || c>=4 || board[r][c]==0 || board[r][c]==-1) continue;
        flag = true;

        int n = board[r][c];
        board[r][c] = -1; board[sx][sy] = 0;
        fish[n].alive = false;

        btk(depth+1, r, c, fish[n].d, total+n, board, fish);

        for(int i=1; i<=16; i++) copyFish(&fish[i], &tmpFish[i]);
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) board[i][j] = tmpBoard[i][j];
        board[r][c] = n; board[sx][sy] = -1;
        fish[n].alive = true;
    }

    if(!flag) {
        ans = max(total, ans);
        return; 
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int sx, sy, sd;
    int board[4][4];
    Fish fish[17];

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            int a, b;
            cin >> a >> b;
            board[i][j] = a;
            fish[a] = {i, j, b-1, true};
        }
    }

    int start = board[0][0];
    board[0][0] = -1; //상어
    sx = 0; sy = 0; sd = fish[start].d;
    fish[start].alive = false;

    btk(1, sx, sy, sd, start, board, fish);
    cout << ans;
    return 0;
}