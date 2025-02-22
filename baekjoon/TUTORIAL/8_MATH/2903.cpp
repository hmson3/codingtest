#include <iostream>
using namespace std;

int main() {


    int N;
    int T = 2;
    cin >> N;
    for (int i = 0; i < N; i++) {
        T = 2*T-1;
    } 
    cout << T*T;
}