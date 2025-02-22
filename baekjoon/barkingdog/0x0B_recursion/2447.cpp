#include<bits/stdc++.h>
using namespace std;
char star[7000][7000];
int num_m1;
int num_0;
int num_1;

void func(int N, int n, int m) {
    if(N == 1) {
        star[n][m] = '*';
        return;
    }

    func(N/3,n,m);
    func(N/3,n,m+N/3);
    func(N/3,n,m+N/3*2);
    func(N/3,n+N/3,m);
    for(int i = n+N/3; i < n+N/3*2; i++) {
        for(int j = m+N/3; j < m+N/3*2; j++) {
            star[i][j] = ' ';
        }
    }
    func(N/3,n+N/3,m+N/3*2);
    func(N/3,n+N/3*2,m);
    func(N/3,n+N/3*2,m+N/3);
    func(N/3,n+N/3*2,m+N/3*2);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    func(N,0,0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << star[i][j];
        }
        cout << '\n';
    }
}