#include <iostream>
using namespace std;

int main() {
    int N;
	cin >> N;
    int a,b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        cout << a+b << "\n";
    }
    return 0;
}