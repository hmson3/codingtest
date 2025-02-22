#include <bits/stdc++.h>
using namespace std;

int a[10][10];
bool isused1[20];  // column을 차지하고 있는지
bool isused2[20];  // / 방향 대각선을 차지하고 있는지
vector<pair<int,int>> v;
int cnt,ans;
int n,vsize;
void func(int cur) {  // cur번째 row에 말을 배치할 예정임
    if(cur == vsize) {
        ans = max(ans,cnt);
        return;
    }

    int x,y;
    tie(x,y) = v[cur];
    if(!isused1[x+y] && !isused2[x-y+n-1]) {
        cnt++;
        isused1[x+y] = 1;
        isused2[x-y+n-1] = 1;
        func(cur+1);
        cnt--;
        isused1[x+y] = 0;
        isused2[x-y+n-1] = 0;
        
    }
    func(cur+1);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                v.push_back({i, j});
            }
        }
    }
    vsize = v.size();
    func(0);
    cout << ans;
}