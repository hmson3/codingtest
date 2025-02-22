#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    list<int> l = {};
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }

    list<int>::iterator cur = l.begin();
    for (int i = 1; i < k; i++) {
        cur++;
        if(cur == l.end()) cur = l.begin();
    }
    cout << '<';
    cout << *cur;
    if (n == 1) {
        cout << '>';
        return 0;
    }
    cout << ", ";
    cur = l.erase(cur);
    if(cur == l.end()) cur = l.begin();
    while (l.size() > 1) {
        for (int i = 1; i < k; i++) {
            cur++;
            if(cur == l.end()) cur = l.begin();
        }
        cout << *cur << ", ";
        cur = l.erase(cur);
        if(cur == l.end()) cur = l.begin();
    }
    cout << *cur <<'>';
}