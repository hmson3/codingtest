#include<bits/stdc++.h>
using namespace std;

char a[64][64];

void re(int x, int y, int k) {
    
    int ch = 0;
    char ze = a[x][y];
    for (int i = x; i < x+k; i++) {
        for (int j = y; j < y+k; j++) {
            if(ze != a[i][j]) {
                cout << '(';
                re(x,y,k/2);
                re(x,y+k/2,k/2);
                re(x+k/2,y,k/2);
                re(x+k/2,y+k/2,k/2);
                cout << ')';
                return;
            }
        }
    }
    cout << ze;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> a[i][j];
    re(0,0,n);
}
