#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    deque<int> s = {};
    int n, k;
    cin >> n >> k;
    
    
    for(int i = 1; i <= n; i++) {
        s.push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < k; i++) {
        cin >> n;
        int idx = find(s.begin(),s.end(), n) - s.begin();
        while(s.front() != n) {
            if(idx < s.size()-idx) {
                s.push_back(s.front());
                s.pop_front();
                ans++;
            }
            else {
                s.push_front(s.back());
                s.pop_back();
                ans++;
            }
        }
        s.pop_front();
    }
    cout << ans;
}