#include <bits/stdc++.h>
using namespace std;
int N, M, zero=0, tv=0, mini = 100000000;
int CCTV[65][3];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int findZero(int **arr) {
    int zero = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j]==0) zero++;
        }
    }
    return zero;
}
// void printArr(int **arr) {
//     cout << "------------------\n";
//     for(int i=0; i<N; i++) {
//         for(int j=0; j<M; j++) {
//             cout << arr[i][j] << "\t";
//         }
//         cout << "\n";
//     }
// }

int** cctv(int i,int d, int r, int c, int** arr) {
    int nx, ny;
    int** tmp = new int*[N]();
    for(int i=0; i<N; i++) tmp[i] = new int[M]();
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) tmp[i][j] = arr[i][j];
    }
    
    if(i==0) {
        while(1) {
            nx = dx[d] + r;
            ny = dy[d] + c;
            if(nx<0 || nx>=N || ny<0 || ny>=M) break;
            if(tmp[nx][ny]==6) break;
            if(tmp[nx][ny]==0) tmp[nx][ny] = -1;
            r = nx;
            c = ny;
        }
    } else if(i==1) {
        tmp = cctv(0, d, r, c, tmp);
        tmp = cctv(0, (d+2)%4, r, c, tmp);
    } else if(i==2) {
        tmp = cctv(0, d, r, c, tmp);
        tmp = cctv(0, (d+1)%4, r, c, tmp);
    } else if(i==3) {
        tmp = cctv(0, d, r, c, tmp);
        tmp = cctv(1, (d+1)%4, r, c, tmp);
    } else {
        tmp = cctv(0, 0, r, c, tmp);
        tmp = cctv(0, 1, r, c, tmp);
        tmp = cctv(0, 2, r, c, tmp);
        tmp = cctv(0, 3, r, c, tmp);
    }
    return tmp;
}

void btk(int k, int** arr) {
    int** tmp;
    if(k==tv) {
        mini = min(mini, findZero(arr));
        return;
    }
    for(int d=0; d<4; d++) {
        tmp = cctv(CCTV[k][0]-1, d, CCTV[k][1], CCTV[k][2], arr);
        btk(k+1, tmp);
    }
}


int main(void) {
    cin >> N >> M;
    int** arr;
    arr = new int*[N]();
    for(int i=0; i<N; i++) arr[i] = new int[M]();

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j]==0) zero++;
            else if(arr[i][j]==6) continue;
            else{
                CCTV[tv][0] = arr[i][j];
                CCTV[tv][1] = i;
                CCTV[tv][2] = j;
                tv++;
            }
        }
    }
    btk(0, arr);
    cout << mini;
    return 0;
}