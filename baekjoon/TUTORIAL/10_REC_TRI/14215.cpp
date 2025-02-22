#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int ma = a;
    int m,mi;
    if(ma < b) ma = b;
    if(ma < c) ma = c;
    mi = a;
    if(mi > b) mi = b;
    if(mi > c) mi = c;
    m = a + b + c - ma - mi;
    
    if(ma >= m+mi) {
        cout << 2*(m+mi)-1;
    }
    else cout << ma+m+mi;
}