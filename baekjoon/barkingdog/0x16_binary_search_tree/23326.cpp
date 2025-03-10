#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    int pos = 1;
    set<int> one;
    for(int i = 1; i <= n; i++) {
        int ii;
        cin >> ii;
        if(ii == 1) one.insert(i);
    }
    while(q--) {
        int com;
        cin >> com;
        if(com == 1) {
            int iii;
            cin >> iii;
            if(one.find(iii) != one.end()) {
                one.erase(iii);
            }
            else {
                one.insert(iii);
            }
        }
        else if(com == 2) {
            int x;
            cin >> x;
            pos = (pos+x) % n;
            if(pos == 0) pos = n;
        }
        else {
            if(one.empty()) {
                cout << -1 << '\n';
                continue;
            }
            if(one.find(pos) != one.end()) {
                cout << 0 << '\n';
                continue;
            }
            auto it = one.upper_bound(pos);
            if(it != one.end()) cout << *it - pos << '\n';
            else cout << n - pos + *one.begin() << '\n';
        }
    }
}