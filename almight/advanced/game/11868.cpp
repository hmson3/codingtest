#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,p;
    cin >> n >> p;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        p = p ^ x;
    }
    if(p) cout << "koosaga";
    else cout << "cubelover";
}