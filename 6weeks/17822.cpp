#include <bits/stdc++.h>
using namespace std;
int N, M, T;
int circle[52][52];
tuple<int, int, int> query[51];
int startPoint[51];

int prevIndex(int idx) {
    return (idx+M-1)%M;
}

int nextIndex(int idx) {
    return (idx+1)%M;
}

void reDraw() {
    double total=0, div=0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            if(circle[i][j]==0) continue;
            total+=circle[i][j];
            div++;
        }
    }

    double avg;
    if(div!=0) {
        avg = (total/div);

        for(int i=1; i<=N; i++) {
            for(int j=0; j<M; j++) {
                if(circle[i][j]==0 || circle[i][j]==avg) continue;
                if(circle[i][j]>avg) circle[i][j]--;
                else circle[i][j]++;
            }
        }
    }
}


void debug() {
    cout << "---------------------\n";
    for(int i=1; i<=N; i++) {
        int j = startPoint[i], loop = M;
        while(loop--) {
            cout << circle[i][j] << ' ';
            j = nextIndex(j);
        }
        cout << "\n";
    }
}

int bfs(int nx, int ny) {
    int x, y, r, c;
    int num = circle[nx][ny];
    queue<pair<int, int>> Q;
    circle[nx][ny] = 0;
    Q.push({nx, ny});




    int cnt = 0;
    while(!Q.empty()) {
        x = Q.front().first; y = Q.front().second;
        Q.pop();
        int j = startPoint[x], loop = M, idx=0;
        while(loop--) {
            if(j==y) break;
            j = nextIndex(j);
            idx++;
        }
        int newIdx=0, newJ1=0, newJ2=0;
        if(x+1<=N) {
            j = startPoint[x+1];
            loop = M;
            while(loop--) {
                if(idx==newIdx) {
                    newJ1 = j;
                    break;
                }
                j = nextIndex(j);
                newIdx++;
            }   
        }
        if(x-1>0) {
            j = startPoint[x-1];
            loop = M;
            newIdx=0;
            while(loop--) {
                if(idx==newIdx) {
                    newJ2 = j;
                    break;
                }
                j = nextIndex(j);
                newIdx++;
            }
        }
        pair<int, int> arr[4] = {{x+1,newJ1}, {x-1,newJ2}, {x,nextIndex(y)}, {x,prevIndex(y)}};
        for(int d=0; d<4; d++) {
            r=arr[d].first; c=arr[d].second;
            if(r<1 || r>N || circle[r][c]!=num) continue;
            circle[r][c] = 0;
            Q.push({r, c});
            cnt++;
        }
    }
    if(cnt==0) circle[nx][ny] = num;
    return cnt;
}

void printAns() {
    int total=0;
    for(int i=1; i<=N; i++) for(int j=0; j<M; j++) total+=circle[i][j];
    cout << total;
}

void rotateCircle(int idx, int cnt, int d) { //시계방향
    if(d==0) startPoint[idx] = (startPoint[idx]+(M-cnt))%M;
    else startPoint[idx] = (startPoint[idx]+cnt)%M;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    for(int i=1; i<=N; i++) for(int j=0; j<M; j++) cin >> circle[i][j];
    // debug();
    for(int t=0; t<T; t++) {
        
        int x, d, k;
        cin >> x >> d >> k;
        for(int i=x; i<=N; i+=x) rotateCircle(i, k, d);
        // debug();
        int flag = 0;

        for(int i=1; i<=N; i++) {
            int j = startPoint[i], loop = M;
            while(loop--) {
                if(circle[i][j]!=0) {
                    flag += bfs(i, j);
                }
                j = nextIndex(j);
            }
        }
        if(flag==0) reDraw();
        // debug();
    }
    printAns();

    return 0;

}