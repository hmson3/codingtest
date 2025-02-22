#include <iostream>
using namespace std;
 
int main() {
 
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
 
	int MAX = -1;	
	int in;	
	for (int i = 0; i < 9; i++) {
		if (arr[i] > MAX) {
			MAX = arr[i];
			in = i;
		}
	}
	cout << MAX << "\n";

	cout << in + 1;
	return 0;
}