#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool vis[10];
vector<int> v;

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << v[arr[i]-1] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            arr[k] = i;
            vis[i] = 1;
            func(k+1);
            vis[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    func(0);
}