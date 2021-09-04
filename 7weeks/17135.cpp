#include <bits/stdc++.h>
using namespace std;
int N, M, D;
int brute[17];
vector<int> Archur;
deque<deque<int>> Field;
deque<deque<int>> field;

void init() {
    Archur.clear();
    field.clear();
    for(int i=0; i<N; i++) field.push_front(Field[i]);
}

int dist(int Ac, int Er, int Ec) {
    return (N-Er)+abs(Ec-Ac);
}

void debug() {
    cout << "--------------------------\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cout << field[i][j] << ' ';
        cout << '\n';
    }
    bool dede[17] = {false, };
    for(int i=0; i<3; i++) {
        dede[Archur[i]] = true;
    }

    for(int i=0; i<M; i++) {
        if(dede[i]) cout << 5 << ' ';
        else cout << "  ";
    }
    cout << '\n';
}

int solve() {
    int time = 0;
    int ans=0;

    while(time<N) {
        int minD[3] = {(int)1e9, (int)1e9, (int)1e9};
        pair<int, int> pos[3];
        for(int i=N-1; i>=0; i--) {
            for(int j=0; j<M; j++) {
                if(field[i][j]==0) continue;
                for(int a=0; a<3; a++) {
                    int d = dist(Archur[a], i, j);
                    if(d>D) continue;
                    if(d<minD[a]) {
                        minD[a] = d;
                        pos[a].first = i;
                        pos[a].second = j;
                    } else if(d==minD[a]) {
                        if(j<pos[a].second) {
                            pos[a].first = i;
                            pos[a].second = j;
                        }
                    }
                }
            }
        }
        for(int a=0; a<3; a++) {
            if(minD[a]==1e9) continue;
            int x=pos[a].first, y=pos[a].second;
            if(field[x][y]==1) {
                field[x][y] = 0;
                ans++;
            }
        }
        field.push_front(deque<int>(M));
        field.pop_back();
        time++; 
    }
    return ans;
}



int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> D;
    for(int i=0; i<N; i++) {
        deque<int> input;
        int n;
        for(int j=0; j<M; j++) {
            cin >> n;
            input.push_back(n);
        }
        Field.push_front(input);
    }
    

    for(int i=3; i<M; i++) brute[i] = 1;
    int maxi = 0;
    do {
        init();
        for(int i=0; i<M; i++) if(!brute[i]) Archur.push_back(i);
        int b = solve();
        maxi = max(maxi, b);
    } while(next_permutation(brute, brute+M));

    cout << maxi;

    return 0;
}