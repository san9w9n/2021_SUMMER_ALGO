#include <bits/stdc++.h>
using namespace std;
int N;
typedef struct {
    string name;
    int kor;
    int eng;
    int math;
} Student;
vector<Student> V;

bool cmp(Student& a, Student& b) {
    if(a.kor>b.kor) return true;
    if(a.kor==b.kor) {
        if(a.eng<b.eng) return true;
        if(a.eng==b.eng) {
            if(a.math>b.math) return true;
            if(a.math==b.math) return a.name <= b.name;
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--) {
        string s;
        int k, e, m;
        cin >> s >> k >> e >> m;
        V.push_back({s, k, e, m});
    }

    sort(V.begin(), V.end(), cmp);
    for(int i=0; i<V.size(); i++) cout << V[i].name << '\n';

    return 0;
}