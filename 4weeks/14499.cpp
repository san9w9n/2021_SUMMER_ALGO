#include <bits/stdc++.h>
using namespace std;
int N, M, x, y, K;
int order[1002]; // 동:0, 서:1, 북:2, 남:3
int dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0};
int board[22][22];
int state[6]; //위, 아래, 서, 동, 북, 남

void copy() {
    if(board[x][y]==0) board[x][y] = state[1];
    else {
        state[1] = board[x][y];
        board[x][y] = 0;
    }
    cout << state[0] << '\n';
}
void East() { 
    // 서->위 , 위->동, 동->아래, 아래->서
    int tmp = state[0], tmp2 = state[3], tmp3 = state[1];
    state[0] = state[2];
    state[3] = tmp;
    state[1] = tmp2;
    state[2] = tmp3;

    copy();
}
void West() {
    // 동->위 , 위->서, 서->아래, 아래->동
    int tmp=state[0], tmp2=state[2], tmp3=state[1];
    state[0] = state[3];
    state[2] = tmp;
    state[1] = tmp2;
    state[3] = tmp3;

    copy();
}
void South() {
    //북->위 , 위->남, 남->아래, 아래->북
    int tmp=state[0], tmp2=state[5], tmp3=state[1];
    state[0] = state[4];
    state[5] = tmp;
    state[1] = tmp2;
    state[4] = tmp3;

    copy();
}
void North() {
    //남->위, 위->북, 북->아래, 아래->남
    int tmp=state[0], tmp2=state[4], tmp3=state[1];
    state[0] = state[5];
    state[4] = tmp;
    state[1] = tmp2;
    state[5] = tmp3;
    
    copy();
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> board[i][j];
    for(int i=0; i<K; i++) cin >> order[i];

    for(int i=0; i<K; i++) {
        int r,c;
        r=x+dx[order[i]-1]; c=y+dy[order[i]-1];
        if(r<0||c<0||r>=N||c>=M) continue;
        x=r; y=c;
        if(order[i]==1) East();
        else if(order[i]==2) West();
        else if(order[i]==3) North();
        else South();
    }
    return 0;
}