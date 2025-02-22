#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
    int y = 0;
    int m = 0;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        y += (a / 30 +1)*10;
        m += (a / 60 +1)*15;
    }
    if(m > y) cout << "Y " << y;
    else if(m == y) cout << "Y M " << y;
    else cout << "M " << m;

	
	return 0;
}