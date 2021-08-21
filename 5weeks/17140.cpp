#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int N, M, maxN, maxM;
int R, C, K;
int counting[101];
int arr[101][101];

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.S>p2.S) return false;
    else if(p1.S==p2.S) {
        if(p1.F>p2.F) return false;
        else return true;
    } 
    else return true;
}

void RcountRet(int r) {
    vector<pair<int,int>> countV;
    for(int i=1; i<101; i++) {
        if(counting[i]<=0) continue;
        countV.push_back({i, counting[i]});
    }
    sort(countV.begin(), countV.end(), compare);
    int s = countV.size()*2;
    if(s>=100) maxM=100;
    else maxM = max(maxM, s);

    int cnt=0;
    for(int i=0; i<countV.size(); i++) {
        arr[r][cnt] = countV[i].F;
        cnt++;
        if(cnt>=100) break;
        arr[r][cnt] = countV[i].S;
        cnt++;
        if(cnt>=100) break;
    }
    for(int i=cnt; i<100; i++) arr[r][i]=0;
}

void CcountRet(int c) {
    vector<pair<int,int>> countV;
    for(int i=1; i<101; i++) {
        if(counting[i]<=0) continue;
        countV.push_back({i, counting[i]});
    }
    sort(countV.begin(), countV.end(), compare);
    int s = countV.size()*2;
    if(s>=100) maxN=100;
    else maxN = max(maxN, s);

    int cnt=0;
    for(int i=0; i<countV.size(); i++) {
        arr[cnt][c] = countV[i].F;
        cnt++;
        if(cnt>=100) break;
        arr[cnt][c] = countV[i].S;
        cnt++;
        if(cnt>=100) break;
    }
    for(int i=cnt; i<100; i++) arr[i][c] = 0;
}

void Rcal() {
    for(int i=0; i<N; i++) {
        fill(counting, counting+101, 0);
        for(int j=0; j<M; j++) counting[arr[i][j]]++;
        RcountRet(i);
    }
    M = maxM;
}

void Ccal() {
    for(int j=0; j<M; j++) {
        fill(counting, counting+101, 0);
        for(int i=0; i<N; i++) counting[arr[i][j]]++;
        CcountRet(j);
    }
    N = maxN;
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    N=3; M=3; 
    maxN=N; maxM=M;

    cin >> R >> C >> K;
    R--; C--;

    for(int i=0; i<N; i++) for(int j=0; j<M; j++)  cin >> arr[i][j];
    int idx=0;
    while(arr[R][C]!=K && idx<=100) {
        if(N>=M) Rcal();
        else Ccal();
        idx++;
    }

    if(arr[R][C]==K) cout << idx;
    else cout << -1;
    return 0;
}