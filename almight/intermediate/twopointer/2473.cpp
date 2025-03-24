#include<bits/stdc++.h>
using namespace std;

long long a[5000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    long long max = 3000000000;
    for(int i = 0; i < n - 3; i++) {
        int st = i+1;
        int ed = n-1;
        while(st < ed) {
            if(abs(a[st]+a[ed]))
        }
    }

}