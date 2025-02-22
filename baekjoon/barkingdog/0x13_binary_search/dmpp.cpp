#include<bits/stdc++.h>
int a[10] = {2,7,11,11,16,19,22,22,22,32};
int n = 10;

int func(int t) {
    int st = -1;
    int en = n-1;
    while(st < en) {
        int mid = (st+en)/2;
        std::cout << st << ' ' << en << ' ' << mid << '\n';
        if(a[mid] < t) st = mid;
        else en = mid-1;
    }
    return st;
}
int main() {
    std::cout << func(16);
}