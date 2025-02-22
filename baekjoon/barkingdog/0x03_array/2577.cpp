#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int a,b,c;
    cin >> a >> b >> c;
    a = a*b*c;
    int arr[10] = {};
    while(a != 0) {
        arr[a%10]++;
        a /= 10;
    }
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }
}