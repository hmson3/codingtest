#include <bits/stdc++.h>
using namespace std;

vector<int> pri(int n, int m) {
    vector<int> primes;
    vector<bool> state(m+1, true);
    state[1] = false;
    for(int i = 2; i*i<=m; i++) {
        if(!state[i]) continue;
        for(int j = i*i; j <= m; j += i)
            state[j] = false;
    }
    for(int i = n; i <=m; i++) {
        if(state[i]) primes.push_back(i);
    }
    return primes;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v = pri(2,n);

    int en = 0;
    int ans = 0;
    int sum = 0;
    int vsi = v.size();
    for(int st = 0; st < vsi; st++) {
        while(sum < n && en < vsi) {
            sum += v[en++];
        }
        if(sum == n) {
            ans++;
        }
        if(sum >= n) {
            sum -= v[st]; 
        }
        else break;
    }
         
        cout << ans << '\n';
}