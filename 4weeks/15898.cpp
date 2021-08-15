#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, char> enchant[10][4][4];
bool used[10];
pair<pair<int,int>, int> selected[3]; //{{재료번호, 방향}, 좌표}
int ans;
pair<int, char> board[5][5];

int total() {
    int score[4] = {0, 0, 0, 0};
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            char c = board[i][j].second;
            int e = board[i][j].first;
            switch(c) {
                case 'R':
                    score[0]+=e;
                    break;
                case 'B':
                    score[1]+=e;
                    break;
                case 'G':
                    score[2]+=e;
                    break;
                case 'Y':
                    score[3]+=e;
                    break;
                default:
                    break;
            }
        }
    }
    return 7*score[0] + 5*score[1] + 3*score[2] + 2*score[3];
}   

void init() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            board[i][j].first = 0;
            board[i][j].second = 'W';
        }
    }
}

void Rotate(int n, int d, int x, int y) {
    if(d==0) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(enchant[n][i][j].second=='W') {
                    board[i+x][j+y].first += enchant[n][i][j].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                }
                else {
                    board[i+x][j+y].first += enchant[n][i][j].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                    board[i+x][j+y].second = enchant[n][i][j].second;
                }
            }
        }
    } else if(d==1) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(enchant[n][j][3-i].second=='W') {
                    board[i+x][j+y].first += enchant[n][j][3-i].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                }
                else {
                    board[i+x][j+y].first += enchant[n][j][3-i].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                    board[i+x][j+y].second = enchant[n][j][3-i].second;
                }
            }
        }
    } else if(d==2) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(enchant[n][3-i][3-j].second=='W') {
                    board[i+x][j+y].first += enchant[n][3-i][3-j].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                }
                else {
                    board[i+x][j+y].first += enchant[n][3-i][3-j].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                    board[i+x][j+y].second = enchant[n][3-i][3-j].second;
                }
            }
        }
    } else {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(enchant[n][3-j][i].second=='W') {
                    board[i+x][j+y].first += enchant[n][3-j][i].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                }
                else {
                    board[i+x][j+y].first += enchant[n][3-j][i].first;
                    if(board[i+x][j+y].first<0) board[i+x][j+y].first=0;
                    else if(board[i+x][j+y].first>9) board[i+x][j+y].first=9;
                    board[i+x][j+y].second = enchant[n][3-j][i].second;
                }
            }
        }
    }
}

void Enchant1() {
    init();
    for(int k=0; k<3; k++) {
        int n=selected[k].first.first, d=selected[k].first.second, pos=selected[k].second;
        int x=pos/2, y=pos%2;
        Rotate(n, d, x, y);
    }
    int t = total();
    if(ans<t) ans=t;
}

void btk3(int k) {
    if(k==3) {
        Enchant1();
        return;
    }
    for(int d=0; d<4; d++) {
        selected[k].second = d;
        btk3(k+1);
    }
}
void btk2(int k) {
    if(k==3) {
        btk3(0);
        return;
    }
    for(int d=0; d<4; d++) {
        selected[k].first.second = d;
        btk2(k+1);
    }
}
void btk1(int k) {
    if(k==3) {
        btk2(0);
        return;
    }
    for(int i=0; i<N; i++) {
        if(used[i]) continue;
        used[i] = true;
        selected[k].first.first = i;
        btk1(k+1);
        used[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int n=0; n<N; n++) {
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) cin >> enchant[n][i][j].first;
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) cin >> enchant[n][i][j].second;
    }
    btk1(0);
    cout << ans;
    return 0;
}