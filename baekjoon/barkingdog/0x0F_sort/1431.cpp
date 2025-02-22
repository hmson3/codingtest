#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b) {
    if(a.size() != b.size()) return a.size() < b.size();
    else {
        int a_sum = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i]-'0' < 10) a_sum += a[i]-'0';
        }    
        int b_sum = 0;
        for(int i = 0; i < b.size(); i++) {
            if(b[i]-'0' < 10) b_sum += b[i]-'0';
        }
        if(a_sum != b_sum) return a_sum < b_sum;
        else return a < b;
    }
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s[52] = {};
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s,s+n,cmp);
    for(int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
}