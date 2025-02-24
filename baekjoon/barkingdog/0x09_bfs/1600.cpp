#include<bits/stdc++.h>
using namespace std;

int board[1002][1002];
int dis[1002][1002][31];
int n,m,k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ni_dx[8] = {-2,-2,-1,-1,1,1,2,2};
int ni_dy[8] = {-1,1,-2,2,-2,2,-1,1};

int bfs() {
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dis[0][0][0] = 1;
    while (!Q.empty()) {
        int x,y,z;
        tie(x,y,z) = Q.front(); Q.pop();
        if(x == n-1 && y == m-1) {
            return dis[n-1][m-1][z] - 1;
        }
        if(z < k) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = x + ni_dx[dir];
                int ny = y + ni_dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == 1 || dis[nx][ny][z+1]) continue;
                dis[nx][ny][z+1] = dis[x][y][z] + 1;
                Q.push({nx, ny, z+1});
            }
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 1 || dis[nx][ny][z]) continue;
            dis[nx][ny][z] = dis[x][y][z] + 1;
            Q.push({nx, ny, z}); 
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin >> m >> n;
    for(int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    cout << bfs();
}
