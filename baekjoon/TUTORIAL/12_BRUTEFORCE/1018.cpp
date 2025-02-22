#include <iostream>
#include <string>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;

    char** arr = new char*[N];
    for(char i=0; i<N; i++) 
	arr[i] = new char[M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }

    int C = 0;
    int mc = 64;

    for (int i = 0; i < N-7; i++) {
        for (int j = 0; j < M-7; j++) {

            C = 64;
            for(int k = i; k < i+8; k++) {
                for(int l = j; l < j+8; l++) {
                    if((k+l-i-j)%2 == 0) {
                        if(arr[k][l] == 'B') C--;
                    }
                    else {
                        if(arr[k][l] == 'W') C--;
                    }
                }
            }
            if(C < mc) {
                mc = C;
            }
            C = 64;
            for(int k = i; k < i+8; k++) {
                for(int l = j; l < j+8; l++) {
                    if((k+l-i-j)%2 == 0) {
                        if(arr[k][l] == 'W') C--;
                    }
                    else {
                        if(arr[k][l] == 'B') C--;
                    }
                }
            }
            if(C < mc) {
                mc = C;
            }
        }
    }
    cout << mc;
    for(int i=0; i<N; i++) delete[] arr[i];
    delete[] arr;

}