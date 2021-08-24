#include <bits/stdc++.h>
using namespace std;
int N, K;
int board[13][13];
deque<pair<int,int>> MAP[13][13]; // {번호, 방향}
tuple<int, int, int> arr[11]; //각 번호의 말이 현재 있는 위치와 층
int dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0};

void debug() {
    for(int i=0; i<K; i++) {
        int x, y, z;
        tie(x, y, z) = arr[i];
        cout << i << ": (" << x << "," << y << "," << z << ")    ";
    }
    cout << '\n';
}


bool ansCheck() {
    for(int i=0; i<K; i++) {
        int x, y, z;
        tie(x, y, z) = arr[i];
        if(MAP[x][y].size()>=4) return true;
    }
    return false;
}

void Move(int pos) {
    int x, y, z, r, c;
    tie(x, y, z) = arr[pos];

    int d = MAP[x][y][z].second;
    r=x+dx[d]; c=y+dy[d];

    if(r<0||c<0||r>=N||c>=N||board[r][c]==2) { //파란색
        if(d==0) d=1;
        else if(d==1) d=0;
        else if(d==2) d=3;
        else d=2;
        MAP[x][y][z].second = d;
        r=x+dx[d]; c=y+dy[d];
        if(r<0||c<0||r>=N||c>=N||board[r][c]==2) return;
    }
    
    if(board[r][c]==1) { //빨간색
        int loop = MAP[x][y].size()-z;
        while(loop--) {
            auto M = MAP[x][y].back();
            int i = M.first;
            int newZ = MAP[r][c].size();
            arr[i] = make_tuple(r, c, newZ); //좌표 바꾸기

            MAP[r][c].push_back(M); // 다음 좌표에 추가.
            MAP[x][y].pop_back();
        }
    } else if(board[r][c]==0) { //하얀색
        int tmpSize = MAP[x][y].size();
        int loop = MAP[x][y].size()-z;
        for(int i=z; i<tmpSize; i++) {
            int cur = MAP[x][y][i].first;
            arr[cur] = make_tuple(r, c, MAP[r][c].size());
            MAP[r][c].push_back(MAP[x][y][i]);
        }
        while(loop--) {
            MAP[x][y].pop_back();
        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> board[i][j];
    for(int i=0; i<K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        MAP[r-1][c-1].push_back({i, d-1});
        arr[i] = make_tuple(r-1, c-1, 0);
    }

    int pos = 0; //0번 말 이동
    int turn = 1;
    while(1) {
        Move(pos);
        if(ansCheck()) break;
        pos=(pos+1)%K;
        if(pos==0) {
            turn++;
            if(turn>1000) break;
        }
    }


    if(turn>1000) cout << -1;
    else cout << turn;

    return 0;
}