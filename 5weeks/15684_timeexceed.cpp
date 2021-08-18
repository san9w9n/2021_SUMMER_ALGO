#include <bits/stdc++.h>
using namespace std;
int M, bar, N, ans=1e9;
bool rail[33][33];
vector<pair<int, int>> debug;
int used(int r, int c) { //false 반환 시 설치 가능
    if(c==1) {
        if(rail[r][c]) return 2; 
        if(rail[r][c+1]) return 3;
    } else if(c>1 && c<M-1) {
        if(rail[r][c]) return 2;
        if(rail[r][c-1]) return 1;
        if(rail[r][c+1]) return 3;
    } else if(c==M-1) {
        if(rail[r][c]) return 2;
        if(rail[r][c-1]) return 1;
    }
    return 0;

}

bool moveOne(int startM, int n, int m) {
    if(n>N) return (startM==m);
    int nextM=m;
    if(m==1) {
        if(rail[n][m]) nextM=m+1;
    } else if(m>1 && m<M) {
        if(rail[n][m-1]) nextM=m-1;
        if(rail[n][m]) nextM=m+1;
    } else if(m==M) {
        if(rail[n][m-1]) nextM=m-1;
    }
    return moveOne(startM, n+1, nextM);
}

bool moveAll() { //true면 성공적으로 됐다는 뜻.
    bool check = true;
    for(int m=1; m<M; m++) {
        check = moveOne(m, 1, m);
        if(!check) break;
    }
    return check;
}
void printDebug() {
    cout << "----------------------------\n";
    for(int i=0; i<debug.size(); i++) cout << debug[i].first << "," << debug[i].second << "        ";
    cout << '\n';
}
void btk(int r, int c, int cnt) {
    if(cnt>3) return;
    printDebug();
    if(cnt!=0) {
        if(moveAll()) {
            if(ans>cnt) ans= cnt;
        }
    }
    
    if(c>=M) {
        r++;
        if(r>N) return;
        c=0;
    }
    int move = used(r,c);
    
    if(move==0) {
        debug.push_back({r,c});
        rail[r][c] = true;
        btk(r, c+2, cnt+1);
        rail[r][c] = false;
        debug.pop_back();
        btk(r, c+1, cnt);
    } else if(move==1) {
        btk(r, c+1, cnt);
    } else if(move==2) {
        btk(r, c+2, cnt);
    } else {
        btk(r, c+3, cnt);
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
    if(moveAll()) {
        cout << 0;
    } else {
        btk(1, 1, 0);
        if(ans>3) cout << -1;
        else cout << ans;
    }
    return 0;
}