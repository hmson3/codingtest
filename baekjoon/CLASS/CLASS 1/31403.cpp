#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b,c;
    cin >> a >> b >> c;

    cout << stoi(a)+stoi(b)-stoi(c) << '\n';
    a += b;
    cout << stoi(a) - stoi(c);
}