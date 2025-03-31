#include<bits/stdc++.h>
using namespace std;

int n,k;
int now = 0;
struct customer {
    int id;
    int time;
    int counter;
};
vector<int> ex;
struct cmp {
    bool operator()(const customer& a, const customer& b) const {
        if(a.time == b.time) return a.counter > b.counter;
        else return a.time > b.time;
    }
};
priority_queue<customer,vector<customer>,cmp> busy;
priority_queue<int> wait;

void exitcounter() {
    customer c = busy.top(); busy.pop();
    now = c.time;
    wait.push(c.counter);
    ex.push_back(c.id);
}

void entercounter(int id, int w) {
    if(wait.empty()) {
        exitcounter();
        while(!busy.empty() && busy.top().time == now) exitcounter();
    }
    int c = wait.top(); wait.pop();
    customer cc = {id,w+now,c};
    busy.push(cc);

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; i++) wait.push(i);
    for(int i = 0; i < n; i++) {
        int id,w;
        cin >> id >> w;
        entercounter(id,w);
    }
    

    while(!busy.empty()) exitcounter();
    long long ans = 0;
    long long i = 1;
    for(auto e : ex) {
        ans += i++*e;
    }
    cout << ans;
}