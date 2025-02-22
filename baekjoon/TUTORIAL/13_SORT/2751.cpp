#include <iostream>
using namespace std;

int a[1000000] = {};
int s[1000000] = {};

void merge(int start, int end){
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) 
            s[k++] = a[i++];
        else
            s[k++] = a[j++];
    }
    while (i <= mid)
        s[k++] = a[i++];
    while (j <= end)
        s[k++] = a[j++];
 
    for (int i = start; i <= end; i++) {
        a[i] = s[i];
    }
}

void merge_sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, end);
    }
}

int main() {
    int N;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    merge_sort(0,N-1);
    
    for(int i = 0; i < N; i++) {
        cout << a[i] << "\n";
    }

    return 0 ;
}