#include <iostream>
using namespace std;

int main() {
    int N,M;
    int MM = 0;
    int arr[100] = {};
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < N-2; i++) {
        for(int j = i+1; j < N-1; j++) {
            for(int k = j+1; k < N; k++) {
                if(arr[i]+arr[j]+arr[k] > MM && arr[i]+arr[j]+arr[k] <= M) MM = arr[i]+arr[j]+arr[k];
            }
        }
    }
    cout << MM;
}