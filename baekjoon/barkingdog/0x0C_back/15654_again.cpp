#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int a[10];
bool isused[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if(!isused[i]) {
            arr[k] = a[i];
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    func(0);
}