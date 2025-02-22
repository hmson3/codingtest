#include <bits/stdc++.h>
using namespace std;


int main(void) {
    list<char> L = {};
    string s;
    cin >> s;
    auto cur = L.end();
    for(auto c : s) {
        L.push_back(c);
    }
    int n;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if(s == "L") {
            if(cur != L.begin()) cur--;
        }
        else if(s == "D") {
            if(cur != L.end()) cur++;
        }
        else if(s == "B") {
            if(cur != L.begin()) {
                cur--;
                cur = L.erase(cur);
            }
        }
        else if(s == "P") {
            cin >> c;
            L.insert(cur,c);
        }
    }
    for(auto i : L) cout << i;

}