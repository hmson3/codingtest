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
        multiset<int> s;
        for(int i = 0; i < n; i++) {
            string c;
            int ii;
            cin >> c >> ii;
            if(c == "I") {
                s.insert(ii);
            }
            else {
                if(s.empty()) continue;
                if(ii == 1) {
                    auto ss = s.end();
                    s.erase(--ss);
                }
                else {
                    s.erase(s.begin());
                }
            }
        }
        if(s.empty()) cout << "EMPTY" << '\n';
        else {
            cout << *--s.end() << ' ' << *s.begin() << '\n';
        }
    }
}