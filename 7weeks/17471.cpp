#include <bits/stdc++.h>
using namespace std;
int N, totalPeople, ans=INT32_MAX;

bool visited[52];
int people[52];
vector<int> graph[52];
vector<int> selected;

bool bfs() {
    bool used[52] = {false, };
    int idx, con = 1;
    queue<int> Q;
    
    for(int i=0; i<selected.size(); i++) used[selected[i]] = true;
    for(int i=0; i<N; i++) {
        if(used[i]) continue;
        idx = i;
        break;
    }

    Q.push(idx);
    used[idx] = true;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i=0; i<graph[x].size(); i++) {
            if(used[graph[x][i]]) continue;
            used[graph[x][i]] = true;
            con++;
            Q.push(graph[x][i]);
        }
    }
    if(N-selected.size()==con) return true;
    return false;
}

bool newbfs() {
    bool used[52];
    fill(used, used+52, true);
    int idx;
    queue<int> Q;
    if(selected.empty()) return false;

    for(int i=0; i<selected.size(); i++) used[selected[i]] = false;
    for(int i=0; i<N; i++) {
        if(used[i]) continue;
        idx = i;
        break;
    }

    Q.push(idx);
    used[idx] = true;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i=0; i<graph[x].size(); i++) {
            if(used[graph[x][i]]) continue;
            used[graph[x][i]] = true;
            Q.push(graph[x][i]);
        }
    }
    for(int i=0; i<N; i++) if(!used[i]) return false;
    return true;
}

void btk(int start, int cnt) {
    if(selected.size()==N) return;
    if(newbfs() && bfs()) {
        ans = min(ans, abs(cnt-(totalPeople-cnt)));
    }

    for(int i=start+1; i<N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        selected.push_back(i);
        btk(i, cnt+people[i]);
        selected.pop_back();
        visited[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> people[i];
        totalPeople+=people[i];
    }
    
    for(int i=0; i<N; i++) {
        int n, g;
        cin >> n;
        for(int j=0; j<n; j++) {
            cin >> g;
            graph[i].push_back(g-1);
            graph[g-1].push_back(i);
        }
    }

    for(int i=0; i<N; i++) {
        visited[i] = true;
        selected.push_back(i);
        btk(i, people[i]);
        selected.pop_back();
    }

    if(ans==INT32_MAX) cout << -1;
    else cout << ans;

    return 0;
}