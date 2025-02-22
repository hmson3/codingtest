#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int K;
    stack<int> S  = {};
    cin >> K;
    while(K--) {
        int r;
        cin >> r;
        if(r) S.push(r);
        else S.pop();
    }
    int ans = 0;
    while(!S.empty()) {
        ans += S.top();
        S.pop();
    }
    cout << ans;
}