// 
#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> eggcase[8];
bool brocheck[8];
int max_broken;

void func(int k, int broken) {
    if(k == n) {
        max_broken = max(max_broken,broken);
        return;
    }
    if(brocheck[k]) {
        func(k+1,broken);
        return;
    }
    bool not_loof = true;
    for(int i = 0; i < n; i++) {
        if(brocheck[i] == 1 || i == k) continue;
        not_loof = false;
        int bro = broken;
        eggcase[k].first -= eggcase[i].second;
        if(eggcase[k].first <= 0) {
            brocheck[k] = 1;
            bro++;
        }
        eggcase[i].first -= eggcase[k].second;
        if(eggcase[i].first <= 0) {
            brocheck[i] = 1;
            bro++;
        }
        func(k+1,bro);
        eggcase[k].first += eggcase[i].second;
        eggcase[i].first += eggcase[k].second;
        brocheck[k] = 0;
        brocheck[i] = 0;
    }
    if(not_loof) {
        func(k+1,broken);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> eggcase[i].first >> eggcase[i].second;
    }
    func(0,0);
    cout << max_broken;
}