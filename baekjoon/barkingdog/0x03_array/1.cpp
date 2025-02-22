#include <iostream>
#include <vector>
using namespace std;

/*
항의 개수는 1~100,000

수열의 항들은 1~1,000,000
i!=j

두 항의 합은 1~2,000,000
*/

const int MX = 2000001;
int idx[MX];


int main() {
int cnt;//항의 개수
cin >> cnt;

vector<int> v;

while (cnt--) { //벡터에 수열 저장
int tmp;
cin >> tmp;
v.push_back(tmp);
}

int sum; //두 항의 합
cin >> sum;

int ans = 0; //순서쌍의 개수 출력용(정답)

for (auto e : v) { //항이 존재하면 1, 없으면 0인 배열 생성
idx[e]++;
}

for (auto e : v) {
if (sum - e > 0 && idx[sum - e] > 0) {
ans++;
idx[e] = 0;
idx[sum - e] = 0;
}
}

cout << ans;

return 0;

}