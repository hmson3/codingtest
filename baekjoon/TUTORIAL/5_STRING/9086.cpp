#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T;
    string str;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> str;
        cout << str[0] << str[str.size()-1] << endl;
    }
     
    return 0;
}