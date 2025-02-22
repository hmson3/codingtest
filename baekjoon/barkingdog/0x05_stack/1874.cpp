#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    stack<int> s  = {};
    int sr = 1;
    int no = 0;
    list<char> pm  = {};
    cin >> n;
    while(n--) {
        int r;
        cin >> r;
        while(s.empty() || r != s.top()) {
            if(s.empty() || r > s.top()) {
                s.push(sr++);
                pm.push_back(1);
            }
            else if(r < s.top()) {
                no++;
                break;
            }
        }
        s.pop();
        pm.push_back(-1);
    }
    if(no) cout << "NO";
    else {
        for(auto i : pm) {
            if(i > 0) {
                cout << '+' << "\n";
            }
            else cout << '-' << "\n";
        }
    }
}