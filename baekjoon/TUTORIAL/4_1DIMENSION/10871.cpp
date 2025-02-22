#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,n,X;
    int T = 0;
    cin >> N >> X;

    int *array = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> n;
        array[i] = n;
    }
    for (int i = 0; i < N; i++) {
        if (array[i] < X) {
            cout << array[i] << " ";
        }
    }


    delete[] array; 

    return 0;
}
