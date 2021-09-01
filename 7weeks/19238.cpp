#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int N, M, fuel, sx, sy;
int board[22][22];

typedef struct {
    int X;
    int Y;
    int TX;
    int TY;
    int D;
    int SD;
} PassInfo;
PassInfo passInfo[404];

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.F<b.F) return false;
        if(a.F==b.F) {
            if(passInfo[a.S].X < passInfo[b.S].X) return false;
            if(passInfo[a.S].X == passInfo[b.S].X) {
                if(passInfo[a.S].Y < passInfo[b.S].Y) return false;
            }
        }
        return true;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> endTopass[404];

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
bool visited[404];

int bfs(int x, int y, int tx, int ty) {
    queue<pair<int, int>> Q;
    int r, c;
    int dist[22][22];
    memset(dist, 0, sizeof(dist));
    Q.push({x, y});
    dist[x][y] = 1;
    if(x==tx && y==ty) return 0;
    while(!Q.empty()) {
        x = Q.front().F; y = Q.front().S;
        Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<1|| c<1 || r>N || c>N || board[r][c]==1 || dist[r][c]!=0) continue;
            if(r==tx && c==ty) return dist[x][y];
            dist[r][c] = dist[x][y] + 1;
            Q.push({r, c});
        }
    }
    return -1;
}


bool gogo(int k, int idx) {
    if(k==M) {
        return true;
    }

    while(!endTopass[idx].empty()) {
        if(!visited[endTopass[idx].top().S]) break;
        endTopass[idx].pop();
    }
    if(fuel >= endTopass[idx].top().F + passInfo[endTopass[idx].top().S].D) {
        fuel -= endTopass[idx].top().F + passInfo[endTopass[idx].top().S].D;
        fuel += 2*passInfo[endTopass[idx].top().S].D;
        sx = passInfo[endTopass[idx].top().S].TX; sy = passInfo[endTopass[idx].top().S].TY;
        visited[endTopass[idx].top().S] = true;
        return gogo(k+1, endTopass[idx].top().S);
    } else {
        return false;
    }

}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> fuel;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> board[i][j];
    cin >> sx >> sy;
    bool flag = false;
    for(int i=0; i<M; i++) {
        int x, y, tx, ty, d, sd;
        cin >> x >> y >> tx >> ty;
        d = bfs(x, y, tx, ty);
        sd = bfs(x, y, sx, sy);
        if(d==-1) {
            flag = true;
            continue;
        }
        
        passInfo[i] = {x, y, tx, ty, d, sd};
    }
    if(flag) {
        cout << -1;
        return 0;
    }

    int minD = 1e9, startI;
    flag = false;
    for(int i=0; i<M; i++) {
        if(passInfo[i].SD==-1) continue;
        if(minD==1e9) {
            minD = passInfo[i].SD;
            startI = i;
            continue;
        }
        if(minD>passInfo[i].SD) {
            minD = passInfo[i].SD;
            startI = i;
        } else if(minD==passInfo[i].SD) {
            if(passInfo[i].X<passInfo[startI].X) {
                minD = passInfo[i].SD;
                startI = i;
            } else if(passInfo[i].X==passInfo[startI].X) {
                if(passInfo[i].Y<passInfo[startI].Y) {
                    minD = passInfo[i].SD;
                    startI = i;
                }
            }
        }
    }
    
    if(minD==1e9) {
        cout << -1;
        return 0;
    }

    visited[startI] = true;
    if(fuel>=minD+passInfo[startI].D) {
        fuel-=minD+passInfo[startI].D;
        fuel+=2*passInfo[startI].D;
    } else {
        cout << -1;
        return 0;
    }
    sx=passInfo[startI].TX; sy=passInfo[startI].TY;
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            if(i==j || j==startI) continue;
            endTopass[i].push({bfs(passInfo[i].TX, passInfo[i].TY, passInfo[j].X, passInfo[j].Y), j});
        }
    }

    bool check = gogo(1, startI);
    if(check) cout << fuel;
    else cout << -1;

    return 0;
}