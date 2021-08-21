#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N, M, T;
int space[52][52];
deque<pair<int,int>> dust;
int Ux=-1, Uy=-1, Dx, Dy;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

void debug() {
    cout << "---------------------\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cout << space[i][j] << ' ';
        cout << '\n';
    }
}

void reQueue() {
    dust.clear();
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(space[i][j]>0) dust.push_back({i, j});
        }
    }
}
void machine() {
    for(int i=Ux-2; i>=0; i--) space[i+1][0]=space[i][0];
    for(int j=1; j<M; j++) space[0][j-1] = space[0][j];
    for(int i=1; i<=Ux; i++) space[i-1][M-1] = space[i][M-1];
    for(int j=M-2; j>=1; j--) space[Ux][j+1] = space[Ux][j];
    if(1<M) space[Ux][1] = 0;

    for(int i=Dx+2; i<N; i++) space[i-1][0]=space[i][0];
    for(int j=1; j<M; j++) space[N-1][j-1] = space[N-1][j];
    for(int i=N-2; i>=Dx; i--) space[i+1][M-1] = space[i][M-1];
    for(int j=M-2; j>=1; j--) space[Dx][j+1] = space[Dx][j];
    if(1<M) space[Dx][1] = 0;
}

void bfs() {
    int x, y, r, c;
    int dustArr[52][52];
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) dustArr[i][j]=0;
    
    int size = dust.size();

    while(size--) {
        x=dust.front().X; y=dust.front().Y;
        dust.pop_front();
        int D=0;
        for(int d=0; d<4; d++) {
            r=x+dx[d]; c=y+dy[d];
            if(r<0||c<0||r>=N||c>=M||space[r][c]==-1) continue;
            dustArr[r][c]+=space[x][y]/5;
            D++;
        }
        dustArr[x][y]+=space[x][y]-(space[x][y]/5)*D;
    }
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) space[i][j] = dustArr[i][j];
    space[Ux][Uy]=-1; space[Dx][Dy]=-1;
    machine();
    
    reQueue();
}



void printAns() {
    int total=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(space[i][j]==0 || space[i][j]==-1) continue;
            total+=space[i][j];
        }
    }
    cout << total;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin >> N >> M >> T;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> space[i][j];
            if(space[i][j]==0) continue;
            if(space[i][j]>0) dust.push_back({i,j});
            if(space[i][j]==-1) {
                if(Ux==-1 && Uy==-1) {
                    Ux=i; Uy=j;
                } else {
                    Dx=i; Dy=j;
                }
            }
        }
    }

    while(T--) bfs();

    printAns();
    return 0;
}