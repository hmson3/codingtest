#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long M = 1234567891;
    long long H = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        long long l = c - 'a' + 1;
        for(int j = 0; j < i; j++) {
            l = (l * 31)%M;
        }
        H = (H + l)%M;
    }
    cout << H;
}