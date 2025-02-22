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
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int flower() {
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (garden[i][j] == 3) t++;
        }
    }   
    return t;
}

void solve() {
    int time = 1;
    while(!green.empty() || !red.empty()) {
        while(!green.empty() && dis_green[green.front().x][green.front().y] == time-1) {
            pair<int,int> cur = green.front();
            green.pop();
            if(garden[cur.x][cur.y] == 3) continue;;
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.x  + dx[dir];
                int ny = cur.y  + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(garden[nx][ny] == 0 || dis_green[nx][ny] >= 0 || dis_red[nx][ny] >= 0) continue;
                dis_green[nx][ny] = dis_green[cur.x][cur.y]+1;
                green.push({nx,ny});
            }
        }
        while(!red.empty() && dis_red[red.front().x][red.front().y] == time-1) {
            pair<int,int> cur = red.front();
            red.pop();
            if(garden[cur.x][cur.y] == 3) continue;;
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.x  + dx[dir];
                int ny = cur.y  + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(garden[nx][ny] <= 0) continue;
                if(dis_red[nx][ny] >= 0) continue;
                if(dis_green[nx][ny] >= 0 && dis_red[cur.x][cur.y]+1 != dis_green[nx][ny]) continue;
                dis_red[nx][ny] = dis_red[cur.x][cur.y]+1;
                red.push({nx,ny});
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(garden[i][j] == 0) continue;
                if(dis_green[i][j] < 0 || dis_red[i][j] < 0) continue;
                if(dis_green[i][j] == dis_red[i][j]) garden[i][j] = 3;
            }
        }
        time++;
    }
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
    int baeyangtack[10] = {};
    for (int i = g + r; i < baeyang.size(); i++) baeyangtack[i] = 1;
    do {
        vector<pair<int, int>> v;
        for (int i = 0; i < baeyang.size(); i++) {
            if (!baeyangtack[i]) {
                v.push_back(baeyang[i]);
            }
        }
        int kkkk[10] = {};
        for (int i = g; i < g + r; i++) kkkk[i] = 1;
        do {
            for (int i = 0; i < n; i++) {
                fill(dis_green[i],dis_green[i]+m,-1);
                fill(dis_red[i],dis_red[i]+m,-1);
            }
            for (int i = 0; i < v.size(); i++) {
                if (!kkkk[i]) {
                    auto cccc = v[i];
                    dis_green[cccc.x][cccc.y] = 0;
                    green.push(v[i]);
                } else {
                    auto cccc = v[i];
                    dis_red[cccc.x][cccc.y] = 0;
                    red.push(v[i]);
                }
            }
            int tmp[50][50];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                tmp[i][j] = garden[i][j];
                }
            }
            solve();
            ans = max(ans, flower());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                garden[i][j] = tmp[i][j];
                }
            }

        } while (next_permutation(kkkk, kkkk + g + r));

    } while (next_permutation(baeyangtack, baeyangtack + baeyang.size()));

    cout << ans;
}

/*
5 7 1 1
1 0 1 2 1 2 1
1 1 1 0 1 0 2
2 1 0 0 1 1 1
1 0 2 1 2 1 0
0 2 1 1 0 1 2
*/