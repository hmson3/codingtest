#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    while(true) {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        if(a == b && b == c && c == a) cout << "Equilateral" << "\n";
        else {
            int m = a;
            if(m < b) m = b;
            if(m < c) m = c;
            if (m >= a+b+c-m) cout << "Invalid" << "\n";
            else {
                if(a == b || b == c || c == a) cout << "Isosceles" << "\n";    
                else cout << "Scalene" << "\n";
            }
        }
    } 
}