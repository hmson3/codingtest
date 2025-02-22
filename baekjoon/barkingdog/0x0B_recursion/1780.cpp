#include<bits/stdc++.h>
using namespace std;
int paper[2200][2200];

int num_m1;
int num_0;
int num_1;

void func(int N, int n, int m) {
    int first = paper[n][m];
    for(int i = n; i < n+N; i++) {
        for(int j = m; j < m+N; j++) {
            if(paper[i][j] != first) {
                func(N/3,n,m);
                func(N/3,n,m+N/3);
                func(N/3,n,m+N/3*2);
                func(N/3,n+N/3,m);
                func(N/3,n+N/3,m+N/3);
                func(N/3,n+N/3,m+N/3*2);
                func(N/3,n+N/3*2,m);
                func(N/3,n+N/3*2,m+N/3);
                func(N/3,n+N/3*2,m+N/3*2);
                return;
            }
                
        }    
    }
    if(first == 1) num_1++;
    else if(first == 0) num_0++;
    else num_m1++;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    func(N,0,0);
    cout << num_m1 << "\n";
    cout << num_0 << "\n";
    cout << num_1 << "\n";
}