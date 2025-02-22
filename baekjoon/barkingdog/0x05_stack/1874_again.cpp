#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s = {};
    vector<char> v = {};
    int n;
    cin >> n;
    int idx = 1;
    int ck = 1;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        while (idx <= r) {
            s.push(idx++);
            v.push_back('+');
        }
        if (r == s.top()) {
            s.pop();
            v.push_back('-');
        } else {
            ck = 0;
        }
    }
    if (ck) {
        for (auto c : v) {
            cout << c << '\n';
        }
    } else
        cout << "NO";
}