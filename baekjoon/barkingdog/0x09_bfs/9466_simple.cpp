#include<bits/stdc++.h>
using namespace std;

int a[100001];
int dis[100001];
int n;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        fill(dis,dis+n+1,0);
        int g = 0,idx = 1;
        for(int i = 1; i <= n; i++) {
            if(dis[i]) continue;
            int cur = i, r = idx;

            while(!dis[cur]) {
                dis[cur] = idx++;
                cur = a[cur];
            }
            if(dis[cur] >= r) g += idx - dis[cur];
        }
        cout << n - g << '\n';
    }
}