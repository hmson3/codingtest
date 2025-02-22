#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin,s);

    while(s[0] != '.') {
        stack<char> t = {};
        int check = 0;
        for(char c : s) {
            if(c == '(') t.push(c);
            else if(c == ')') {
                if(t.empty() || t.top() != '(') check++;
                else t.pop();
            }
            else if(c == '[') t.push(c);
            else if(c == ']') {
                if(t.empty() || t.top() != '[') check++;
                else t.pop();
            }
        }
        if(!t.empty() || check) cout << "no\n";
        else cout << "yes\n";
        getline(cin,s);
    }

}