#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N, M, G, R, CAND;
int field[52][52];
vector<pair<int, int>> niceSoil;
int brute[10];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int bfs(){
  int cnt = 0;
  pair<int,int> state[52][52];

  queue<pair<int,int>> q;
  for(int i = 0; i < CAND; i++){
    if(brute[i] == 1 || brute[i] == 2){
      state[niceSoil[i].X][niceSoil[i].Y] = {0, brute[i]};
      q.push(niceSoil[i]);
    }
  }
  while(!q.empty()){
    int x = q.front().X, y = q.front().Y; q.pop();
    int curtime = state[x][y].X;
    int curcolor = state[x][y].Y;
    if(state[x][y].Y == 3) continue;
    for(int d=0; d<4; d++) {
      int r = x+dx[d], c = y+dy[d];
      if(r<0||r>=N||r<0||c>=M) continue;
      if(field[r][c] == 0) continue;
      if(state[r][c].Y == 0){
        state[r][c] = {curtime+1, curcolor};
        q.push({r, c});
      }
      else if(state[r][c].Y == 2){
        if(curcolor == 1 && state[r][c].X == curtime+1){
          cnt++;
          state[r][c].Y = 3;
        }
      }
      else if(state[r][c].Y == 1){
        if(curcolor == 2 && state[r][c].X == curtime+1){
          cnt++;
          state[r][c].Y = 3;
        }        
      }
    }
  }
  return cnt;
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> G >> R;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> field[i][j];
            if(field[i][j]==2) niceSoil.push_back({i, j});
        }
    }
    CAND = niceSoil.size();
    fill(brute+CAND-G-R, brute+CAND-R, 1);
    fill(brute+CAND-R, brute+CAND, 2);
    int mx = 0;
    do {
        mx = max(mx, bfs());
    } while(next_permutation(brute, brute+CAND));
    cout << mx;
    return 0;
}