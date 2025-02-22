// 1 || 1
// 2 || 2 3 4 5 6 7
// 3 || 8 9 10 11 12 13 14 15 16 17 18 19

#include <iostream>
using namespace std;

int main() {


    int N;
    int c = 1;
    int i = 1;
    int e = 1;
    int n = 1;
    cin >> N;
    if (N == 1) {
        c = 0;
    }
    while(c) {
        
        i = e + 1;
        e = i + (n*6) - 1;
        if (i <= N && N <= e) c = 0;
        n++;
    }

    cout << n;
}