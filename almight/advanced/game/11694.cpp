/*
0 - 0
1 - 1
2 - 0
3 - 1
4 - 0

홀수 : 상근 이김
짝수 : 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,p;
    cin >> n >> p;

    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        p = p ^ x;
    }
    if(p == 0) cout << "cubelover";
    else cout << "koosaga";
}