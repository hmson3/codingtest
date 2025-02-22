#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> s = {};
    vector<char> v = {};
    int n;
    cin >> n;
    int idx = 1;
    int ck = 1;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        if(s.empty()) {
            s.push({r,i});
            cout << 0 << ' ';
            continue;
        }
        while(!s.empty() && r > s.top().first) {
            s.pop();
        }
        if(!s.empty()) {
            cout << s.top().second+1 << ' ';
            s.push({r,i});
        }
        else {
            cout << 0 << ' ';
            s.push({r,i});
        }
    }
}