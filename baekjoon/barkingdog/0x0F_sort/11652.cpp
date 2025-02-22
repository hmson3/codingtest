#include <bits/stdc++.h>
using namespace std;

long long card[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> card[i];
    }

    sort(card,card+n);
    
    int cnt = 1;
    long long mxval = -(1ll << 62) - 1;
    int mxcnt = 0;
    for (int i = 1; i < n; i++) {
        if(card[i-1] == card[i]) cnt++;
        else {
            if(cnt > mxcnt) {
                mxcnt = cnt;
                mxval = card[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > mxcnt) mxval = card[n-1];
    cout << mxval;
}