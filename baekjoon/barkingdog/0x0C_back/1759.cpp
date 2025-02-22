#include<bits/stdc++.h>
using namespace std;

int l,c;
char a[20];
int arr[20];
bool isused[20];
int mo;
int ja;

void func(int k) {
    if(k == l) {
        if(mo>=1 && ja >= 2) {
            for(int i = 0; i < l; i++) {
                cout << a[arr[i]];
            }
            cout << '\n';
        }
        return;
    }
    int st = 0;
    if(k != 0) st = arr[k-1] + 1;
    for(int i = st; i < c; i++) {
        arr[k] = i;
        char ck = a[i];
        if(ck == 'a' ||ck == 'e' ||ck == 'o' ||ck == 'u' ||ck == 'i') mo++;
        else ja++;
        func(k+1);
        if(ck == 'a' ||ck == 'e' ||ck == 'o' ||ck == 'u' ||ck == 'i') mo--;
        else ja--;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for(int i = 0; i < c; i++)
            cin >> a[i];
    sort(a,a+c);
    func(0);
}