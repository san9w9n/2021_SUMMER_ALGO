#include <bits/stdc++.h>
using namespace std;
int N, M, K, sec;
int board[22][22];
pair<int, int> scent[22][22];
int searchOrder[404][4][4];
int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

typedef struct {
    int X;
    int Y;
    int D;
    bool alive=false;
} Snake;

deque<Snake> snake[404];

bool checkAns() {
    int cnt = 0;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cnt += board[i][j];
    return (cnt==1);
}

int selectDir(int idx, int x, int y, int d) {
    int r, c, ret;
    bool flag = false;
    for(int e : searchOrder[idx][d]) {
        r=x+dx[e]; c=y+dy[e];
        if(r<0||c<0||r>=N||c>=N||scent[r][c].first>0) continue;
        flag = true;
        ret = e; break;
    }
    if(flag) return ret;
    for(int e : searchOrder[idx][d]) {
        r=x+dx[e]; c=y+dy[e];
        if(r<0||c<0||r>=N||c>=N) continue;
        if(scent[r][c].second==idx) return e;
    }
}

void scentUp() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(scent[i][j].first==0) continue;
            scent[i][j].first++;
            if(scent[i][j].first==K+1) scent[i][j] = {0, 0};
        }
    }
}

void sharkMove() {
    int x, y, r, c, d;

    for(int i=1; i<=M; i++) {
        if(snake[i].empty() || !snake[i][0].alive) continue;
        x = snake[i][0].X; y = snake[i][0].Y;
        scent[x][y] = {1, i};
    }

    for(int i=1; i<=M; i++) {
        if(snake[i].empty() || !snake[i][0].alive) continue;
        x = snake[i][0].X; y = snake[i][0].Y; d = snake[i][0].D;
        d = selectDir(i, x, y, d);
        r=x+dx[d]; c=y+dy[d];
        snake[i].push_front({r, c, d, true});
    }
    scentUp();
    for(int i=M; i>=1; i--) {
        if(snake[i].empty() || !snake[i][0].alive) continue;
        x = snake[i][1].X; y = snake[i][1].Y;
        board[x][y] = 0;

        r = snake[i][0].X; c = snake[i][0].Y;
        if(board[r][c]!=0 && board[r][c]<i) {
            snake[i][0].alive = false;
            continue;
        } else if(board[r][c]>i) {
            snake[board[r][c]][0].alive = false;
        }
        board[r][c] = i;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j]==0) continue;
            snake[board[i][j]].push_back({i, j, 0, true});
        }
    }
    for(int i=1; i<=M; i++) {
        cin >> snake[i][0].D;
        snake[i][0].D--;
    }
    for(int i=1; i<=M; i++) {
        for(int j=0; j<4; j++) {
            for(int d=0; d<4; d++) {
                cin >> searchOrder[i][j][d];
                searchOrder[i][j][d]--;
            }
        }
    }

    while(!checkAns() && sec<1001) {
        sharkMove();
        sec++;
    }

    if(sec==1001) cout << -1;
    else cout << sec;

    return 0;
}