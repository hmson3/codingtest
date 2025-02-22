#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> s = {};
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        s.push(i);
    }
    while(--n) {
        s.pop();
        s.push(s.front());
        s.pop();
    }
    cout << s.front();
}