#include <bits/stdc++.h>
using namespace std;

void par(string& s, deque<int>& d) {
    int cur = 0;
    for(int i = 1; i < s.size()-1; i++) {
        if(s[i] == ',') {
            d.push_back(cur);
            cur = 0;
        }
        else {
            cur = 10*cur + s[i] - '0';
        }
    }
    if(cur) {
        d.push_back(cur);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int re = 0;
        int er = 0;
        string s;
        cin >> s;
        int n;
        cin >> n;
        string p;
        cin >> p;
        deque<int> d = {};
        par(p,d);

        for(char c : s) {
            
            if(c == 'R') {
                re++;
            }
            else {
                if(d.empty()) { er++; break; }
                if(re%2 != 0) {
                    d.pop_back();
                }
                else {
                    d.pop_front();
                }
            }
        }
        if(er) cout << "error" << "\n";
        else {
            cout << '[';
            int num = d.size() -1;
            for(int j = 0; j < num; j++) {
                if(re%2 != 0) {
                    cout << d.back() << ',';
                    d.pop_back();
                }
                else {
                    cout << d.front() << ',';
                    d.pop_front();
                }
            }
            if(!d.empty()) cout << d.front();
            cout << ']' << "\n";
        }
    }
    
}