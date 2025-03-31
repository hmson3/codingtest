#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> ri;
priority_queue<int> le;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
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