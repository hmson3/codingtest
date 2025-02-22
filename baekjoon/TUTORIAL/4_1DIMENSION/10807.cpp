#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,n,v;
    int T = 0;
    cin >> N;

    int *array = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> n;
        array[i] = n;
    }
    cin >> v;

    for (int i = 0; i < N; i++) {
        if (v == array[i]){
            T++;
        }
    }
    cout << T << endl;

    delete[] array; 

    return 0;
}
