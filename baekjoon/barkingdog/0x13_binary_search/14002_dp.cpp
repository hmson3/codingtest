#include <bits/stdc++.h>
using namespace std;

int a[1000];
int d[1000];
int pre[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fill(d,d+n,1);
    fill(pre,pre+n,-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if(d[i] < d[j]+1) {
                    d[i] = d[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }
    cout << *max_element(d, d + n) << '\n';
    vector<int> v;
    int tmp = max_element(d, d + n) - d;
    v.push_back(tmp); 
    while(true) {
        tmp = pre[tmp];
        if(tmp == -1) break;
        v.push_back(tmp);
    }
    for(int i = v.size()-1; i >= 0; i--) {
        cout << a[v[i]] << ' ';
    }
    
}