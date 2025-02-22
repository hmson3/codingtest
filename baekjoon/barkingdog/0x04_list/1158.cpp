#include <bits/stdc++.h>
using namespace std;


int main(void) {
    
    int N,K;
    cin >> N >> K;
    list<int> L = {};
    auto cur  = L.begin();
    for(int i = 1; i <= N; i++) {
        L.push_back(i);
    }
    cout << '<';
    for(int i = 0; i < K; i++) {
            cur++;
            if(cur == L.end()) cur = L.begin();
        }
    cout << *cur << ", ";
    cur = L.erase(cur);
    while(L.size() != 1) {
        for(int i = 0; i < K-1; i++) {
            if(cur == L.end()) cur = L.begin();
            cur++;
        }
        cout << *cur << ", ";
        cur = L.erase(cur);
        if(cur == L.end()) cur = L.begin();
    }
    cout << L.front() << '>';
}