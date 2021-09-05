#include <bits/stdc++.h>
using namespace std;
int N, M, K, ans=INT32_MAX;
int MAP[53][53];

typedef struct {
    int r;
    int c;
    int s;
} Query;
vector<Query> query;
bool queryCheck[8];
vector<Query> realquery;

int rotateMAP() {
    int tmp[53][53], tmp2[53][53];
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) tmp[i][j] = MAP[i][j];
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) tmp2[i][j] = MAP[i][j];
    
    for(int i=0; i<realquery.size(); i++) {
        int r, c, s, tmps;
        r = realquery[i].r; c = realquery[i].c; s = realquery[i].s;
        while(s) {
            for(int j=c-s; j<c+s; j++) tmp[r-s][j+1] = tmp2[r-s][j];
            for(int i=r-s; i<r+s; i++) tmp[i+1][c+s] = tmp2[i][c+s];
            for(int j=c+s; j>c-s; j--) tmp[r+s][j-1] = tmp2[r+s][j];
            for(int i=r+s; i>r-s; i--) tmp[i-1][c-s] = tmp2[i][c-s];
            s--;
        }
        for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) tmp2[i][j] = tmp[i][j];
    }

    int mini = INT32_MAX;
    for(int i=1; i<=N; i++) {
        int total = 0;
        for(int j=1; j<=M; j++) total+=tmp[i][j];
        if(mini>total) mini = total;
    }

    return mini;
}

void QueryBtk(int k) {
    if(k==K) {
        ans = min(ans,rotateMAP());
        return;
    }
    for(int i=0; i<K; i++) {
        if(queryCheck[i]) continue;
        queryCheck[i] = true;
        realquery.push_back(query[i]);
        QueryBtk(k+1);
        queryCheck[i] = false;
        realquery.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin >> MAP[i][j];
    for(int i=0; i<K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        query.push_back({r, c, s});
    }

    QueryBtk(0);
    cout << ans;

    return 0;
}