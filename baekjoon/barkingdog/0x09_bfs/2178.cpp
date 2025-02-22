#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[102];
int dis[102][102];
int n = 0;
int m = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for(int i = 0; i < n; i++) fill(dis[i],dis[i]+m,-1);

    queue<pair<int,int>> q = {};
   
    dis[0][0] = 0;
    q.push({0,0});
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(dis[nx][ny] != -1 || board[nx][ny] != '1') continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    cout << dis[n-1][m-1] + 1;
}