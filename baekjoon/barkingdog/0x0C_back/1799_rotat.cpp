// 좌표를 돌려서
// n-queen 처럼 한 행씩 확인
// 처음 1 좌표 다 넣고 다 해봄 최악 2^100
// n = 10 일 때 2^19 여전히 시간초과
// 하얀색 바닥과 검은색 바닥 서로 연관 x
// 2^(n/2)

/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

2*4*6*8*10 = 3840  1107
10!!
3*5*7*9 = 945 485
9!!

2
1 1
1 1
2*4
3

3
1 1 1
1 1 1
1 1 1
6*4*2 = 48  45
5*3 = 15 


2n!!
(2n-1)!!

4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

8*6*4*2 = 384  192
7*5*3 = 105    96

적은 이유
비숍이 잡히지 않기 위해서 넘어가는 경우가 있음 그러면 다음 func(cur+2) 부분을 안하고 다음 반복문으로 넘어감
*/

#include <bits/stdc++.h>
using namespace std;

int a[10][10];

bool isused[20];
int cnt,ans;
int n;
int cnnnnt;

void func(int cur) {  
    if(cur >= 2*n-1) {
        ans = max(ans,cnt);
        return;
    }

    int x,y;
    for(int i = 0; i < cur+1; i++) {
        cnnnnt++;
        y = i;
        x = cur - i;
        if(x >= n || y >= n) continue;
        if(a[x][y] == 0) continue;
        if(isused[x-y+n-1]) continue;
        isused[x-y+n-1] = 1;
        cnt++;
        func(cur+2);
        cnt--;
        isused[x-y+n-1] = 0;
    }
    if(cur+2 < 2*n-1) cnnnnt++;
    func(cur+2);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    func(0);
    int tmp = ans;
    ans = 0;
    func(1);
    cout << tmp+ans << '\n';
    cout << cnnnnt  << '\n';
}