#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct mem
{
    int age;
    string name;
};

mem p[100000];

bool compare(mem a, mem b)
{
    return a.age < b.age;
}

int main() {	
	cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {    
        cin >> p[i].age >> p[i].name;
    }

    stable_sort(p, p + N, compare);

    for (int i = 0; i < N; i++) {
        cout << p[i].age << ' ' << p[i].name << "\n";
    }
}