#include<bits/stdc++.h>
using namespace std;

int num[100001];
set<int> dif[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int p,l;
        cin >> p >> l;
        num[p] = l;
        dif[l].insert(p);
    }
    int m;
    cin >> m;
    while(m--) {
        string s;
        cin >> s;
        if(s == "recommend") {
            int ii;
            cin >> ii;
            if(ii == 1) {
                for(int i = 100; i >= 1; i--) {
                    if(dif[i].empty()) continue;
                    cout << *prev(dif[i].end()) << '\n';
                    break;
                }
            }
            else  {
                for(int i = 0; i <= 100; i++) {
                    if(dif[i].empty()) continue;
                    cout << *dif[i].begin() << '\n';
                    break;
                }
            }
        }
        else if(s == "solved") {
            int p;
            cin >> p;
            int ll = num[p];
            dif[ll].erase(p);
        }
        else if(s == "add") {
            int p,l;
            cin >> p >> l;
            num[p] = l;
            dif[l].insert(p);
        }
    }
}