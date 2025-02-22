#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,n,MAX,MIN = 0;
    cin >> N;
    
    int *array = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> n;
        array[i] = n;
    }
    MAX = array[0];
    MIN = array[0];
    for (int i = 0; i < N; i++) {
        if (array[i] > MAX) {
            MAX = array[i];
        }
        else if (array[i] < MIN) {
            MIN = array[i];
        }
    }

    cout << MIN << ' ' << MAX << endl;

    delete[] array; 
    return 0;
}