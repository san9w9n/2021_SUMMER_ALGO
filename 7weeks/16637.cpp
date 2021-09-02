#include <bits/stdc++.h>
using namespace std;
int N, idx, ans=INT32_MIN;
string S;
pair<int,int> arr[500];
bool visited[500];
vector<int> order;

int Cal(deque<char>& V) {
    int a, b, op;
    deque<int> tmpNum;
    deque<char> tmpOp;
    while(!V.empty()) {
        int val = 0;
        if(V.front()=='(') {
            V.pop_front();
            a = V.front()-'0'; V.pop_front();
            op = V.front(); V.pop_front();
            b = V.front()-'0'; V.pop_front(); V.pop_front();

            if(op=='+') val = a+b;
            else if(op=='-') val = a-b;
            else val = a*b;

            tmpNum.push_back(val);
        } else {
            if(V.front()-'0'<0 || V.front()-'0'>10) {
                tmpOp.push_back(V.front());
                V.pop_front();
            } else {
                tmpNum.push_back(V.front()-'0');
                V.pop_front();
            }
        }
    }

    if(tmpNum.empty()) return 0;
    int total = tmpNum[0];
    for(int i=1; i<tmpNum.size(); i++) {
        if(tmpOp[i-1]=='+') total += tmpNum[i];
        else if(tmpOp[i-1]=='-') total -= tmpNum[i];
        else total*=tmpNum[i];
    }
    return total;
}

int makeStack() {
    bool check[500] = {false, };
    deque<char> V;
    for(int i=0; i<order.size(); i++) {
        check[arr[order[i]].first] = true;
        check[arr[order[i]].second] = true;
    }

    bool odd = false;
    for(int i=0; i<N; i++) {
        if(check[i]) {
            if(!odd) {
                V.push_back('(');
                odd = true;
            } else {
                V.push_back(')');
                odd = false;
            }
        }
        V.push_back(S[i]);
    }
    if(odd) V.push_back(')');


    // for(int i=0; i<V.size(); i++) cout << V[i];
    // cout << '\n';

    return Cal(V);
}

void btk() {
    for(int i=0; i<=idx; i++) {
        if(visited[i]) continue;
        for(int j=0; j<=idx && j<=i+1; j++) visited[j] = true;
        order.push_back(i);
        btk();
        order.pop_back();
        for(int j=0; j<=idx && j<=i+1; j++) visited[j] = false;
    }
    ans = max(ans,makeStack());

}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin >> S;
    if(N==1) {
        cout << S[0] - '0';
        return 0;
    }
    while(1) {
        arr[idx] = {idx*2,idx*2+3};
        if(idx*2+3==N) break;
        idx++;
    }
    btk();


    cout << ans;
    return 0;
}