#include <bits/stdc++.h>
using namespace std;

int N[100005];
int n,m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> N[i];
    sort(N,N+n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cout << binary_search(N,N+n,t) << '\n';
    }
    
}