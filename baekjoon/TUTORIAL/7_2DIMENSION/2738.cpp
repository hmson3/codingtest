#include <iostream>
#include <string>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int T = 0;
    int** arr = new int*[N];

    for(int i=0; i<N; i++) 
	arr[i] = new int[M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> T;
            arr[i][j] += T;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cout << arr[i][j] << ' ';
        cout << "\n";
    }

    for(int i=0; i<N; i++) delete[] arr[i];

    delete[] arr;

}