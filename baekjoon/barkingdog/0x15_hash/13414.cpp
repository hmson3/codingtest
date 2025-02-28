#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b) {return a.second < b.second; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,l;
    cin >> k >> l;
    unordered_map<string,int> s;
    for(int i = 0; i < l; i++) {
        string ss;
        cin >> ss;
        s[ss] = i; 
    }
    vector<pair<string,int>> v(s.begin(),s.end());
    sort(v.begin(), v.end(),cmp);
    for(int i = 0; i < v.size(); i++) {
        if(i == k) break;
        cout << v[i].first << '\n';
    }
}