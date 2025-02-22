#include <bits/stdc++.h>
using namespace std;

int zero[50];
int one[50];



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;
    for(int i = 2; i <= 40; i++) {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    
    int n;
    cin >> n;
    while(n--) {
        int k;
        cin >> k;
        cout << zero[k] << ' ' << one[k] << '\n';
    }
    
}