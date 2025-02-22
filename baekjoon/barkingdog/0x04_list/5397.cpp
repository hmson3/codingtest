#include <bits/stdc++.h>
using namespace std;


int main(void) {
    
    int n = 0;
    cin >> n;
    string s;
    while(n--) {
        list<char> L = {};
        auto cur = L.end();
        cin >> s;
        for(auto c : s) {
            if(c == '<') {
                if(cur != L.begin()) cur--;
            }
            else if(c == '>') {
                if(cur != L.end()) cur++;
            }
            else if(c == '-') {
                if(cur != L.begin()) {
                    cur--;
                    cur = L.erase(cur);
                }
            }
            else {
                L.insert(cur,c);
            }
        }
        for(auto t : L) cout << t;
        cout << "\n";
    }

}