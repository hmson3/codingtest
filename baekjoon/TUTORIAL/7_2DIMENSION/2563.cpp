#include <iostream>
using namespace std;

int main() {

    int arr[101][101] = {};
    int N,x,y;
    int T = 0;
    cin >> N;
    for(int k=0; k<N; k++) {
        cin >> x >> y;
        for (int i = x; i < x+10; i++) {
            for (int j = y; j < y+10; j++) {
                arr[i][j] = 1;
            }
        }    
    }


    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] == 1) T++;
        }
    }
    cout << T;

    
}