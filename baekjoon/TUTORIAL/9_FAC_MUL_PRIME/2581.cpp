#include <iostream>
using namespace std;

int main() {

    int a,b;
    int m = 0;
    int mi = 0;
    int c = 0;

    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        
        if (i == 1) continue;
        for(int j = 1; j < i; j++) {
            if (i % j == 0) {
                c++;
            }
        }

        if (c == 1 && m == 0) mi = i;
        if (c == 1) {
            m += i;
        }
   
        c = 0;
    }
    if (m == 0) cout << -1;
    else {
        cout << m << "\n" << mi;
    }
}