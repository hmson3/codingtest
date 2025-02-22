#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,T = 0;
    char c[101] = "";
    cin >> N >> c;

    
    for (int i = 0; i < N; i++) {
        T += int(c[i])-'0';
    }
    cout << T;
    return 0;
}