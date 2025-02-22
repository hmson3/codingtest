#include <iostream>
using namespace std;

int x[100000] = {};
int y[100000] = {};
int sx[100000] = {};
int sy[100000] = {};

void merge(int start, int end){
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if (x[i] < x[j] || (x[i] == x[j] && y[i] <= y[j])) { 
            sy[k] = y[i];
            sx[k++] = x[i++];
        }
        else {
            sy[k] = y[j];
            sx[k++] = x[j++];
        }
    }
    while (i <= mid) {
        sy[k] = y[i];
        sx[k++] = x[i++];
    }
    while (j <= end) {
        sy[k] = y[j];
        sx[k++] = x[j++];
    }
 
    for (int i = start; i <= end; i++) {
        x[i] = sx[i];
        y[i] = sy[i];
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
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    
    merge_sort(0, N-1);

    for(int i = 0; i < N; i++) {
        cout << x[i] << ' ' << y[i] << "\n";
    }

    return 0 ;
}