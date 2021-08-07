#include <bits/stdc++.h>
using namespace std;
int N, K;
int room[12]; //0번 1학년 여자, 1번 1학년 남자

int main(void) {
    cin >> N >> K;
    fill(room, room+12, 0);
    while(N--) {
        int S, Y;
        cin >> S >> Y;
        room[2*(Y-1) + S]++;
    }
    int total=0;
    for(int i=0; i<12; i++) {
        total+=room[i]/K;
        total+=(room[i]%K>0) ? 1 : 0;
    }
    cout << total;
    return 0;
}