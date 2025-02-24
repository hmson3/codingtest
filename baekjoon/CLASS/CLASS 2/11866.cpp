#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    deque<int> q;
    for (int i = 1; i <= n; i++) q.push_back(i);
    cout << '<';
    while(q.size() > 1) {
        for (int i = 1; i < k; i++) {
            q.push_back(q.front());
            q.pop_front();
        }
        cout << q.front() << ", ";
        q.pop_front();
    }
    cout << q.front() << '>';
}