#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int a[10] = {};
    int temp;
    getline(cin, S);
    for(int i = 0; i < S.length(); i++) {
        a[i] = S[i] - 48;
    }
    for(int i = 0; i < S.length()-1; i++) {
        for(int j = 0; j < S.length()-i-1; j++) {
            if(a[j+1] > a[j]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < S.length(); i++) {
        cout << a[i];
    }
    cout << "\n";

    return 0 ;
}
