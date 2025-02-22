#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
	cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-i-1; j++) {
            cout << ' ';
        }
        for (int k = 0; k < i+1; k++) {
            cout << '*';
        }
        cout << "\n";
    }
    
    return 0;
}