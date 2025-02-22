#include <iostream>
using namespace std;

int main() {

    int x,y,w,h;
    int xw,yh;
    int mx,my;
    cin >> x >> y >> w >> h;
    xw = w - x;
    yh = h - y;
    if (x < xw) mx = x;
    else mx = xw;
    if (y < yh) my = y;
    else my = yh;
    if (my < mx) cout << my;
    else cout << mx;
}