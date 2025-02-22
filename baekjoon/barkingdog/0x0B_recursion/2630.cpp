#include<bits/stdc++.h>
using namespace std;
string paper[70];


void func(int N, int n, int m) {
    int first = paper[n][m];
    for(int i = n; i < n+N; i++) {
        for(int j = m; j < m+N; j++) {
            if(paper[i][j] != first) {
                cout << '(';
                func(N/2,n,m);
                func(N/2,n,m+N/2);
                func(N/2,n+N/2,m);
                func(N/2,n+N/2,m+N/2);
                cout << ')';
                return;
            } 
        }    
    }
    cout << first-'0';
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> paper[i];
    }
    func(N,0,0);
}