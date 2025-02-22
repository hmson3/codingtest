#include <iostream>
using namespace std;

int main()
{
    int n,N,C = 0;
    int array[10] = {};
    cin >> n;
    array[0] = n%42;
    N++;
  
    for (int i = 1; i < 10; i++) {
        cin >> n;
        for (int j = 0; j < N; j++) {
            if (array[j] == n%42) {
                C++;
            }
        }
        if (!C) {
            array[N] = n%42;
            N++;       
        }
        C = 0;
    }

    cout << N << "\n";

    return 0;
}