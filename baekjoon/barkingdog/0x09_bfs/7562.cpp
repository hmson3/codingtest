#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[302][302];
int dis[302][302];
int n = 0;
int dx[8] = {1,1,2,2,-2,-2,-1,-1};
int dy[8] = {-2,2,-1,1,-1,1,-2,2};

int bfs(int i, int j, int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({i, j});
    dis[i][j] = 0;
    while (dis[x][y] == -1) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
    }
    return dis[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int x,y,gx,gy;
        cin >> x >> y >> gx >> gy;
        for (int i = 0; i < n; i++) {
            fill(dis[i],dis[i]+n,-1);
        }
        cout << bfs(x,y,gx,gy) << '\n';
    }
}