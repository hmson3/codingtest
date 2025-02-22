#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n = 0;
int m = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>> q = {};
    int mx = 0;
    int area = 0;
    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 || vis[i][j] == 1) continue;
            num++;
            vis[i][j] = 1;
            q.push({i,j});
            area = 0;
            while(!q.empty()) {
                pair<int,int> cur = q.front(); q.pop();
                area++;
                for(int k = 0; k < 4; k++) {
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            mx = max(mx,area);
        }
    }
    cout << num << '\n' << mx;
}