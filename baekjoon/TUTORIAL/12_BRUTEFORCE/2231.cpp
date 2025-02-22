#include <iostream>
using namespace std;

int findsum(int s) {
    int m = s;
    while(s) {
        m += s%10;
        s /= 10;
    }
    return m;
}

int main() {
    int N;
    int sum = 0;
   
    cin >> N;
    for(int i = 1; i < N; i++) {
        if(findsum(i) == N) {
            sum = i;
            break;
        };
    }
    if (sum) cout << sum;
    else cout << 0;
    
}