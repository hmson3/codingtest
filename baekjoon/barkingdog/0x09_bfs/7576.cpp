#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[1002][1002];
int dis[1002][1002];
int n = 0;
int m = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    string s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int,int>> q = {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                q.push({i,j});
            }
            if(board[i][j] == 0) {
                dis[i][j] = -1;
            }
            
                    }
    }
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(dis[nx][ny] >= 0) continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dis[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(dis[i][j],ans);
        }
    }
    cout << ans;
}