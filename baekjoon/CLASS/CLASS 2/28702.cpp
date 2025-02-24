#include <bits/stdc++.h>
using namespace std;

void fizbuz(int n) {
    if(n%3 == 0 && n%5 == 0) cout << "FizzBuzz";
    else if(n%3 == 0) cout << "Fizz";
    else if(n%5 == 0) cout << "Buzz";
    else cout << n;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    for(int i = 0; i < 3; i++) {
        cin >> s;
        if(s[0] == 'F' || s[0] == 'B') continue;
        else  {
            fizbuz(stoi(s)+3-i);
            return 0;
        }
    }
}