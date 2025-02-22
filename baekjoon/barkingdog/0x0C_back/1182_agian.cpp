#include <bits/stdc++.h>
using namespace std;

int n,s;
int arr[20];
int ans;
int num;

void func(int k) {
    if(k == n) {    
        if (num == s) {
            ans++;
        }
        return;
    }
    num += arr[k];
    func(k+1);
    num -= arr[k];
    func(k+1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    func(0);
    if(s == 0) ans--;
    cout << ans;
}