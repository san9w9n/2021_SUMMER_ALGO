#include <bits/stdc++.h>
using namespace std;
int N, maxi=-1;

//0, 1, 2, 3 : 동, 남, 서, 북
int** move(int d, int** arr) {
    int** tmp = new int*[N]();
    for(int i=0; i<N; i++) tmp[i] = new int[N]();
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) tmp[i][j] = arr[i][j];
    }

    if(d==0) { //동쪽으로 이동
        for(int k=0; k<N; k++) {
            for(int i=0; i<N; i++) {
                for(int j=N-1; j>0; j--) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i][j-1];
                    tmp[i][j-1] = 0;
                }
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=N-1; j>0; j--) {
                if(tmp[i][j]==tmp[i][j-1]) {
                    tmp[i][j] *= 2;
                    tmp[i][j-1] = 0;
                }
            }
        }
        for(int k=0; k<N; k++) {
            for(int i=0; i<N; i++) {
                for(int j=N-1; j>0; j--) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i][j-1];
                    tmp[i][j-1] = 0;
                }
            }
        }
    } else if(d==1) {
        for(int k=0; k<N; k++) {
            for(int j=0; j<N; j++) {
                for(int i=N-1; i>0; i--) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i-1][j];
                    tmp[i-1][j] = 0;
                }
            }
        }
        for(int j=0; j<N; j++) {
            for(int i=N-1; i>0; i--) {
                if(tmp[i][j]==tmp[i-1][j]) {
                    tmp[i][j] *= 2;
                    tmp[i-1][j] = 0;
                }
            }
        }
        for(int k=0; k<N; k++) {
            for(int j=0; j<N; j++) {
                for(int i=N-1; i>0; i--) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i-1][j];
                    tmp[i-1][j] = 0;
                }
            }
        }
    } else if(d==2) {
        for(int k=0; k<N; k++) {
            for(int i=0; i<N; i++) {
                for(int j=0; j<N-1; j++) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i][j+1];
                    tmp[i][j+1] = 0;
                }
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N-1; j++) {
                if(tmp[i][j]==tmp[i][j+1]) {
                    tmp[i][j] *= 2;
                    tmp[i][j+1] = 0;
                }
            }
        }
        for(int k=0; k<N; k++) {
            for(int i=0; i<N; i++) {
                for(int j=0; j<N-1; j++) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i][j+1];
                    tmp[i][j+1] = 0;
                }
            }
        }
    } else {
        for(int k=0; k<N; k++) {
            for(int j=0; j<N; j++) {
                for(int i=0; i<N-1; i++) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i+1][j];
                    tmp[i+1][j] = 0;
                }
            }
        }
        for(int j=0; j<N; j++) {
            for(int i=0; i<N-1; i++) {
                if(tmp[i][j]==tmp[i+1][j]) {
                    tmp[i][j] *= 2;
                    tmp[i+1][j] = 0;
                }
            }
        }
        for(int k=0; k<N; k++) {
            for(int j=0; j<N; j++) {
                for(int i=0; i<N-1; i++) {
                    if(tmp[i][j]!=0) continue;
                    tmp[i][j] = tmp[i+1][j];
                    tmp[i+1][j] = 0;
                }
            }
        }
    }
    return tmp;
}

void btk(int k, int** arr) {
    if(k==5) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(arr[i][j]>maxi) maxi = arr[i][j];
            }
        }
        return;
    }
    for(int i=0; i<4; i++) {
        btk(k+1,move(i, arr));
    }
}


int main(void) {
    cin >> N;
    int** arr = new int*[N]();
    for(int i=0; i<N; i++) arr[i] = new int[N]();
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }
    
    btk(0, arr);
    cout << maxi;

    return 0;
}