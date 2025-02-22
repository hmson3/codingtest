#include <iostream>
using namespace std;

int main() {
    int M[6] = {1,1,2,2,2,8};
    int al[6];
    for (int i = 0; i < 6; i++) {
        cin >> al[i];
    }
    
    for (int i = 0; i < 6; i++) {
        cout << M[i] - al[i] << ' ';
    }
}