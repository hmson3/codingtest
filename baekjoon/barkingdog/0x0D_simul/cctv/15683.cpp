// 애초에 잘 못 설계
// 
/*
1 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
1 1 1 1 0 0
1 1 1 1 1 0
1 1 1 1 1 1

1 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
1 1 1 1 0 0
1 1 1 1 1 0
1 1 1 1 1 1

1 0 0 0 0 1
1 1 0 0 0 1
1 1 1 0 0 1
1 1 1 1 0 1
1 1 1 1 1 1
1 1 1 1 1 1

1 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
1 1 1 1 0 0
1 1 1 1 1 0
2 2 2 2 2 1

1 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
1 1 1 1 0 0
1 1 1 1 (1) 1  // 여기서 (1)만 돌고 
1 1 1 1 0 1 // <-는 안 돔돔

1 0 0 0 1 0
1 1 0 0 1 0
1 1 1 0 1 0
1 1 1 1 1 0
1 1 1 1 1 0
1 1 1 1 0 1

1 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
1 1 1 1 0 0
2 2 2 2 1 0
1 1 1 1 0 1

1 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
1 1 1 1 1 1
1 1 1 0 1 0
1 1 1 0 0 1*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
int room[8][8];
int check[8][8];
int cctv_for[5] = {4,2,4,4,1};
int mi = 64;
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;
queue<pair<int,int>> q3;
queue<pair<int,int>> q4;
queue<pair<int,int>> q5;
queue<pair<int,int>> q6;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int blind_num(int arr[][8]) {
    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!arr[i][j]) num++; 
        }
    }
    return num;
}

void func(int k) {
    if(k == 6) {
        if(!q6.empty()) {
            pair<int,int> cur = q6.front(); q6.pop();
            check[cur.first][cur.second] = 1;
        }
        mi = min(mi,blind_num(check));
        for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << check[i][j]<< ' '; 
        }
        cout << '\n';
    }
    cout << '\n';
        return;
    }
    if(k == 1) {
        if(q1.empty()) func(2);
        else {
            pair<int,int> cur = q1.front(); q1.pop();
            check[cur.first][cur.second] = 1;
            for(int i = 0; i < 4; i++) {
                int nx = cur.first;
                int ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                if(q1.empty()) func(2);
                else func(1);
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                }
            }
        }
    }
    else if(k == 2) {
        if(q2.empty()) func(3);
        else {
            pair<int,int> cur = q2.front(); q2.pop();
            check[cur.first][cur.second]++;
            for(int i = 0; i < 2; i++) {
                int nx = cur.first;
                int ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = cur.second + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx - dx[i];
                    ny = ny - dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                if(q2.empty()) func(3);
                else func(2);
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx - dx[i];
                    ny = ny - dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                }
            }
            
            

        }
    }
    else if(k == 3) {
        if(q3.empty()) func(4);
        else {
            pair<int,int> cur = q3.front(); q3.pop();
            check[cur.first][cur.second]++;
            for(int i = 0; i < 4; i++) {
                int nx = cur.first;
                int ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dy[i];
                    ny = ny + dx[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                if(q3.empty()) func(4);
                else func(3);
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dy[i];
                    ny = ny + dx[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                } 
            }
        }
    }
    else if(k == 4) {
        if(q4.empty()) func(5);
        else {
            pair<int,int> cur = q4.front(); q4.pop();
            check[cur.first][cur.second]++;
            for(int i = 0; i < 4; i++) {
                int nx = cur.first;
                int ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dy[i];
                    ny = ny + dx[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx - dx[i];
                    ny = ny - dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]++;
                    else break;
                }
                if(q4.empty()) func(5);
                else func(4);
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx + dy[i];
                    ny = ny + dx[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                }
                nx = cur.first;
                ny = cur.second;
                while(1){
                    nx = nx - dx[i];
                    ny = ny - dy[i];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                    if(room[nx][ny] == 0) check[nx][ny]--;
                    else break;
                }
            }
        }
    }
    if(k == 5) {
        if(q5.empty()) func(6);
        else {
            pair<int,int> cur = q5.front(); q5.pop();
            check[cur.first][cur.second]++;
            int nx = cur.first;
            int ny = cur.second;
            while(1){
                int nx = nx + 1;
                int ny = ny;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]++;
                else break;
            }
            nx = cur.first;
            ny = cur.second;
            while(1){
                int nx = nx - 1;
                int ny = ny;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]++;
                else break;
            }
            nx = cur.first;
            ny = cur.second;
            while(1){
                int nx = nx;
                int ny = ny + 1;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]++;
                else break;
            }
            nx = cur.first;
            ny = cur.second;
            while(1){
                int nx = nx;
                int ny = ny - 1;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]++;
                else break;
            }
            if(q5.empty()) func(6);
            else func(5);
            nx = cur.first;
            ny = cur.second;
            while(1){
                int nx = nx + 1;
                int ny = ny;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]--;
                else break;
            }
            nx = cur.first;
            ny = cur.second;
            while(1){
                int nx = nx - 1;
                int ny = ny;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]--;
                else break;
            }
            nx = cur.first;
            ny = cur.second;
            while(1){
                int nx = nx;
                int ny = ny + 1;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]--;
                else break;
            }
            nx = cur.first;
            ny = cur.second;
            while(1){
                int nx = nx;
                int ny = ny - 1;
                if(0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if(room[nx][ny] == 0) check[nx][ny]--;
                else break;
            }
        }
    }
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int cctv[64] = {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
            if(room[i][j] == 1) q1.push({i,j});
            else if(room[i][j] == 2) q2.push({i,j});
            else if(room[i][j] == 3) q3.push({i,j});
            else if(room[i][j] == 4) q4.push({i,j});
            else if(room[i][j] == 5) q5.push({i,j});
            else if(room[i][j] == 6) q6.push({i,j});
        }
    }
    func(1);
    cout << mi;
}