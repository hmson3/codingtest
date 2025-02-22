#include <bits/stdc++.h>
using namespace std;

int n,k;
int d[101][100001];
int W[101];
int V[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> W[i] >> V[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if(W[i] > j) d[i][j] = d[i-1][j];
            else d[i][j] = max(d[i-1][j-W[i]]+V[i],d[i-1][j]);
        }
    }
    
    cout << d[n][k];
}