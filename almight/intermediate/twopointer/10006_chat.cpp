#include<bits/stdc++.h>
using namespace std;

long long int arr[1000001];
long long int cnt[1000001] = {0};
long long int target_cnt[1000001] = {0};
long long int l[1000001] = {0};
bitset<1000001> cmp;
int c = 0;

void add(int ii) {
    if (cnt[ii] == target_cnt[ii]) { cmp[ii] = 0; c--; }
    cnt[ii]++;
    if (cnt[ii] == target_cnt[ii]) { cmp[ii] = 1; c++; }
}

void del(int ii) {
    if (cnt[ii] == target_cnt[ii]) { cmp[ii] = 0; c--; }
    cnt[ii]--;
    if (cnt[ii] == target_cnt[ii]) { cmp[ii] = 1; c++; }
}

int main() {
    long long int n, m;
    cin >> n >> m;
    long long int L = 0;
    for(int i = 0; i < m; i++) {
        cin >> l[i];
        L += l[i];
    }
    for(long long int i = 0; i < m; i++) {
        int num;
        cin >> num;
        target_cnt[num] = l[i];
    }
    for(long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(L > n) {
        cout << 0;
        return 0;
    }
    for(long long int i = 0; i < L; i++) {
        cnt[arr[i]]++;
    }
    cmp.reset();
    for(long long int i = 0; i <= n; i++) {
        if(cnt[i] == target_cnt[i]) {
            cmp[i] = 1;
            c++;
        }
    }
    int ans = 0;
    if(c == n + 1) {
        ans++;
    }
    for(long long int i = L; i < n; i++) {
        int left = arr[i - L];
        int right = arr[i];
        del(left);
        add(right);
        if(c == n + 1) {
            ans++;
        }
    }
    cout << ans;
}
