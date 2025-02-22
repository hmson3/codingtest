#include <iostream>
using namespace std;
int main() {
    int A,B;
    cin >> A >> B;
    cout << A*(B%10) << "\n" << A*(B%100-B%10)/10 << "\n" << A*(B-B%100)/100 << "\n" << A*B << endl;
}