#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> s  = {};
    int n;
    cin >> n;
    s.push({100000001,0});
    for(int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        while(r > s.top().first) {
            s.pop();
        }
        cout << s.top().second << ' ';
        s.push({r,i});
    }
}