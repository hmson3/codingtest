#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

    string st;
    int T = 0;
    int B,A;
    int k = 1;
    int p = 0;
    char M;
    cin >> T >> B;

    while (T > 0) {
        while (k) {
            for (int i = 0; i < B; i++) {
                if (T >= i*pow(B,p) && T < (i+1)*pow(B,p)) {
                    T -= i*pow(B,p);
                    if (i < 10) cout << i;
                    else cout << char(i+55);
                    k = 0;
                    break;
                }
            }
            p++;
        }
        
        for (int i = p - 2; i >= 0; i--) {
            for (int j = 0; j < B; j++) {
                if (T >= j*pow(B,i) && T < (j+1)*pow(B,i)) {
                    T -= j*pow(B,i);
                    if (j < 10) cout << j;
                    else cout << char(j+55);

                    break;
                }
                if (j == B - 1) cout << '0';
            }
        }        
    }

}