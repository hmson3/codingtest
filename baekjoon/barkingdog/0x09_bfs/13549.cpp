#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int dis[1000005];
queue<int> q;
int n,k;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    q.push(n);
    dis[n] = 1;
    int ck = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(ck && ans <= dis[cur]) continue;
        if(cur == k) {
            ans = dis[cur];
            ck = 1;
        }
        for(int i : {-1,1}) {
            int nx = cur + i;
            if(nx < 0 || nx >=100001) continue;
            if(dis[nx] && dis[nx] <= dis[cur]) continue;
            dis[nx] = dis[cur]+1;
            q.push(nx);
        }
        int nx = 2*cur;
        if(nx < 0 || nx >=100001) continue;
        if(dis[nx] && dis[nx] <= dis[cur]) continue;
        dis[nx] = dis[cur];
        q.push(nx);
    }
    cout << ans-1;
}