#include <bits/stdc++.h>
using namespace std;

char board[1000][1000];
int dis[1000][1000][2];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) dis[i][j][0] = dis[i][j][1] = -1;
    dis[0][0][0] = dis[0][0][1] = 1;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        if (x == n - 1 && y == m - 1) return dis[x][y][broken];
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == '0' && dis[nx][ny][broken] == -1) {
                dis[nx][ny][broken] = dis[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }

            if (!broken && board[nx][ny] == '1' && dis[nx][ny][1] == -1) {
                dis[nx][ny][1] = dis[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> board[i][j];
    cout << bfs();
    return 0;
}