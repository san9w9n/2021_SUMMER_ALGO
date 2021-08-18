#include <bits/stdc++.h>
using namespace std;
int N;
int brute[8] = {0, 1, 2, 4, 5, 6, 7, 8};
vector<int> order;
int baseball[52][9];
int ans;
int one, two, three, home;

void oneBat() {
    home+=three;
    three=two; two=one; one=1;
}
void twoBat() {
    home+=two+three;
    two=1; three=one; one=0;
}
void threeBat() {
    home+=two+one+three;
    one=0; two=0; three=1;
}
void homerun() {
    home+=one+two+three+1;
    one=0; two=0; three=0;
}
void makeOrder() {
    for(int i=0; i<3; i++) order.push_back(brute[i]);
    order.push_back(3);
    for(int i=3; i<8; i++) order.push_back(brute[i]);
}

void play() {
    int last=0;
    for(int i=0; i<N; i++) {
        int out=0, player=0;
        while(1) {
            int n = baseball[i][order[last]];
            if(n==0) out++;
            else if(n==1) oneBat();
            else if(n==2) twoBat();
            else if(n==3) threeBat();
            else homerun();
            last=(last+1)%9;
            player++;
            if(out==3) break;
            if(player==9 && out<3) player=0;
        }
        one=0; two=0; three=0;
    }
    if(ans<home) ans=home;
    home=0;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<9; j++) {
            if(j==0) cin >> baseball[i][3];
            else if(j==3) cin >> baseball[i][0];
            else cin >> baseball[i][j];
        }
    }

    do {
        makeOrder();
        play();
        order.clear();
    } while (next_permutation(brute, brute+8));
    cout << ans;
    

    return 0;
}