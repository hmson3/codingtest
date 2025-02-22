#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K,S,Y;
    cin >> N >> K;
    int arr[12] = {};
    for(int i = 0; i < N; i++) {
        cin >> S >> Y;
        arr[2*(Y-1)+S]++;
    }
    int ans = 0;
    for(int i = 0; i < 12; i++) {
        while(arr[i] > 0) {
            ans++;
            arr[i] -= K;
        }
    }
    cout << ans;
}