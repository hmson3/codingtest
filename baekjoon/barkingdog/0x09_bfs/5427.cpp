#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002];  // 불의 전파 시간
int dist2[1002][1002];  // 상근근 이동 시간
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fire_dis() {
    queue<pair<int, int> > Q1 = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '*') {
                Q1.push({i, j});
                dist1[i][j] = 0;
            }
        }
    }
    // 불에 대한 BFS
    while (!Q1.empty()) {
        auto cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
}
int esca() {
    queue<pair<int, int>> Q2 = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '@') {
                Q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }
    // 상근이에 대한 BFS
    while (!Q2.empty()) {
        auto cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { 
                return dist2[cur.X][cur.Y] + 1;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;  
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    return -1;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            fill(dist1[i], dist1[i] + m, -1);
            fill(dist2[i], dist2[i] + m, -1);
        }
        for (int i = 0; i < n; i++) cin >> board[i];
        fire_dis();
        int ans = esca();
        if(ans != -1) cout << ans << '\n';
        else cout << "IMPOSSIBLE" << '\n';
    }
}