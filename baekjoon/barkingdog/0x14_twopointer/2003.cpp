#include <bits/stdc++.h>
using namespace std;

long long a[10000];
long long m;
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int en = 0;
    int ans = 0;
    long long sum = 0;
    for(int st = 0; st < n; st++) {
        while(sum < m && en < n) {
            sum += a[en++];
        }
        if(sum == m) {
            ans++;
        }
        if(sum >= m) {
            sum -= a[st]; 
        }
        else break;
    }
         
        cout << ans << '\n';
}