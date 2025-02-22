#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[26] = {};

    string s1;
    string s2;
    cin >> s1 >> s2;
    for (auto i : s1) arr[i-'a']++;
    for (auto i : s2) arr[i-'a']--;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(arr[i]) {
            if(arr[i] > 0) ans += arr[i];
            else ans -= arr[i]; 
        } 
    }
    cout << ans;
}