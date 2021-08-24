#include <bits/stdc++.h>
using namespace std;
int N;
int popular[21][21];
int MAP[21][21];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int popu[6];
int ans=1e9;

void init() {
    memset(MAP, 0, sizeof(MAP));
    memset(popu, 0, sizeof(popu));
}
bool inRange(int x, int y) {
    if(x<1 || x>N || y<1 || y>N) return false;
    return true;
}
void bfs1(int d1, int d2, int sx, int sy) {
    int r, c, x, y;
    queue<pair<int ,int>> Q;
    Q.push({1, 1});
    MAP[1][1] = 1;
    popu[1]+=popular[1][1];

    while(!Q.empty()) {
        x=Q.front().first; y=Q.front().second; Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(!inRange(r, c)) continue;
            if(r<1 || c<1 || r>=sx+d1 || c>sy || MAP[r][c]!=0) continue;
            MAP[r][c] = 1;
            popu[1]+=popular[r][c];;
            Q.push({r, c});
        }
    }
}
void bfs2(int d1, int d2, int sx, int sy) {
    int r, c, x, y;
    queue<pair<int ,int>> Q;
    Q.push({1, N});
    MAP[1][N] = 2;
    popu[2]+=popular[1][N];

    while(!Q.empty()) {
        x=Q.front().first; y=Q.front().second; Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(!inRange(r, c)) continue;
            if(r<1 || c<=sy || r>sx+d2 || c>N || MAP[r][c]!=0) continue;
            MAP[r][c] = 2;
            popu[2]+=popular[r][c];;
            Q.push({r, c});
        }
    }
}
void bfs3(int d1, int d2, int sx, int sy) {
    int r, c, x, y;
    queue<pair<int ,int>> Q;
    Q.push({N, 1});
    MAP[N][1] = 3;
    popu[3]+=popular[N][1];

    while(!Q.empty()) {
        x=Q.front().first; y=Q.front().second; Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(!inRange(r, c)) continue;
            if(r<sx+d1 || c<1 || r>N || c>=sy-d1+d2 || MAP[r][c]!=0) continue;
            MAP[r][c] = 3;
            popu[3]+=popular[r][c];
            Q.push({r, c});
        }
    }
}
void bfs4(int d1, int d2, int sx, int sy) {
    int r, c, x, y;
    queue<pair<int ,int>> Q;
    Q.push({N, N});
    MAP[N][N] = 4;
    popu[4]+=popular[N][N];

    while(!Q.empty()) {
        x=Q.front().first; y=Q.front().second; Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(!inRange(r, c)) continue;
            if(r<=sx+d2 || r>N || c<sy-d1+d2 || c>N || MAP[r][c]!=0) continue;
            MAP[r][c] = 4;
            popu[4]+=popular[r][c];
            Q.push({r, c});
        }
    }
}

bool makeBorder(int x, int y, int d1, int d2) { 
    int tmpX = x, tmpY = y;
    
    while(x!=tmpX+d1 || y!=tmpY-d1) {
        if(!inRange(x, y)) return false;
        MAP[x][y] = 5;
        x++; y--;
    }
    while(x!=tmpX+d1+d2 || y!=tmpY-d1+d2) {
        if(!inRange(x, y)) return false;
        MAP[x][y] = 5;
        x++;  y++;
    }
    if(!inRange(x, y)) return false;
    MAP[x][y] = 5;
    x=tmpX; y=tmpY;
    while(x!=tmpX+d2 || y!=tmpY+d2) {
        if(!inRange(x, y)) return false;
        MAP[x][y] = 5;
        x++; y++;
    }
    while(x!=tmpX+d1+d2 || y!=tmpY+d2-d1) {
        if(!inRange(x, y)) return false;
        MAP[x][y] = 5;
        x++; y--;
    }
    if(!inRange(x, y)) return false;
    MAP[x][y] = 5;
    return true;
}

void debug() {
    cout << "--------------------\n";
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) cout << MAP[i][j] << ' ';
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int total=0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> popular[i][j];
            total+=popular[i][j];
        }
    }
    // 1 <= x < x+d1+d2 <= N
    // x가 1일때 , d1+d2 <= N-1 이어야함.
    // x가 N일때 , d1+d2 <= 0 => 즉 x는 N일 수 없다.
    // x는 최대 N-2 까지고, d1+d2<=2 이다.


    // 1 <= y-d1 < y <y+d2 <= N
    // y가 1일 수 없다.
    // y가 2일때, 
    for(int d1=1; d1<=N; d1++) {
        for(int d2=1; d2<=N; d2++) {
            for(int y=1; y<=N; y++) {
                if(y-d1<1 || y+d2>N) continue;
                for(int x=1; x<=N; x++) {
                    if(x+d1+d2>N) continue;
                
                    
                    if(!makeBorder(x, y, d1, d2)) continue;
                    
                    bfs1(d1, d2, x, y);
                    bfs2(d1, d2, x, y);
                    bfs3(d1, d2, x, y);
                    bfs4(d1, d2, x, y);
                    // debug();
                    int sub = total;
                    for(int i=1; i<=5; i++) sub-=popu[i];
                    popu[5] = sub;
                    
                    int mini=1e9, maxi=-1;
                    for(int i=1; i<=5; i++) {
                        if(maxi<popu[i]) maxi=popu[i];
                        if(mini>popu[i]) mini=popu[i];
                    }
                    int div = maxi - mini;
                    if(ans>div) ans = div;
                    init();
                }
            }
        }
    }
    cout << ans;

    return 0;
}