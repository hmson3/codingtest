#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    for (int i = 0; i < 3; i++) {
        int m = 0;
        for(int j = 0; j < 4; j++) {
            cin >> n;
            if(n) m++; 
        }
        switch (m) {
            case 1:
                cout << 'C' << '\n';
                break;
            case 2:
                cout << 'B' << '\n';
                break;
            case 3:
                cout << 'A' << '\n';
                break;
            case 4:
                cout << 'E' << '\n';
                break;
            case 0:
                cout << 'D' << '\n';
                break;

            default:
                break;
        }
    }
}
