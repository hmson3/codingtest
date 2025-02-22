#include <iostream>
using namespace std;

int main()
{

    int MAX,n = 0;
    int array[9] = {};
    
  
    for (int i = 0; i < 9; i++) {
        cin >> array[i];
    }
    MAX = array[0];
    n = 0;
    
    for (int i = 0; i < 9; i++) {
        if (array[i] > MAX) {
            MAX = array[i];
            n = i;
        }
    }

    cout << MAX << "\n" << n+1;
    return 0;
}