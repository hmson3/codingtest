#include <iostream>
#include <string>
using namespace std;

int main()
{

    string S1[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    string s;
    int M = 0;
    int R = 0;
    char C = 0;
    
    cin >> s;
    int i = 0;
    while( i < s.length() ) {
        for (int j = 0; j < 8; j++) {
            if (S1[j] == s.substr(i,S1[j].length())) {
                M++;
                i = i + S1[j].length();
                R++;
                break;
            }
        }
        if (R) {
            R = 0;
            continue;
        }
        i++;
        M++;
        R = 0;
    }



    cout << M;
    
    return 0;
}