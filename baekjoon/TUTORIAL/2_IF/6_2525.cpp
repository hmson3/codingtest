#include <iostream>
using namespace std;

int main() {
    int H,M,T;
	cin >> H >> M >> T;
    M += T;
    H += M / 60;
    M = M % 60;
    H = H % 24;
    cout << H << ' ' << M;
    return 0;
}