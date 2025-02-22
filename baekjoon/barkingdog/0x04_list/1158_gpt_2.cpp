#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    list<int> L;

    // 1부터 N까지의 숫자 리스트에 넣기
    for (int i = 1; i <= N; i++) {
        L.push_back(i);
    }

    auto cur = L.begin();
    cout << '<';

    // K번째마다 cur를 이동시키기
    for (int i = 0; i < K-1; i++) {
        cur++;
    }

    // 첫 번째 숫자 출력
    cout << *cur;
    cur = L.erase(cur);  // 숫자 삭제 후 반복자 갱신
    if (cur == L.end()) 
        cur = L.begin();
    if(L.empty()) {
        cout << ">";
        return 0;
    }
    else cout << ", ";
    // 리스트에 하나만 남을 때까지
    while (L.size() > 1) {
        for (int i = 0; i < K-1; i++) {
            cur++;
            if (cur == L.end()) 
                cur = L.begin();
        }

        cout << *cur << ", ";
        cur = L.erase(cur);  // 숫자 삭제 후 반복자 갱신
        if (cur == L.end()) 
            cur = L.begin();
    }

    // 마지막 남은 숫자 출력
    cout << L.front() << '>';

    return 0;
}
