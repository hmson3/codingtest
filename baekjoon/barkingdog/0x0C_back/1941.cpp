#include<bits/stdc++.h>
using namespace std;

int mark[25];
string board[5];
int dx[4] = {1,0,-1,-0};
int dy[4] = {0,1,0,-1};
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++) {
        cin >> board[i];
    }
    fill(mark+7,mark+25,1);

    do {
        queue<pair<int,int>> q;
        int num = 0, som = 0;
        int princess[5][5] = {}, vis[5][5] = {};
        for(int i = 0; i < 25; i++) {
            if(!mark[i]) {
                int dx = i / 5, dy = i % 5;
                princess[dx][dy] = 1;
                if(q.empty()) {
                    q.push({dx,dy});
                    vis[dx][dy] = 1;
                }
            }
        }

        while(!q.empty()) {
            pair<int,int> cur = q.front(); q.pop();
            num++;
            if(board[cur.first][cur.second] == 'S') som++;
            for(int i = 0; i < 4; i++) {
                int nx = cur.first+dx[i];
                int ny = cur.second+dy[i];
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || !princess[nx][ny] || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
        if(num == 7 && som >= 4) ans++;
    } while (next_permutation(mark,mark+25));
    
    cout << ans;
    
}