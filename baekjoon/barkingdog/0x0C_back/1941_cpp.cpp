#include<bits/stdc++.h>
using namespace std;

int l,c;
string a[5];
int arr[20];
bool isused[5][5];
int Y;
int S;
int ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void func(int k,int x,int y) {
    if(k == 7) {
        if(Y < S) {
            ans++;    
        }
        return;
    }
    for(int dir = 0; dir < 4; dir++) {
        int nx = x  + dx[dir];
        int ny = y  + dy[dir];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
        vis[nx][ny] = 1;
        q.push({nx,ny});
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    for(int i = 7; i < 25; i++)
        pm[i] = 1;
}