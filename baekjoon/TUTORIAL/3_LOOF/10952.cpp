#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int a,b;
	cin >> a >> b;
    
    while (a || b) {
        cout << a+b << "\n";
        cin >> a >> b;
        
    }
    
    return 0;
}