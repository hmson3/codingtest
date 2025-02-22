#include <iostream>
using namespace std;

int main() {
    int N,x,y;
    int Mx = 0, My = 0, mx = 0, my = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        if (i == 0) {
            Mx = x;
            mx = x;
            My = y;
            my = y;
            continue;
        }
        if (mx > x) mx = x;
        if (Mx < x) Mx = x;
        if (my > y) my = y;
        if (My < y) My = y;
    }
    cout << (Mx - mx)*(My - my);
}