#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s = {};
    vector<char> v = {};
    int n;
    cin >> n;
    unsigned int ans = 0;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        while(!s.empty() && r >= s.top()) {
            s.pop();
        }
        ans += s.size();
        s.push(r);
    }
    cout << ans;
}