#include <bits/stdc++.h>
using namespace std;

int strfry(string& s,string& ss) {
    int a1[26] = {};
    int a2[26] = {};
    for(int i = 0; i < s.length(); i++) {
        a1[s[i]-'a']++;
    }
    for(int i = 0; i < ss.length(); i++) {
        a2[ss[i]-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(a1[i] != a2[i]) return 1;
    }
    return 0;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K,S,Y;
    string s1;
    string s2;
    int a1[26] = {};
    int a2[26] = {};
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s1 >> s2;
        if(strfry(s1,s2)) cout << "Impossible" << "\n";
        else cout << "Possible" << "\n";
    }

}