#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
	cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << "\n";
    }
    
    return 0;
}