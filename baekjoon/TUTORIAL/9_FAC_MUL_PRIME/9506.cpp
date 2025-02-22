#include <iostream>
using namespace std;

int main() {

    int a;
    int c = 0;
    int m = 0;
    while (true) {
        cin >> a;
        if (a == -1) break;
        for(int i = 1; i < a; i++) {
            if (a % i == 0) {
                c += i;
                m = i;
            }
        }
        if (a == c) {
            cout << a << " = ";
            for(int i = 1; i < m; i++) {
                if (a % i == 0) {
                    cout << i << " + ";
                };
            }
            cout << m << "\n";
        }
        else cout << a << " is NOT perfect." << "\n";
        c = 0;
    }
}