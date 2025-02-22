#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a,b;
    cin >> a >> b;
    if(a > b) swap(a,b);
    if(a < b) cout << b-a-1ll << '\n';
    else cout << 0;
    for (long long i = a+1ll; i < b; i++) {
        cout << i << ' ';
    }   
}