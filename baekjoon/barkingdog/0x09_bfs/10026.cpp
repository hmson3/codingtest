#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[102];
int dis[102][102];
int n = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dis[i][j] == 0) {
                queue<pair<int, int>> q = {};
                q.push({i, j});
                dis[i][j] = 1;
                char rgb = board[i][j];
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (dis[nx][ny] || board[nx][ny] != rgb) continue;
                        dis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                ans++;
            }
        }
    }
    cout << ans << ' ';
    for(int i = 0; i < n; i++) {
        fill(dis[i],dis[i]+n,0);
        for (int j = 0; j < n; j++) {
            if(board[i][j] == 'G') {
                board[i][j] = 'R';
            }
        }
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dis[i][j] == 0) {
                queue<pair<int, int>> q = {};
                q.push({i, j});
                dis[i][j] = 1;
                char rgb = board[i][j];
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (dis[nx][ny] || board[nx][ny] != rgb) continue;
                        dis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                ans++;
            }
        }
    }
    cout << ans;
}