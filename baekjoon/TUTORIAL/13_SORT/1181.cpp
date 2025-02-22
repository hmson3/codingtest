#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {		
        return a < b;		
	}
	else {					
		return a.length() < b.length();	
	}
}


int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, tmp;
	cin >> N;

	string s[20000];

	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	sort(s, s + N, compare);

	for (int i = 0; i < N; i++) {
		if (s[i] == s[i - 1]) continue;
        cout << s[i] << "\n";
	}


	return 0;
}