#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int a;
    cin >> a;
    int arr[10] = {};
    while(a != 0) {
        arr[a%10]++;
        a /= 10;
    }
    a = arr[9]+arr[6];
    if(a % 2 == 0) arr[6] = a/2; // (arr[9]+arr[6]+1)/2 로 줄일 수 있음음
    else arr[6] = (a+1)/2; 
    a = arr[0];
    for(int i = 1; i < 9; i++) { 
        if (arr[i] > a) a = arr[i];
    }
    cout << a;
}