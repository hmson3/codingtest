#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {


    int T,C;
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> C;
        
        cout << C / 25 << ' ';
        C %= 25;
        cout << C / 10 << ' ';
        C %= 10;
        cout << C / 5 << ' ';
        C %= 5;
        cout << C << "\n";
        
    } 
}