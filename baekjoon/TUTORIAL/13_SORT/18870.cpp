#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int p[1000000];
int s[1000000];
int rr[1000000];


bool compare(int a, int b)
{
    return a < b;
}

int main() {	
	cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N,k=0;
    cin >> N;

    for (int i = 0; i < N; i++) {    
        cin >> p[i];
        s[i] = p[i];
    }

    sort(s, s + N, compare);
    for (int i = 0; i < N; i++) {
		if (s[i] == s[i - 1]) continue;
        else rr[k++] = s[i];
	}

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < k; j++) {
            if (rr[j] == p[i]) cout << j << ' ';
        }
    }
}