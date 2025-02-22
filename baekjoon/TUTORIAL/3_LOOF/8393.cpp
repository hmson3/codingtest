#include <iostream>
using namespace std;

int main() {
    int N;
	cin >> N;
    int T = 0;
    for (int i = 0; i < N; i++) {
        T += i+1;
        
    }
    cout << T << "\n";
    return 0;
}