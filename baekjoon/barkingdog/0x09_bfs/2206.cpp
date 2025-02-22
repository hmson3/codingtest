#include<bits/stdc++.h>
using namespace std;

char board[1002][1002];
int dis[1002][1002][2];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs() {
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dis[0][0][0] = 1;
    while (!Q.empty()) {
        int x,y,z;
        tie(x,y,z) = Q.front(); Q.pop();
        if(x == n-1 && y == m-1) {
            return dis[n-1][m-1][z];
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' && dis[nx][ny][z] == 0) {
                dis[nx][ny][z] = dis[x][y][z] + 1;
                Q.push({nx, ny, z});
            }
            if (board[nx][ny] == '1' && z == 0 && dis[nx][ny][1] == 0){
                dis[nx][ny][1] = dis[x][y][z] + 1;
                Q.push({nx, ny, 1});
            } 
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
        cin >> board[i][j];
    cout << bfs();
}
