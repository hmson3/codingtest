#include <iostream>
using namespace std;

int main()
{
    int N,M,i,j,c = 0;
    cin >> N >> M;
    
    int *arr = new int[N] {};
    for (int k = 0; k < N; k++) {
        arr[k] = k + 1;
    }

    for (int k = 0; k < M; k++) {
        cin >> i >> j;
        for(int q = 0; q < (j-i+1)/2; q++) {
            c = arr[i-1+q];
            arr[i-1+q] = arr[j-1-q];
            arr[j-1-q] = c;
        }
    }

    for (int k = 0; k < N; k++) {
        cout << arr[k] << ' ';
    }

    delete[] arr; 
    return 0;
}