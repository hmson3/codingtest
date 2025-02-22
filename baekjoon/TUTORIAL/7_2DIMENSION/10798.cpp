#include <iostream>
#include <string>
using namespace std;

int main() {

    char** arr = new char*[5] {};

    for(int i=0; i<5; i++) 
	arr[i] = new char[15] {};

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] == '\0') continue;
            cout << arr[j][i];
        }
    }

    for(int i=0; i<5; i++) delete[] arr[i];
    delete[] arr;

}