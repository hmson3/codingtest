#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
    if(n == 1) return 1;
    return n + sum(n-1);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a = sum(5);
    cout << a;
}