#include <bits/stdc++.h>
using namespace std;

int N[500005];
int n,m;

int upper_idx(int target) {
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st+en) / 2;
        if(N[mid] > target) {
            en = mid;
        }
        else if(N[mid] <= target) {
            st = mid + 1;
        }
    
    }
    return st;
}
int lower_idx(int target) { 
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st+en) / 2;
        if(N[mid] >= target) {
            en = mid;
        }
        else if(N[mid] < target) {
            st = mid + 1;
        }
    
    }
    return st;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> N[i];
    sort(N,N+n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cout << upper_idx(t)-lower_idx(t) << ' ';
    }
}