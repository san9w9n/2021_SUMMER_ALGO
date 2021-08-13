#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> arr[9];
bool broken[9];
int ans;

void collision(int a, int b) {
    arr[a].first -= arr[b].second;
    arr[b].first -= arr[a].second;
}

void timeback(int a, int b) {
    arr[a].first += arr[b].second;
    arr[b].first += arr[a].second;
}

void btk(int k, int cnt) {
    if(ans<cnt) ans=cnt;
    if(k>=N) {
        return;
    }
    if(broken[k]) {
        btk(k+1, cnt);
    } else {
        
        for(int i=0; i<N; i++) {
            bool tmpI, tmpK;
            int cntTmp = cnt;
            if(broken[i] || i==k) continue;
            tmpI = arr[i].first<=0;
            tmpK = arr[k].first<=0;

            collision(k, i);
            
            if(arr[i].first<=0) {
                cntTmp++;
                broken[i] = true;
            }
            if(arr[k].first<=0) {
                cntTmp++;
                broken[k] = true;
            }

            btk(k+1, cntTmp);

            timeback(k, i);
            broken[i] = tmpI;
            broken[k] = tmpK;
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    btk(0, 0);
    cout << ans;

    return 0;
}