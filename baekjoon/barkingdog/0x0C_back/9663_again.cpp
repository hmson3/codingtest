#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
bool isused[15][15];
int ans;

void func(int k) {
    if (k == n) {
        ans++;
        return;
    }
    int tmp[15][15] = {};
    for (int cor = 0; cor < n; ++cor) {
        if (!isused[k][cor]) {
            int mi = k - cor;
            int su = k + cor;
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++) 
                    tmp[i][j] = isused[i][j];
            for (int i = k; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == k || j == cor || mi == i - j || su == i + j) isused[i][j] = 1;
                }
            }
            func(k + 1);
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++) 
                    isused[i][j] = tmp[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << ans;
}