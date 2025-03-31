#include<bits/stdc++.h>
using namespace std;

int n,k;
struct customer {
    int id;
    int time;
    int counter;
};
bool cmp(customer a, customer b) {
    if(a.time == b.time) return a.counter > b.counter;
    else return a.time < b.time;
} 
priority_queue<customer,vector<customer>,decltype(&cmp)> k1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        
    }
    if(n > k) {

    }
    else {
        for(int i = k; k > 0; i--) {

        }
    }
    int ii;
    cin >> ii;
    le.push(ii);
    cout << ii << '\n';
    for(int i = 1; i < n; i++) {
        int k;
        cin >> k;
        if(k > le.top()) {
            ri.push(k);
        }
        else {
            le.push(k);
        }
        if(le.size() < ri.size()) {
            le.push(ri.top());
            ri.pop();
        }
        else if(le.size() > ri.size() + 1) {
            ri.push(le.top());
            le.pop();
        }
        cout << le.top() << '\n';
    }
}