#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

    string st;
    int T = 0;
    int B,A;
    char M;
    cin >> st >> B;

    for(int k=0; k < st.length(); k++) {
        M = st[k];
        if (M < 60) {A = M - '0';}
        else {A = M - 'A' + 10;} 
        T += A*pow(B,st.length()-1-k);
    }


    cout << T;

    
}