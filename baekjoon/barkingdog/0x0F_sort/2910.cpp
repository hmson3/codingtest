#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[1001];
int sizea = 0;
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool chk = false;
        for(int j = 0; j < sizea; j++) {
            if(num == a[j].first) {
                a[j].second++;
                chk = true;    
            }
        }
        if(!chk) {
            a[sizea].first = num;
            a[sizea].second++;
            sizea++;
        }
    }
    stable_sort(a,a+sizea,cmp);
    for(int i = 0; i < sizea; i++) {
        for(int j = 0; j < a[i].second; j++) {
            cout << a[i].first << ' ';
        }
    }
}