#include<bits/stdc++.h>
using namespace std;
char star[4000][8000];


void func(int N, int n, int m) {
    if (N == 3) {
        star[n][m+2] = '*';
        star[n+1][m+1] = '*';
        star[n+1][m+3] = '*';
        for(int i = 0; i < 5; i++) {
            star[n+2][m+i] = '*'; 
        }
        return;
    }
    func(N/2,n,m+N/2);
    func(N/2,n+N/2,m);
    func(N/2,n+N/2,m+N);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        fill(star[i], star[i]+2*N, ' ');

    func(N,0,0);

    for (int i = 0; i < N; i++)
    cout << star[i] << '\n';    
}