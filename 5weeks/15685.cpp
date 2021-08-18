#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N, cnt, ans;
vector<int> curveD[22];
vector<pair<int, int>> dragon[22];
int dx[4]={0,-1,0,1}, dy[4]={1,0,-1,0}; //동, 북, 서, 남
bool edge[105][105];

void makeDragon(int x, int y) {
    edge[x][y] = true;
    for(int i=0; i<curveD[cnt].size(); i++) {
        x+=dx[curveD[cnt][i]];
        y+=dy[curveD[cnt][i]];
        edge[x][y] = true;
    }
}

void findSquare() {
    for(int i=0; i<102; i++) {
        for(int j=0; j<102; j++) {
            if(edge[i][j] && edge[i][j+1] && edge[i+1][j] && edge[i+1][j+1]) ans++;
        }
    }
}

void makeD(int d, int g) {
    curveD[cnt].push_back(d);
    while(g--) {
        int posSize = curveD[cnt].size();
        for(int i=posSize-1; i>=0; i--) curveD[cnt].push_back((curveD[cnt][i]+1)%4);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        makeD(d, g);
        makeDragon(x, y);
        cnt++;
    }
    findSquare();
    cout << ans;
    return 0;
}