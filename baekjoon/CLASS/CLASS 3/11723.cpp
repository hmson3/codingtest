#include<bits/stdc++.h>
using namespace std;

bool a[21];
int m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    while(m--) {
        string s;
        cin >> s;
        if(s == "add") {
            int x;
            cin >> x;
            if(a[x]) continue;
            a[x] = true;
        }
        else if(s == "remove") {
            int x;
            cin >> x;
            if(a[x]) a[x] = false;
        }
        else if(s == "check") {
            int x;
            cin >> x;
            if(a[x]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(s == "toggle") {
            int x;
            cin >> x;
            a[x] = 1-a[x];
        }
        else if(s == "all") {
            for(int i = 1; i<=20; i++) {
                a[i] = true;
            }
        }
        else if(s == "empty") {
            for(int i = 1; i<=20; i++) {
                a[i] = false;
            }
        }
    }
}