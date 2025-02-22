#include <iostream>
#include <string>
using namespace std;

int main() {

    int M = 0;
    int x = 0,y = 0;
    int** arr = new int*[9];

    for(int i=0; i<9; i++) 
	arr[i] = new int[9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] > M) {
                M = arr[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << arr[x][y] << "\n" << x+1 << " " << y+1 << endl;
    
    for(int i=0; i<9; i++) delete[] arr[i];

    delete[] arr;

}