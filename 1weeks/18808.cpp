#include <bits/stdc++.h>
using namespace std;
int N, M, K, r, c;
int notebook[42][42];
int sticker[12][12];


void rotate() {
    int tmp[12][12];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            tmp[i][j] = sticker[i][j];
    
    for(int i=0; i<c; i++)
        for(int j=0; j<r; j++)
            sticker[i][j] = tmp[r-1-j][i];
    swap(r, c);
}

bool paste(int x, int y) {
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(notebook[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
    
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(sticker[i][j]==1)
                notebook[x+i][y+j] = 1;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    while(K--) {
        cin >> r >> c;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin >> sticker[i][j];
        
        for(int d=0; d<4; d++) {
            bool pasted = false;
            for(int x=0; x<=N-r; x++) {
                if(pasted) break;
                for(int y=0; y<=M-c; y++) {
                    if(paste(x,y)) {
                        pasted = true;
                        break;
                    }
                }
            }
            if(pasted) break;
            rotate();
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            ans += notebook[i][j]; 
    cout << ans;

    return 0;
}