#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,p;
    cin >> n >> p;
    p--;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        p = p ^ (x-1);
    }
    if(p) cout << "cubelover";
    else cout << "koosaga";
}