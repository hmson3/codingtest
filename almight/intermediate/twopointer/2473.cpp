#include<bits/stdc++.h>
using namespace std;

long long a[5000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long one, two, three;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    long long ma = 3000000001;
    for(int i = 0; i < n - 2; i++) {
        long long go = -a[i];
        int st = i+1;
        int ed = n-1;
        while(st < ed) {
            if(abs(a[st]+a[ed]-go) < ma) {
                ma = abs(a[st]+a[ed]-go);
                one = a[i];
                two = a[st];
                three = a[ed];
            }
            if(a[st]+a[ed] > go) ed--;
            else if(a[st]+a[ed] < go) st++;
            else {
                cout << a[i] << ' ' << a[st] << ' ' << a[ed];
                return 0;
            }
        }
    }
    cout << one << ' ' << two << ' ' << three;

}