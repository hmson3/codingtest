#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,M,j,k,c = 0;
    cin >> N >> M;
    
    int *arr = new int[N] {};
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> j >> k;
        c = arr[j-1];
        arr[j-1] = arr[k-1];
        arr[k-1] = c;
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    delete[] arr; 
    return 0;
}