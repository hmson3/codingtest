#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
string board[1002];
int fire[1002][1002];
int jihoon[1002][1002];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s;
    queue<pair<int,int>> Q_F = {};
    queue<pair<int,int>> Q_J = {};
    for(int i = 0; i < n; i++) {
        cin >> s;
        board[i] = s;
        for(int j = 0; j < m; j++) {
            fire[i][j] = -1;
            jihoon[i][j] = -1;
            if(s[j] == 'J') {
                Q_J.push({i,j});
                jihoon[i][j] = 0;
            }
            else if(s[j] == 'F') {
                Q_F.push({i,j});
                fire[i][j] = 0;
            }

        }
    }
    while(!Q_F.empty()) {
        pair<int,int> cur = Q_F.front(); Q_F.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            fire[nx][ny] = fire[cur.x][cur.y] + 1;
            Q_F.push({nx,ny});
        }
    }
    int imp = 1;
    while(!Q_J.empty()) {
        pair<int,int> cur = Q_J.front(); Q_J.pop();
        if(cur.x == 0 || cur.y == 0 || cur.x == n-1 || cur.y == m-1) {
                cout << jihoon[cur.x][cur.y]+1;
                return 0;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;   // 범위를 벗어났다는 것은 탈출에 성공했다는 의미
            // cout << jihoon[nx][ny]+1;
            // return 0;
            if(jihoon[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            jihoon[nx][ny] = jihoon[cur.x][cur.y] + 1;
            if(fire[nx][ny] != -1 && jihoon[nx][ny] >= fire[nx][ny]) continue;
            if(nx == 0 || ny == 0 || nx == n-1 || ny == m-1) {
                cout << jihoon[nx][ny]+1;
                while(!Q_J.empty()) {
                    Q_J.pop();
                }
                imp--;
                break;
            }
            Q_J.push({nx,ny});
        }
    }

    if(imp) cout << "IMPOSSIBLE";

}