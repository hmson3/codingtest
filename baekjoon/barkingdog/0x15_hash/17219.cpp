#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    unordered_map<string,string> s;
    for(int i = 0; i < n; i++) {
        string ss,sss;
        cin >> ss >> sss;
        s[ss] = sss; 
    }
    for(int i = 0; i < m; i++) {
        string ss;
        cin >> ss;
        cout << s[ss] << '\n';
    }
}