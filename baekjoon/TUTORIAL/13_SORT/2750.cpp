#include <iostream>
using namespace std;

int main() {
    int N,temp;
    int a[1000] = {};
   
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-i-1; j++) {
            if(a[j+1] < a[j]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << a[i] << "\n";
    }

    return 0 ;
}