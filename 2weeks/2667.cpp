#include <bits/stdc++.h>
using namespace std;
int N;
int cnt=0;
int board[26][26];
vector<int> ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y) {
    int r, c;
    board[x][y] = 0;
    cnt++;
    for(int i=0; i<4; i++) {
        r=dx[i]+x; c=dy[i]+y;
        if(r<0 || c<0 || r>=N || c>= N) continue;
        if(board[r][c]==0) continue;
        dfs(r, c);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0; i<N; i++) {
        string line;
        cin >> line;
        for(int j=0; j<N; j++) board[i][j] = line[j]-'0';
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j]>0) {
                dfs(i, j);
                ans.push_back(cnt);
                cnt=0;
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n";
    return 0;
}