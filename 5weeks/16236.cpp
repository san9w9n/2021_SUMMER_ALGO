#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N;
int space[30][30];
vector<pair<int, int>> fish[8];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int minD=1e9, minX=1e9, minY=1e9;

bool bfs(int x, int y, int size) {
    int dist[22][22], r, c;
    queue<pair<int, int>> Q;
    minD=1e9; minX=1e9; minY=1e9;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) dist[i][j] = 0;
    if(x>=N || y>=N) return false;
    Q.push({x, y});
    dist[x][y] = 1;
    space[x][y] = 0;
    while(!Q.empty()) {
        x=Q.front().X; y=Q.front().Y; Q.pop();

        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=N||c>=N) continue;
            if(space[r][c]>size) continue;
            if(dist[r][c]!=0 && dist[r][c]<=dist[x][y]+1) continue;
            dist[r][c] = dist[x][y]+1;
            Q.push({r, c});
        }
    }
    int fx, fy;
    for(int s=1; s<size; s++) {
        if(s>=8) break;
        for(int i=0; i<fish[s].size(); i++) {
            fx=fish[s][i].X; fy=fish[s][i].Y;
            if(space[fx][fy]==0 || space[fx][fy]==9) continue;
            if(dist[fx][fy]==0) continue;
            if(minD==dist[fx][fy]) {
                if(minX>fx) {
                    minX=fx; minY=fy;
                } else if(minX==fx) {
                    if(minY>fy) {
                        minX=fx; minY=fy;
                    }
                }
            } else if(minD>dist[fx][fy]) {
                minD=dist[fx][fy];
                minX=fx; minY=fy;
            }
        }
    }
    
    if(minD>N*N*4 || minX>=N || minY>=N) return false;
    space[minX][minY]=9;
    return true;
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int x, y;

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> space[i][j];
            if(space[i][j]!=0) {
                if(space[i][j]==9) {
                    x=i;
                    y=j;
                } else fish[space[i][j]].push_back({i, j});
            }
        }
    }

    int size=2, cnt=0, ans=0;
    while(1) {
        bool check = bfs(x, y, size);
        if(!check) break;
        cnt++;
        if(cnt==size) {
            cnt=0;
            size++;
        }
        ans+=minD-1;
        x=minX; y=minY;
    }

    cout << ans;


    return 0;
}