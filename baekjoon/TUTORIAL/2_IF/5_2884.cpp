#include <iostream>
using namespace std;

int main() {
    int H,M;
	cin >> H >> M;
    
    if (M >= 45) cout << H << ' ' << M-45;
    else {
        if (H-1 < 0) cout << "23 " << M+15;
        else cout << H-1 << ' ' << M+15;
    }
    return 0;
}