#include <iostream>
using namespace std;

int main() {
    int N;
	cin >> N;
    
    for (int i = 0; i < N/4; i++) {
        cout << "long ";
    }
    cout << "int" << "\n";
    return 0;
}