#include <iostream>
using namespace std;


// aex+bey=ce adx+bdy =cd 
// bdx+bey=fb adx+eay=fa
int main() {
    int a,b,c,d,e,f;
    int x,y;
    
    cin >> a >> b >> c >> d >> e >> f;
    y = (c*d-f*a)/(b*d-e*a);
    x = (c*e-f*b)/(a*e-b*d);
    cout << x << ' ' << y;
    
}