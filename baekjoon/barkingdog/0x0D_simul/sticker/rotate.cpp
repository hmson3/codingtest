#include <bits/stdc++.h>
using namespace std;

int notebook[40][40];
int sticker[10][10];
int n,m,k,r,c;

int check(int x, int y) {
    cout << "check" << x << y << '\n';
                    for (int si = 0; si < n; si++) {
        for (int sj = 0; sj < m; sj++) {
            cout << notebook[si][sj] << ' '; 
        } 
        cout << '\n';
    }
    cout << "stcicker" << '\n';
        for (int ssi = 0; ssi < r; ssi++) {
            for (int ssj = 0; ssj < c; ssj++){ 
                cout << sticker[ssi][ssj] << ' ';}
                cout << '\n';
        }
        cout << '\n';

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
            notebook[si][sj] = sticker[si][sj];
        } 
    }
}

void rotate() {
    //sticker 시계방향으로 돌리는 함수
    int tmp[10][10] = {};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[j][c-1-i] = sticker[i][j];     
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
        cin >> r >> c;
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++) 
                cin >> sticker[i][j];
        
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
    cout << "stcicker" << '\n';
        for (int ssi = 0; ssi < r; ssi++) {
            for (int ssj = 0; ssj < c; ssj++){ 
                cout << sticker[ssi][ssj] << ' ';}
                cout << '\n';
        }
        cout << '\n';
}