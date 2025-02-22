#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
string a[12];
int dis[100][100];
int n = 12, m = 6;
int ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    dis[i][j] = 1;
    char state = a[i][j];
    int puyo = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        puyo++;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx <0 || ny <0 || nx >= n || ny >= n) continue;
            if(dis[nx][ny] == 1 || a[nx][ny] != state) continue;
            dis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    return puyo;
}
void remv(int i, int j) {
    queue<pair<int, int>> q;
    dis[i][j] = 0;
    a[i][j] = '.';
    q.push({i, j});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dis[nx][ny] <= 0) continue;
            dis[nx][ny] = 0;
            a[nx][ny] = '.';
            q.push({nx, ny});
        }
    }
}
void back(int i, int j) {
    queue<pair<int, int>> q;
    dis[i][j] = -1;
    q.push({i, j});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dis[nx][ny] <= 0) continue;
            dis[nx][ny] = -1;
            q.push({nx, ny});
        }
    }
}
void time_spend() {
    for(int j = 0; j < 6; j++) {
        int idx = n-1;
        for(int i = n-1; i >= 0; i--) {
            if(a[i][j] != '.') {
                char tmp = a[i][j];
                a[i][j] = '.';
                a[idx--][j] = tmp;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < n; i++)
            cin >> a[i];

    int tim = 0;
    while(true) {
        int ck = 0;
        for (int i = 0; i < n; i++) fill(dis[i],dis[i]+n,0);
        for (int i = n-1; i >= 0; i--) {
            for(int j = 5; j >= 0; j--) {
                if(a[i][j] != '.' && dis[i][j] != -1 ) {
                    if(bfs(i,j) >= 4) {
                        remv(i,j);
                        ck++;
                    }
                    else {
                        back(i,j);
                    }
                }
            }
        }
        if(ck) {
            time_spend();
            tim++;
        }
        else {
            break;
        }
        
    }
    cout << tim;
}