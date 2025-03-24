/*
0 - 0
1 - 1
2 - 0
3 - 1
4 - 2
5 - 3
6 - 2

7 - 0
8 - 1
9 - 0
10 - 1
11 - 2
12 - 3

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    // 홀수 일 때 
    if(n % 7 == 0 || n % 7 == 2) cout << "CY";
    else cout << "SK";

}