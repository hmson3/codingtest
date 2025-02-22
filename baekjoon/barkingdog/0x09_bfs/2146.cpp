#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int a[100][100];
int dis[100][100];
bool vis_island[100][100];
int n,ans= 10000;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int i, int j) {
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q;
    q1.push({i,j});
    for(int k = 0; k < n; k++) fill(dis[k],dis[k]+n,0);
    dis[i][j] = 1;
    vis_island[i][j] = 1;
    while(!q1.empty()) {
        auto cur = q1.front(); q1.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx <0 || ny <0 || nx >= n || ny >= n) continue;
            if(vis_island[nx][ny]) continue;
            if(a[nx][ny] == 0) {
                q.push({cur.x,cur.y});
                continue;
            }
            dis[nx][ny] = 1;
            vis_island[nx][ny] = 1;
            q1.push({nx,ny});
        }
    }

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int cur_state = a[cur.x][cur.y];
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx <0 || ny <0 || nx >= n || ny >= n) continue;
            if(dis[nx][ny] > 0) continue;
            if(a[nx][ny] == 0) {
                dis[nx][ny] = dis[cur.x][cur.y] + 1;
            }
            else {
                if(a[cur.x][cur.y] == 0) {
                    ans = min(ans,dis[cur.x][cur.y]-1);
                    return;
                }
            }
            q.push({nx,ny});
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] && !vis_island[i][j]) {
                bfs(i,j);
            }
        }
    }
    cout << ans;
}