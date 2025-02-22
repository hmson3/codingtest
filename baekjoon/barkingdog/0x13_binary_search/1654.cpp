#include <bits/stdc++.h>
using namespace std;

int K[10001];
int N[1000001];
int n,k;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> K[i];
    }
    long long st = 0;
    long long en = 1ll << 31;
    while(st < en) {
        long long mid = (st+en+1) / 2;
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans += K[i] / mid;
        }
        if(ans >= n) {
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }
    
   cout << st;
}