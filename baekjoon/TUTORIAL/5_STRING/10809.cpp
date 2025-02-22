#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    int al[26];
    for (int i = 0; i < 26; i++) {
        al[i] = -1;
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == i+97) {
                al[i] = j;
                break;
            }
        }
    }
    
    for (int i = 0; i < 26; i++) {
        cout << al[i] << ' ';
    }
    
    return 0;
}