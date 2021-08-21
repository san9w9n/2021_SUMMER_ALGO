#include <bits/stdc++.h>
using namespace std;
int N, M, zero;
int space[52][52], ans=1e9;
vector<int> arr;
vector<pair<int, int>> virus;
pair<int, int> selectedPos[10];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

void bfs() {
    int x, y, r, c;
    queue<pair<int, int>> Q;
    int zeroTmp=zero;
    int dist[52][52];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) dist[i][j] = 0;
    for(int i=0; i<M; i++) {
        Q.push(selectedPos[i]);
        dist[selectedPos[i].first][selectedPos[i].second] = 1;
        zeroTmp--;
    }
    int maxTime=1;
    while(!Q.empty()) {
        x=Q.front().first; y=Q.front().second; Q.pop();
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=N||c>=N||space[r][c]==1) continue;
            if(dist[r][c]!=0) continue;
            if(dist[x][y]+1>maxTime) maxTime = dist[x][y]+1;
            dist[r][c]=dist[x][y]+1;
            Q.push({r, c});
            zeroTmp--;
        }
    }
    if(zeroTmp==0) {
        if(ans>maxTime-1) ans=maxTime-1;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> space[i][j];
            if(space[i][j]!=1) zero++;
            if(space[i][j]==2) virus.push_back({i, j});
        }
    }

    for(int i=0; i<M; i++) arr.push_back(0);
    for(int i=0; i<virus.size()-M; i++) arr.push_back(1);
    
    do {
        int cnt = 0;
        for(int i=0; i<virus.size(); i++) {
            if(arr[i]==0) {
                selectedPos[cnt] = {virus[i].first, virus[i].second};
                cnt++;
            }
        }
        bfs();
    } while(next_permutation(arr.begin(), arr.end()));

    if(ans>=N*N*2) cout << -1;
    else cout << ans;
    return 0;
}