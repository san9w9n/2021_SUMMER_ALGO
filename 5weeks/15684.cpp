#include <bits/stdc++.h>
using namespace std;
int M, bar, N, ans=1e9;
bool rail[33][33];
vector<pair<int, int>> debug;

bool checkGame() {
    for(int c=1; c<=M; c++) {
        int i=1, j=c;
        while(i<=N) {
            if(rail[i][j]) j++;
            else if(rail[i][j-1]) j--;
            i++;
        }
        if(j!=c) return false;
    }
    return true;
}
void printDebug() {
    cout << "----------------------------\n";
    for(int i=0; i<debug.size(); i++) cout << debug[i].first << "," << debug[i].second << "        ";
    cout << '\n';
}
void btk(int r, int cnt) {
    if(cnt>3) return;
    printDebug();
    if(cnt!=0) {
        if(checkGame()) {
            if(ans>cnt) ans= cnt;
        }
    }
    for(int i=r; i<=N; i++) {
        for(int c=1; c<M; c++) {
            if(!rail[i][c-1] && !rail[i][c] && !rail[i][c+1]) {
                debug.push_back({i,c});
                rail[i][c] = true;
                btk(i, cnt+1);
                debug.pop_back();
                rail[i][c] = false;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> bar >> N;
    while(bar--) {
        int a, b;
        cin >> a >> b;
        rail[a][b]=true; // b, b+1 를 잇는 a번째줄의 선 추가
    }
    if(checkGame()) {
        cout << 0;
    } else {
        btk(1, 0);
        if(ans>3) cout << -1;
        else cout << ans;
    }
    return 0;
}