#include <bits/stdc++.h>
using namespace std;

int card[21];

void sw(int a, int b) {
    int tmp;
    while(a < b) {
        tmp = card[a];
        card[a++] = card[b];
        card[b--] = tmp;
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < 21; i++) card[i] = i;
    for (int i = 0; i < 10; i++) {
        int ai,bi;
        cin >> ai >> bi;
        sw(ai,bi);
    }
    for (int i = 1; i < 21; i++)
    {
        cout << card[i] << ' ';
    }
    
}
