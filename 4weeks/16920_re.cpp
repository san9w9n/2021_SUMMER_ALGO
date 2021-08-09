#include <bits/stdc++.h>
using namespace std;
int N, M, P, zero=0;
int len[10];
int field[1002][1002];
queue<pair<int, int>> player[10];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int ans[10];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> P;
    for(int i=1; i<=P; i++) cin >> len[i];

    string line;
    for(int i=0; i<N; i++) {
        cin >> line;
        for(int j=0; j<M; j++) {
            if(line[j]=='.') {
                field[i][j] = 0;
                zero++;
            } else if(line[j]=='#') {
                field[i][j] = -1;
            } else {
                int t = line[j]-'0';
                field[i][j] = t;
                player[t].push({i, j});
            }
        }
    }
    int t=1;
    while(1) {
        for(int t=1; t<=P; t++) {
            int dist = len[t];
            while(!player[t].empty() && dist--) {
                int s = player[t].size();
                for(int i=0; i<s; i++) {
                    int x, y, r, c;
                    x = player[t].front().first;
                    y = player[t].front().second;
                    player[t].pop();
                    for(int d=0; d<4; d++) {
                        r=x+dx[d]; c=y+dy[d];
                        if(r<0||c<0||r>=N||c>=M||field[r][c]!=0) continue;
                        field[r][c] = t;
                        player[t].push({r, c});
                    }
                }
            }
        }
        bool check = true;
        for (int i=1; i<=P; i++) {
			if (!player[i].empty()) {
				check = false;
				break;
			}
		}
        if(check) break;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(field[i][j]>0) ans[field[i][j]]++;
        }
    }
    for(int i=1; i<=P; i++) cout << ans[i] << ' ';
    return 0;
}