#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string str;
    int n; 
    cin >> str >> n;
    cout << str[n-1] << endl;

    return 0;
}