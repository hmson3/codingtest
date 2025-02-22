// 7 1 5 2 6 3 7 
// 5 4 3 2 1
// 4 3 2 1

#include <iostream>
using namespace std;

int main() {
    long long n;
    long long t = 0;
    cin >> n;
    for(long long i = n-2; i > 0; i--) {
        t += i*(i+1)/2;
    }
    cout << t << "\n" << 3;
}