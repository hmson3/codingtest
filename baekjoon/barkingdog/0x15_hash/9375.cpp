#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<string,int> s;
        for(int i = 0; i < n; i++) {
            string ss,sss;
            cin >> ss >> sss;
            s[sss] += 1; 
        }
        long long ans = 1;
        for(auto c : s) {
            ans *= c.second+1;
        }
        cout << ans - 1 << '\n';
    }
}