#include<bits/stdc++.h>
using namespace std;

int n,m,k;
char board[1000][1000];
int dis[1000][1000][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int bfs() {
    queue<tuple<int,int,int,bool>> q;
    q.push({0,0,0,0});
    dis[0][0][0] = 1;
    while(!q.empty()) {
        int x,y,z,night;
        tie(x,y,z,night) = q.front(); q.pop();
        if(x == n-1 && y == m-1) return dis[x][y][z];
        int ck = 0;
        for(int dir =0; dir < 4; dir++) {
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '0' && dis[nx][ny][z] == 0) {
                dis[nx][ny][z] = dis[x][y][z] + 1;
                if(night) q.push({nx, ny, z, false});
                else q.push({nx, ny, z, true});
            }
            if (board[nx][ny] == '1' && z < k && dis[nx][ny][z + 1] == 0) {
                if(night) {
                    ck = 1;
                }
                else {
                    dis[nx][ny][z + 1] = dis[x][y][z] + 1;
                    q.push({nx, ny, z + 1,true});
                }
            }
        }
        if(ck) {
            dis[x][y][z] = dis[x][y][z] + 1;
            q.push({x, y, z ,false});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    cout << bfs();

}