#include <bits/stdc++.h>
using namespace std;

int notebook[40][40];
int sticker[10][10];
int n,m,k,r,c;

int check(int x, int y) {
    int ch = 1;
    for (int si = 0; si < r; si++) {
        for (int sj = 0; sj < c; sj++) {
            if(notebook[x+si][y+sj] && sticker[si][sj]) ch = 0;
        } 
    }
    return ch;
}

void stick(int x, int y) {
    for (int si = 0; si < r; si++) {
        for (int sj = 0; sj < c; sj++) {
            if(sticker[si][sj]) notebook[x+si][y+sj] = sticker[si][sj];
        } 
    }
}

void rotate() {
    //sticker 시계방향으로 돌리는 함수
    int tmp[10][10] = {};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[j][r-1-i] = sticker[i][j];     
        }
    }
    //r,c 값 바꾸기
    swap(r,c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sticker[i][j] = tmp[i][j];     
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++) 
                cin >> sticker[i][j];
        

        for (int ro = 0; ro < 4; ro++) {
            //1. 노트북에 붙일 수 있는지
            int flag = 0;
            for(int i = 0; i < n-r+1; i++) {
                for(int j = 0; j < m-c+1; j++) {
                    // 스티커를 붙여보면서 확인
                    
                    if(check(i,j)) {
                        stick(i,j);
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            // 붙이면 노트북에 반영 break;
            if(flag) break;
            //2. 못 붙이면 로테이트 시계방향
            rotate();
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(notebook[i][j]) ans++;
        } 
    }
    cout << ans;
    
}