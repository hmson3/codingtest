#include<bits/stdc++.h>
using namespace std;

string dogam[100001];
unordered_map<string,int> um;
int n,m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string ss;
        cin >> ss;
        um[ss] = i;
        dogam[i] = ss; 
    }
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(isdigit(s[0])) {
            cout << dogam[stoi(s)] << '\n';
        }
        else cout << um[s] << '\n';
    }
}