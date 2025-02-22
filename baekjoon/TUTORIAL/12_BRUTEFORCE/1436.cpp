#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    int i = 666;
    int n = 0;
    while(true) {
        int c = i;
        while(c) {
            if(c % 1000 == 666) {
                n++;
                break;
            }
            c /= 10;
        }
        if (n == N) {
            cout << i;
            break;
        }
        i++;
    }
}