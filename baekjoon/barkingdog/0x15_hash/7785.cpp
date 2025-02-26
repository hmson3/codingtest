#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_set<string> s;
    for(int i = 0; i < n; i++) {
        string ss,el;
        cin >> ss >> el;
        if(el == "enter") s.insert(ss);
        else s.erase(ss); 
    }
    vector<string> v(s.begin(),s.end());
    sort(v.begin(), v.end());
    for(int i = v.size()-1; i >=0; i--) {
        cout << v[i] << '\n';
    }

}