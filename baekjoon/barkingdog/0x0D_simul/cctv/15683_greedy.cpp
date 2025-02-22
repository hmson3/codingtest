#include<bits/stdc++.h>
using namespace std;

int n,m;
int room[8][8];

int mi = 64;
vector<pair<int,int>> cctv;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int blind_num() {
    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!room[i][j]) num++; 
        }
    }
    return num;
}


void check(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(0 > x || x >= n || 0 > y || y >= m) break;
        if(room[x][y] == 6) break;
        if(room[x][y] != 0) continue;
        room[x][y] = 7;
    }
}

void func(int k) {
    if(k == cctv.size()) {
        mi = min(mi,blind_num());
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {
                cout << room[i][j] << ' ';
            }
            cout << '\n';
        }
            cout << '\n';
        return;
    }

    int x = cctv[k].first;
    int y = cctv[k].second;
    int tmp[9][9];

    for(int dir = 0; dir < 4; dir++) {
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                tmp[i][j] = room[i][j];
        if(room[x][y] == 1) {
            check(x,y,dir);
        }
        else if(room[x][y] == 2) {
            check(x,y,dir);
            check(x,y,dir+2);
        }
        else if(room[x][y] == 3) {
            check(x,y,dir);
            check(x,y,dir+1);
        }
        else if(room[x][y] == 4) {
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
        }
        else if(room[x][y] == 5) {
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
            check(x,y,dir+3);
        }
        func(k+1);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                room[i][j] = tmp[i][j];
    }               
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];
            if(room[i][j] != 0 && room[i][j] != 6)
                cctv.push_back({i, j});
        }
    }
    func(0);
    cout << mi;
}