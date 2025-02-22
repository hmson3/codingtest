#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string str = "";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N-i; j++) {
            str +=  ' ';
        }
        for (int j = 0; j < 2*i-1; j++) {
            str +=  '*';
        }
        cout << str << "\n";
        str = "";
    }
    for (int i = N-1; i >= 1; i--) {
        for (int j = 0; j < N-i; j++) {
            str +=  ' ';
        }
        for (int j = 0; j < 2*i-1; j++) {
            str +=  '*';
        }
        cout << str << "\n";
        str = "";
    }
}