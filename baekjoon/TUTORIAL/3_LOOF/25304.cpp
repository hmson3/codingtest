#include <iostream>
using namespace std;

int main() {
    int X,N,a,b,T;
	cin >> X >> N;
    T = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        T += a*b;
    }
    if (X == T) cout << "Yes" << endl;
    else cout << "No";
    return 0;
}