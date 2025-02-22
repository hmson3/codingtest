#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int board[20][20];

void check(int dir){
    // 왼쪽 스와이프
    if(dir == 0) {
        for(int i = 0; i < n; i++) {
            int cur_cord = 0;
            int cur_num = board[i][cur_cord];
            for(int j = 1; j < n; j++) {
                if(board[i][j] == 0) {
                    continue;
                } 
                else if(board[i][j] == cur_num) {
                    board[i][cur_cord++] *= 2;
                    board[i][j] = 0;
                    cur_num = 0;
                }
                else {
                    if(cur_num == 0) {
                        cur_num = board[i][j];
                        board[i][cur_cord] = cur_num;
                        board[i][j] = 0;
                    }
                    else {
                        cur_num = board[i][j];
                        cur_cord++;
                        if(board[i][cur_cord] == 0) {
                            board[i][cur_cord] = cur_num;
                            board[i][j] = 0;
                        }
                    }
                } 
            } 
        }
    }
    //오른쪽으으로 스와이프
    if(dir == 1) {
        for(int i = n-1; i >= 0; i--) {
            int cur_cord = n-1;
            int cur_num = board[i][cur_cord];
            for(int j = n-2; j >= 0; j--) {
                if(board[i][j] == 0) {
                    continue;
                } 
                else if(board[i][j] == cur_num) {
                    board[i][cur_cord--] *= 2;
                    board[i][j] = 0;
                    cur_num = 0;
                }
                else {
                    if(cur_num == 0) {
                        cur_num = board[i][j];
                        board[i][cur_cord] = cur_num;
                        board[i][j] = 0;
                    }
                    else {
                        cur_num = board[i][j];
                        cur_cord--;
                        if(board[i][cur_cord] == 0) {
                            board[i][cur_cord] = cur_num;
                            board[i][j] = 0;
                        }
                    }
                } 
            } 
        }
    }
    // 위쪽 스와이프
    if(dir == 2) {
        for(int i = 0; i < n; i++) {
            int cur_cord = 0;
            int cur_num = board[cur_cord][i];
            for(int j = 1; j < n; j++) {
                if(board[j][i] == 0) {
                    continue;
                } 
                else if(board[j][i] == cur_num) {
                    board[cur_cord++][i] *= 2;
                    board[j][i] = 0;
                    cur_num = 0;
                }
                else {
                    if(cur_num == 0) {
                        cur_num = board[j][i];
                        board[cur_cord][i] = cur_num;
                        board[j][i] = 0;
                    }
                    else {
                        cur_num = board[j][i];
                        cur_cord++;
                        if(board[cur_cord][i] == 0) {
                            board[cur_cord][i] = cur_num;
                            board[j][i] = 0;
                        }
                    }
                } 
            } 
        }
    }
    //밑으로 스와이프
    if(dir == 3) {
        for(int i = n-1; i >= 0; i--) {
            int cur_cord = n-1;
            int cur_num = board[cur_cord][i];
            for(int j = n-2; j >= 0; j--) {
                if(board[j][i] == 0) {
                    continue;
                } 
                else if(board[j][i] == cur_num) {
                    board[cur_cord--][i] *= 2;
                    board[j][i] = 0;
                    cur_num = 0;
                }
                else {
                    if(cur_num == 0) {
                        cur_num = board[j][i];
                        board[cur_cord][i] = cur_num;
                        board[j][i] = 0;
                    }
                    else {
                        cur_num = board[j][i];
                        cur_cord--;
                        if(board[cur_cord][i] == 0) {
                            board[cur_cord][i] = cur_num;
                            board[j][i] = 0;
                        }
                    }
                } 
            } 
        }
    }
}



void dfs(int idx){
    if(idx == 5){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, board[i][j]);
        return;
    }
    
    int tmp[20][20];

    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                tmp[i][j] = board[i][j];

        check(dir);

        dfs(idx+1);
        // case 종료이므로 초기화
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = tmp[i][j];
    }    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];

    
    dfs(0);

    cout << ans;
        
}