#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    int mx = 0;
    int idx = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> a;
        if(mx < a) {
            mx = a;
            idx = i+1;
        }
    }
    cout << mx << '\n' << idx;
    
}