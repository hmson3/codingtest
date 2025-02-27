#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    unordered_set<string> s;
    for(int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        s.insert(ss); 
    }
    vector<string> v;
    for(int i = 0; i < m; i++) {
        string ss;
        cin >> ss;
        if(s.find(ss) != s.end()) v.push_back(ss); 
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}