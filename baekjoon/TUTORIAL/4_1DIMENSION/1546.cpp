#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,n = 0;
    double MAX,T;
    cin >> N;

    double *array = new double[N];
    for (int i = 0; i < N; i++) {
        cin >> n;
        array[i] = n;
    }

    MAX = array[0];
    for (int i = 0; i < N; i++) {
        if (array[i] > MAX) {
            MAX = array[i];
        }
    }

    for (int i = 0; i < N; i++) {
        T += array[i]/MAX*100;
    }
    cout << fixed;
    cout.precision(6);
    cout << T/N << endl;

    delete[] array; 

    return 0;
}