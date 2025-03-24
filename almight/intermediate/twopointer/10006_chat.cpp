#include<bits/stdc++.h>
using namespace std;

int countNiceFragments(int n, int m, vector<int>& l, vector<int>& c, vector<int>& a) {
    unordered_map<int, int> target_count, current_count;
    long long window_size = 0, match_count = 0;

    // 목표 패턴 저장
    for (int i = 0; i < m; i++) {
        target_count[c[i]] = l[i];
        window_size += l[i];
        if(window_size > 1000001) {
            cout << 0;
            return 0;
        }
    }

    // 첫 윈도우 초기화
    for (int i = 0; i < window_size; i++) {
        current_count[a[i]]++;
    }

    // 첫 윈도우가 정답인지 확인
    if (current_count == target_count) {
        match_count++;
    }

    // 슬라이딩 윈도우 이동
    for (int i = window_size; i < n; i++) {
        // 새 요소 추가
        current_count[a[i]]++;

        // 가장 오래된 요소 제거
        int remove_index = i - window_size;
        if (--current_count[a[remove_index]] == 0) {
            current_count.erase(a[remove_index]);
        }

        // 패턴 검사
        if (current_count == target_count) {
            match_count++;
        }
    }

    return match_count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> l(m), c(m), a(n);

    for (int i = 0; i < m; i++) cin >> l[i];
    for (int i = 0; i < m; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << countNiceFragments(n, m, l, c, a) << endl;

    return 0;
}