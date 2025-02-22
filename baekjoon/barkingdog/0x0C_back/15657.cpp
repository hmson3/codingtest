#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int a[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << a[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if(k == 0 || arr[k-1] <= i) {
            arr[k] = i;
            func(k + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    func(0);
}