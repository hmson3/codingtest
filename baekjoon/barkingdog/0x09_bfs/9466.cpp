#include<bits/stdc++.h>
using namespace std;

int a[100001];
int dis[100001];
int n;

void bfs() {
    fill(dis,dis+n+1,0);
    for(int i = 1; i<= n; i++) {
        if(dis[i] != 0) continue;
        dis[i] = 1;
        int cur = a[i];
        while(true) {
            if(dis[cur] != 0 || cur == a[cur]) {
                int curcur = i;
                while(curcur != cur) {
                    dis[curcur] = -1;
                    curcur = a[curcur];
                }
                break;
            }
            dis[cur] = 1;
            cur = a[cur];
        }
    }
}

int count() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dis[i] == -1) ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        bfs();
        cout << count() << '\n';
    }
}