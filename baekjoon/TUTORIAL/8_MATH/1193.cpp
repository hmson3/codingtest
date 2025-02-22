#include <iostream>
using namespace std;

int main() {


    int N;
    int n = 1;
    int c = 1;
    int bj;
    int bm;
    cin >> N;
    while(N > n*(n+1)/2) {
        n++;
    }
    N -= (n-1)*(n)/2;
    if (n%2 == 0) {
        bj = 1;
        bm = n;
        for (int i = 1; i < N; i++) {
            bj += 1;
            bm -= 1;
        }
    }
    else {
        bj = n;
        bm = 1;
        for (int i = 1; i < N; i++) {
            bj -= 1;
            bm += 1;
        }
    }

    cout << bj << '/' << bm;
}