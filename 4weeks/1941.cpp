#include <bits/stdc++.h>
using namespace std;
const int N=5;
string board[N];
vector<pair<int, int>> pos;
bool visited[N][N];
int dfs_board[N][N];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int ans, cnt, S, Y;

void dfs(int x, int y) {
    if(Y>=4) return;
    if(cnt==7 && S>=4) {
        ans++;
        return;
    }
    for(int d=0; d<4; d++) {
        int r=x+dx[d], c=y+dy[d];
        if(r<0||c<0||r>=N||c>=N||dfs_board[r][c]==0) continue;
        if(board[r][c]=='S') S++; 
        else Y++;
        dfs_board[r][c]=0;
        cnt++;
        dfs(r, c);
    }
}

void btk(int r, int c, int k) {
    if(k==7) {
        for(int i=0; i<7; i++) dfs_board[pos[i].first][pos[i].second]=1;
        dfs_board[pos[0].first][pos[0].second]=0;
        cnt=1;
        if(board[pos[0].first][pos[0].second]=='S') {
            S=1; Y=0;
        } else {
            Y=1; S=0;
        }
        dfs(pos[0].first, pos[0].second);
        for(int i=0; i<7; i++) dfs_board[pos[i].first][pos[i].second]=0;
        return;
    }
    if(c>=N) {
        r++;
        if(r>=N) return;
        c=0;
    }
    if(!visited[r][c]) {
        visited[r][c]=true;
        pos.push_back({r, c});
        btk(r, c+1, k+1);
        pos.pop_back();
        visited[r][c]=false;
    }
    btk(r, c+1, k);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<N; i++) cin >> board[i];
    btk(0, 0, 0);
    cout << ans;
    return 0;
}