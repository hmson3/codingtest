#include <iostream>
using namespace std;

int main() {
    int N,temp;
    int a[5] = {};
   
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < 5-1; i++) {
        for(int j = 0; j < 5-i-1; j++) {
            if(a[j+1] < a[j]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    temp = 0;
    for(int i = 0; i < 5; i++) {
        temp += a[i];
    }
    cout << temp/5 << "\n" << a[2];

    return 0 ;
}