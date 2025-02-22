#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int pre[1000000];
vector<int> v;
vector<int> idx;
int n;

int upper_idx(int target) {
    int st = 0;
    int en = v.size();
    while(st < en) {
        int mid = (st+en) / 2;
        if(v[mid] == target) return mid;
        if(v[mid] > target) {
            en = mid;
        }
        else { 
            st = mid + 1;
        }
    
    }
    return st;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fill(pre,pre+n,-1);
    v.push_back(a[0]);
    idx.push_back(0);
    for (int i = 1; i < n; i++) {
        if (v.back() < a[i]) {
            pre[i] = idx.back();
            v.push_back(a[i]);
            idx.push_back(i);
        }
        else {
            int k = upper_idx(a[i]);
            if(k != 0) pre[i] = idx[k-1];
            v[k] = a[i];
            idx[k] = i;
        }
    }
    cout << v.size() << '\n';
    int tmp = idx.back();
    vector<int> vv;
    vv.push_back(tmp); 
    while(true) {
        tmp = pre[tmp];
        if(tmp == -1) break;
        vv.push_back(tmp);
    }
    for(int i = vv.size()-1; i >= 0; i--) {
        cout << a[vv[i]] << ' ';
    }
    
}