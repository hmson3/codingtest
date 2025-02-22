#include <iostream>
#include <string>
using namespace std;

int main() {

    string S1[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    string s;
    char a;
    int N = 0;
    int R = 0;
    int G = 0;
    int Y = 0;
    char C = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        int j = 0; 
        while (j < s.length()) {
            if (j == s.length() - 1) Y++;
            a = s[j];
            R = 0;
            G = 0;
            for (int k = j+1; k < s.length(); k++) {
                if (a != s[k]) {
                    R = 1;
                }
                if (a == s[k] && R == 1) {
                    G = 1;
                }
            }
            if (G) break;
            j++;
        }
    }        
    cout << Y;
    
    return 0;
}