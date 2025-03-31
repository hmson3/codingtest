#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> mq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        mq.push(k);
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int now = mq.top();
        mq.pop();
        int nxt = mq.top();
        mq.pop();
        ans += now + nxt;
        mq.push(now + nxt);
    }
    cout << ans;
}