#include <bits/stdc++.h>
using namespace std;
const int N=12, M=6;
char field[N][M];
bool visited[N][M];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, cnt, ans;
vector<pair<int, int>> V;

void init() {
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) visited[i][j] = false;
    V.clear();
}

void combo() {
    for(int i=0; i<V.size(); i++) {
        field[V[i].first][V[i].second] = '.';
    }
}

void dfs(int x, int y, char now) {
    int r, c;
    for(int d=0; d<4; d++) {
        r=x+dx[d]; c=y+dy[d];
        if(r<0||c<0||r>=N||c>=M||field[r][c]!=now||visited[r][c]) continue;
        visited[r][c]=true;
        V.push_back({r, c});
        cnt++;
        dfs(r, c, now);
    }
}

void fall() {
    queue<char> S;
    for(int j=0; j<M; j++) {
        for(int i=N-1; i>=0; i--) {
            if(field[i][j]!='.') {
                S.push(field[i][j]);
                field[i][j]='.';
            }
        }
        int idx=N-1;
        while(!S.empty()) {
            field[idx][j] = S.front();
            S.pop();
            idx--;
        }
    }
}
void debug() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cout << field[i][j];
        cout << '\n';
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> field[i][j];


    while(1) {
        // debug();
        bool flag = false;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                char tmp = field[i][j];
                if(tmp!='.') {
                    visited[i][j] = true;
                    V.push_back({i, j});
                    cnt = 1;
                    dfs(i, j, tmp);
                    if(cnt>=4) {
                        combo();
                        flag = true;
                    }
                    init();
                }
            }
        }
        if(!flag) break;
        ans++;
        fall();
    }
    cout << ans;
    return 0;
}