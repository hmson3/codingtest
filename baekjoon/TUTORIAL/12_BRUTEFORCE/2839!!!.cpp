// N % 5 안되면 N-=3 ans++ 반복

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int n = N/3;
    int mi = N;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if (5*i+3*j == N) {
                if (i+j < mi) {
                    mi = i+j;
                }
            }
        }
    }
    if(mi == N) cout << -1;
    else cout << mi;

}