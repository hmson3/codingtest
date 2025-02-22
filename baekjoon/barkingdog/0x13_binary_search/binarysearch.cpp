#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int binary(int target) {
    int st = 0;
    int en = n-1;
    while(st <= en) {
        int mid = (st+en) / 2;
        if(a[mid] == target) {
            return mid;
        }
        else if(a[mid] < target) {
            en = mid + 1;
        }
        else if(a[mid] > target) {
            st = mid - 1;
        }
    }
    return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);


}