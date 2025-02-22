#include <iostream>
using namespace std;

int main() {

    int a,b;
    int c = 0;
    int m = 0;
    cin >> a;
    for(int i = 0; i < a; i++) {
        cin >> b;
        if (b == 1) continue;
        for(int j = 1; j < b; j++) {
            if (b % j == 0) {
                c++;
            }
        }
        if (c == 1) {
            m++;
        }

        c = 0;
    }
    cout << m;
}