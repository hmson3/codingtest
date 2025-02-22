#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> num;
bool isused[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; ++i) {
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; ++i) {
        arr[k] = i;
        func(k + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        num.push_back(t);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    n = int(num.size());
    func(0);
}