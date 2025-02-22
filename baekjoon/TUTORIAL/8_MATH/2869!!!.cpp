#include <iostream>
using namespace std;

int main() {


    int A,B,V;
    int C = 0;;

    cin >> A >> B >> V;
    C = (V-A)/(A-B);
    if ((V - A) % (A - B) == 0) C += 1;
	else C += 2;
	cout << C;
}