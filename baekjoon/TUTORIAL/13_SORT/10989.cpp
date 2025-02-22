#include <iostream>
using namespace std;

int main() {
    int N,b;
    int a[10000] = {};
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> b;
        a[b-1]++;
    }

    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < a[i]; j++) {
            cout << i+1 << "\n";
        }
    }

    return 0 ;
}