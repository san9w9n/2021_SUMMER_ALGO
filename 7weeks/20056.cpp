#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int dx[8]={-1,-1,0,1,1,1,0,-1}, dy[8]={0,1,1,1,0,-1,-1,-1};

typedef struct {
    int R;
    int C;
    int M;
    int S;
    int D;
} Fireball;

deque<Fireball> F;
deque<Fireball> MAP[52][52];
int T_Dir[] = { 0, 2, 4, 6 };
int F_Dir[] = { 1, 3, 5 ,7 };

void init() {
    for(int i=0; i<52; i++) {
        for(int j=0; j<52; j++) {
            MAP[i][j].clear();
        }
    }
}
void mergeFire() {
    deque<Fireball> Temp;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (MAP[i][j].size() == 0)continue;
            if (MAP[i][j].size() == 1)
            {
                Temp.push_back(MAP[i][j][0]);
                continue;
            }
            
            int Massive_Sum = 0;
            int Speed_Sum = 0;
            int Cnt = MAP[i][j].size();
 
            bool Even = true;
            bool Odd = true;
            for (int k = 0; k < MAP[i][j].size(); k++)
            {
                Massive_Sum += MAP[i][j][k].M;
                Speed_Sum += MAP[i][j][k].S;
                if (MAP[i][j][k].D % 2 == 0) Odd = false;
                else Even = false;
            }
            
            int Mass = Massive_Sum / 5;
            int Speed = Speed_Sum / Cnt;
            if (Mass == 0) continue;
            if (Even == true || Odd == true)
            {
                for (int k = 0; k < 4; k++)    Temp.push_back({ i, j, Mass, Speed, T_Dir[k] });
            }
            else
            {
                for (int k = 0; k < 4; k++) Temp.push_back({ i, j, Mass, Speed, F_Dir[k] });
            }
        }
    }
    F = Temp;
}

void bfs() {
    int x, y, r, c, d, m, s;
    init();

    int Size = F.size();
    while(Size--) {
        x = F.front().R; y = F.front().C;
        d = F.front().D; m = F.front().M; s = F.front().S;
        F.pop_front();
        int Move = s % N;
        r=x+dx[d]*Move; c=y+dy[d]*Move;
        if (r>N) r-=N;
        if (c>N) c-=N;
        if (r<1) r+=N;
        if (c<1) c+=N;

        MAP[r][c].push_back({r, c, m, s, d});
    }
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        F.push_back({r, c, m, s, d});
        MAP[r][c].push_back({r, c, m, s, d});
    }
    while(K--) {
        bfs();
        mergeFire();
    }
    int ans = 0;
    for(int k=0; k<F.size(); k++) ans+=F[k].M;
    cout << ans;

    return 0;
}