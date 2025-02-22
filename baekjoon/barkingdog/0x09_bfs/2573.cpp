#include<bits/stdc++.h>
using namespace std;

int a[301][301];
int vis[301][301];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;

void spend_time() {
    for (int i = 0; i < n; i++) fill(vis[i],vis[i]+m,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] > 0) {
                vis[i][j] = 1;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(a[nx][ny] > 0 || vis[nx][ny]) continue;
                    a[i][j]--;
                }
            }
        } 

    }
}


int bfs() {
    for (int i = 0; i < n; i++) fill(vis[i],vis[i]+m,0);
    int num = 0;
    queue<pair<int,int>> q = {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] <= 0 || vis[i][j] == 1) continue;
            if(num) return 2;
            num++;
            q.push({i,j});
            while(!q.empty()) {
                pair<int,int> cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first  + dx[dir];
                    int ny = cur.second  + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(a[nx][ny] <= 0 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return num;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
    int ans = 0;
    while(true) {
        int ch = bfs();
        
        if(ch == 1) {
            spend_time();
            ans++;
        }
        else if(ch == 2) {
            cout << ans;
            return 0;
        }
        else {
            cout << 0;
            return 0;
        }
    }

}