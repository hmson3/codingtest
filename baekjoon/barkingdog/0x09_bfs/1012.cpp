#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int board[50][50];
int vis[50][50];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> m >> n >> k;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) { board[i][j] = 0; vis[i][j] = 0; }}
        while(k--) {
            int x1,y1;
            cin >> x1 >> y1;
            board[x1][y1] = 1;
        }
        int num = 0;
        queue<pair<int,int>> q = {};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 0 || vis[i][j] == 1) continue;
                num++;
                q.push({i,j});
                while(!q.empty()) {
                    pair<int,int> cur = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.x  + dx[dir];
                        int ny = cur.y  + dy[dir];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                
            }
        }
        cout << num << "\n";
    }
}