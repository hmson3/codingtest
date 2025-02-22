#include <bits/stdc++.h>
using namespace std;

int v[1000001];
int v2[1000001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s = {};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && v[i] >= s.top()) {
            s.pop();
        }
        if (s.empty()) {
            v2[i] = -1;
        }
        else {
            v2[i] = s.top();
        }
        s.push(v[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << v2[i] << ' ';
    }
}