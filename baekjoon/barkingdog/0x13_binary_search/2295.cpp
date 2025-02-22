#include <bits/stdc++.h>
using namespace std;

int a[1001];
int two[1000001];
int n;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            two[i*n+j] = a[i] + a[j];
        }
    }
    sort(two,two+n*n);
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(binary_search(two,two+n*n,a[j]-a[i])) {
                ans = max(a[j],ans);
            }
        }
    }
    
   cout << ans;
}