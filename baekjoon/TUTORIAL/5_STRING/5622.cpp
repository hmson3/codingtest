#include <iostream>
#include <string>
using namespace std;

int main()
{

    string S1;
    int T = 0;
    cin >> S1;
    int al[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
   
    for (int i = 0; i < S1.size(); i++) {
        T += al[S1[i] - 'A'];
    }
   
    cout << T;
    
    return 0;
}