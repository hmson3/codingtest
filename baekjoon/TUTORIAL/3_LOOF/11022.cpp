#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,a,b;
	cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << a+b << "\n";
    }
    
    return 0;
}