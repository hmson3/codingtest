#include<bits/stdc++.h>
using namespace std;

int n,s;
int arr[20];
int per[20];
bool isused[20];
int ans;

void func(int k) {
    if(k == 6) {
        for(int i = 0; i < 6; i++) {
            cout << per[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 0;
    if(k != 0) st = arr[k-1] + 1;
    for(int i = st; i < n; i++) {
        arr[k] = i;
        func(k+1); 
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n != 0) {
        for(int i = 0; i < n; i++) {
            cin >> per[i];
        }
        sort(arr,arr+n);
        func(0);
        cout << '\n';
        cin >> n;
    }
    
}