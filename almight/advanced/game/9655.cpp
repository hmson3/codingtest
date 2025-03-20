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

    int n;
    cin >> n;
    // 홀수 일 때 
    if(n % 2) cout << "SK";
    else cout << "CY";

}