// 1. 어디에 배양액 뿌릴 지 선택
// 2. 배양액 bfs 1초씩 한 후 꽃 피는지 확인업데이트
// 3. 큐가 빌 때까지 계속 반복
// 4. 큐 비면 꽃의 개수 확인//
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
int n, m, g, r;
int garden[50][50];
int dis_green[50][50];
int dis_red[50][50];
vector<pair<int, int>> baeyang;
queue<pair<int, int>> green;
queue<pair<int, int>> red;
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve() {
    int time = 1;
    int t = 0;
    int tmp[50][50] = {};
    while (!green.empty() && !red.empty()) {
        while (!green.empty() && dis_green[green.front().x][green.front().y] == time - 1) {
            pair<int, int> cur = green.front();
            green.pop();
            if (tmp[cur.x][cur.y] == 3) continue;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (garden[nx][ny] == 0 || dis_green[nx][ny] >= 0 || dis_red[nx][ny] >= 0) continue;
                dis_green[nx][ny] = dis_green[cur.x][cur.y] + 1;
                green.push({nx, ny});
            }
        }
        while (!red.empty() && dis_red[red.front().x][red.front().y] == time - 1) {
            pair<int, int> cur = red.front();
            red.pop();
            if (tmp[cur.x][cur.y] == 3) continue;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (garden[nx][ny] == 0) continue;
                if (dis_red[nx][ny] >= 0) continue;
                if (dis_green[nx][ny] >= 0 && dis_red[cur.x][cur.y] + 1 != dis_green[nx][ny]) continue;
                dis_red[nx][ny] = dis_red[cur.x][cur.y] + 1;
                red.push({nx, ny});
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (garden[i][j] == 0 || tmp[i][j] == 3) continue;
                if (dis_green[i][j] < 0 || dis_red[i][j] < 0) continue;
                if (dis_green[i][j] == dis_red[i][j]) {
                    tmp[i][j] = 3;
                    t++;
                }
            }
        }
        time++;
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> garden[i][j];
            if (garden[i][j] == 2) {
                baeyang.push_back({i, j});
            }
        }
    }
    int baeyangtack[10] = {1,0,2,0,2,0,1,1};
    int cand = baeyang.size();
        for (int i = 0; i < n; i++) {
            fill(dis_green[i], dis_green[i] + m, -1);
            fill(dis_red[i], dis_red[i] + m, -1);
        }
        for (int i = 0; i < cand; i++) {
            if (baeyangtack[i] == 1) {
                auto cccc = baeyang[i];
                dis_green[cccc.x][cccc.y] = 0;
                green.push(cccc);
            } 
            else if (baeyangtack[i] == 2) {
                auto cccc = baeyang[i];
                dis_red[cccc.x][cccc.y] = 0;
                red.push(cccc);
            }
        }   
        ans = max(ans, solve());

    cout << ans;
}

/*
5 7 3 2
1 0 1 2 1 2 1
1 1 1 0 1 0 2
2 1 0 0 1 1 1
1 0 2 1 2 1 0
0 2 1 1 0 1 2
*/