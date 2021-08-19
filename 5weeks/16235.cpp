#include <bits/stdc++.h>
using namespace std;
int N, M, YEAR;
int soil[12][12];
int A[12][12];
int dx[8]={1,0,-1,0,1,1,-1,-1}, dy[8]={0,1,0,-1,1,-1,1,-1};
deque<int> tree[12][12];

void springAndsummer() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int s = tree[i][j].size();
            int last=0;
            for(int k=1; k<=s; k++) {
                if(soil[i][j]<tree[i][j][k-1]) break;
                last = k;
                soil[i][j]-=tree[i][j][k-1];
                tree[i][j][k-1]++;
            }
            for(int k=s-1; k>=last; k--) {
                soil[i][j]+=tree[i][j][k]/2;
                tree[i][j].pop_back();
            }
        }
    }
}

void newTree(int x, int y, int cnt) {
    int r, c, jump;
    
    for(int d=0; d<8; d++) {
        r=x+dx[d]; c=y+dy[d];
        if(r<1||c<1||r>N||c>N) continue;
        for(int i=0; i<cnt; i++) tree[r][c].push_front(1);
    }
}

void fall() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int cnt=0;
            for(int k=0; k<tree[i][j].size(); k++) if(tree[i][j][k]%5==0) cnt++;
            if(cnt==0) continue;
            newTree(i, j, cnt);
        }
    }
}

void winter() {
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) soil[i][j]+=A[i][j];
}

void printAns() {
    int ans=0;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) ans+= tree[i][j].size();
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> YEAR;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) soil[i][j]=5;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> A[i][j];
    while(M--) {
        int x, y, val;
        cin >> x >> y >> val;
        tree[x][y].push_back(val);
    }
    
    while(YEAR--) {
        springAndsummer();
        fall();
        winter();
    }
    printAns();
    return 0;
}