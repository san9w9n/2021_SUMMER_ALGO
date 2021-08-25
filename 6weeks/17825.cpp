#include <bits/stdc++.h>
using namespace std;
int dice[10], ans;
int Road[4][22], arrived; 
pair<int, int> arr[4];

void dfs(int k, int score) {
    int road, x, r;
    if(k>=10) {
        ans = max(ans, score);
        return;
    }

    for(int mal=0; mal<4; mal++) {
        x = arr[mal].first; road = arr[mal].second; 
        r = x+dice[k];
        if(x==22) continue;
        
        if(road==0) {
            if(r>=21) {
                arr[mal].first = 22;
                Road[road][x] = 0;
                dfs(k+1, score);
                Road[road][x] = 1;
                arr[mal].first = x;
            } else if(r==5||r==10||r==15) {
                if(Road[r/5][0]==0) {
                    Road[r/5][0] = Road[0][r] = 1;
                    Road[road][x] = 0;
                    arr[mal].first = 0;
                    arr[mal].second = r/5;
                    dfs(k+1, score+r*2);
                    arr[mal].first = x;
                    arr[mal].second = road;
                    Road[road][x] = 1;
                    Road[r/5][0] = Road[0][r] = 0;
                }
            } else if(r==20) {
                if(Road[road][r]==0) {
                    Road[1][7] = Road[2][6] = Road[3][7] = 1;
                    Road[0][20] = 1;
                    Road[road][x] = 0;
                    arr[mal].first = r;

                    dfs(k+1, score+40);

                    arr[mal].first = x;
                    Road[road][x] = 1;
                    Road[0][20] = 0;
                    Road[1][7] = Road[2][6] = Road[3][7] = 0;
                }
            } else {
                if(Road[road][r]==0) {
                    Road[road][r] = 1; Road[road][x] = 0;
                    arr[mal].first = r;
                    dfs(k+1, score+r*2);
                    arr[mal].first = x;
                    Road[road][r] = 0; Road[road][x] = 1;
                }
            }
        } else if(road==1) {
            if(x==0) Road[0][5] = 0;
            else if(x>=4 && x<=6) Road[2][x-1] = Road[3][x] = 0;
            else if(x==7) Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 0;
            Road[1][x] = 0;
            arr[mal].first = r;
            
            if(r>=8) {
                arr[mal].first = 22;
                dfs(k+1, score);
                arr[mal].first = x;
            } else if(r==7) {
                if(Road[road][r]==0) {
                    Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 1;
                    dfs(k+1, score+40);
                    Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 0;
                }
            } else if (r>=4) {
                if(Road[road][r]==0) {
                    Road[1][r] = Road[2][r-1] = Road[3][r] = 1;
                    int SCORE[8] = {10, 13, 16, 19, 25, 30, 35, 40};
                    dfs(k+1, score + SCORE[r]);
                    Road[1][r] = Road[2][r-1] = Road[3][r] = 0;
                }
            } else {
                if(Road[road][r]==0) {
                    Road[1][r] = 1;
                    int SCORE[8] = {10, 13, 16, 19, 25, 30, 35, 40};
                    dfs(k+1, score+SCORE[r]);
                    Road[1][r] = 0;
                }
            }

            arr[mal].first = x;
            if(x==0) Road[0][5] = 1;
            else if(x>=4 && x<=6) Road[2][x-1] = Road[3][x] = 1;
            else if(x==7) Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 1;
            Road[1][x] = 1;
        } else if(road==2) {
            if(x==0) Road[0][10] = 0;
            else if(x>=3 && x<=5) Road[1][x+1] = Road[3][x+1] = 0;
            else if(x==6) Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 0;
            Road[2][x] = 0;
            arr[mal].first = r;

            if(r>=7) {
                arr[mal].first = 22;
                dfs(k+1, score);
                arr[mal].first = x;
            } else if(r==6) {
                if(Road[road][r]==0) {
                    Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 1;
                    dfs(k+1, score+40);
                    Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 0;
                }
            } else if (r>=3) {
                if(Road[road][r]==0) {
                    Road[1][r+1] = Road[2][r] = Road[3][r+1] = 1;
                    int SCORE[7] = {20, 22, 24, 25, 30, 35, 40};
                    dfs(k+1, score + SCORE[r]);
                    Road[1][r+1] = Road[2][r] = Road[3][r+1] = 0;
                }
            } else {
                if(Road[road][r]==0) {
                    Road[2][r] = 1;
                    int SCORE[7] = {20, 22, 24, 25, 30, 35, 40};
                    dfs(k+1, score+SCORE[r]);
                    Road[2][r] = 0;
                }
            }

            arr[mal].first = x;
            if(x==0) Road[0][10] = 1;
            else if(x>=3 && x<=5) Road[1][x+1] = Road[3][x+1] = 1;
            else if(x==6) Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 1;
            Road[2][x] = 1;
        } else {
            if(x==0) Road[0][15] = 0;
            else if(x>=4 && x<=6) Road[2][x-1] = Road[1][x] = 0;
            else if(x==7) Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 0;
            Road[3][x] = 0;
            arr[mal].first = r;

            if(r>=8) {   
                arr[mal].first = 22;
                dfs(k+1, score);
                arr[mal].first = x;
            } else if(r==7) {
                if(Road[road][r]==0) {
                    Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 1;
                    dfs(k+1, score+40);
                    Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 0;
                }
            } else if (r>=4) {
                if(Road[road][r]==0) {
                    Road[1][r] = Road[2][r-1] = Road[3][r] = 1;
                    int SCORE[8] = {30, 28, 27, 26, 25, 30, 35, 40};
                    dfs(k+1, score + SCORE[r]);
                    Road[1][r] = Road[2][r-1] = Road[3][r] = 0;
                }
            } else {
                if(Road[road][r]==0) {
                    Road[3][r] = 1;
                    int SCORE[8] = {30, 28, 27, 26, 25, 30, 35, 40};
                    dfs(k+1, score+SCORE[r]);
                    Road[3][r] = 0;
                }
            }
            arr[mal].first = x;
            if(x==0) Road[0][15] = 1;
            else if(x>=4 && x<=6) Road[2][x-1] = Road[1][x] = 1;
            else if(x==7) Road[0][20] = Road[3][7] = Road[1][7] = Road[2][6] = 1;
            Road[3][x] = 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<10; i++) cin >> dice[i];
    dfs(0, 0);
    cout << ans;
    return 0;
}