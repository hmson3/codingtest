#include <bits/stdc++.h>
using namespace std;

int T,n,m;
int a[20001];
int b[20001];
int sizea = 0;
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) { cin >> a[i]; }
        for(int j = 0; j < m; j++) { cin >> b[j]; }
        sort(a,a+n);
        sort(b,b+m);
        int ans = 0;
        for(int i = 0; i < n; i++) { 
            for(int j = 0; j < m; j++) { 
                if(a[i] <= b[j]) {
                    ans += j;
                    break;
                }
                if(j == m-1) ans += m;
            }
        }
        cout << ans << '\n';
    }
}