#include <bits/stdc++.h>
using namespace std;
int N, K;
pair<int, bool> belt[400];
deque<int> robot;

bool checkAns() {
    int check=0;
    for(int i=0; i<2*N; i++) {
        if(belt[i].first==0) check++;
        if(check>=K) return true;
    }
    if(check>=K) return true;
    return false;
}

void makeRobot() {
    if(belt[0].first==0 || belt[0].second) return;
    belt[0].first--; 
    belt[0].second = true;
    robot.push_back(0); // 현재 위치와 아직 벨트에 있는지.
}

void moveRobot() {
    int size = robot.size();
    while(size--) {
        int cur = robot.front();
        int nextPos = (robot.front()+1)%(2*N);
        robot.pop_front();
        if(belt[nextPos].first==0 || belt[nextPos].second) {
            robot.push_back(cur);
        } else {
            belt[cur].second = false;
            if(nextPos==N-1) {
                belt[N-1].first--;
                belt[nextPos].second = false;
            } else {
                belt[nextPos].first--;
                belt[nextPos].second = true;
                robot.push_back(nextPos);
            }
        }
        
    }
}

void moveBelt() {
    int tmp1 = belt[2*N-1].first;
    bool tmp2 = belt[2*N-1].second;
    for(int i=2*N-1; i>0; i--) {
        belt[i].first = belt[i-1].first;
        belt[i].second = belt[i-1].second;
    }
    belt[0].first = tmp1;
    belt[0].second = tmp2;

    int size = robot.size();
    while(size--) {
        int next = (robot.front()+1)%(2*N);
        robot.pop_front();
        if(next!=N-1) {
            robot.push_back(next);
        } else {
            belt[N-1].second = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0; i<2*N; i++) {
        cin >> belt[i].first;
        belt[i].second = false;
    }
    
    int ans = 1;
    while(1) {
        moveBelt();
        moveRobot();
        makeRobot();
        if(checkAns()) break;
        ans++;
    }

    cout << ans;
    
    return 0;
}