#include<bits/stdc++.h>
using namespace std;
const int LMT = 100;
int soo_zzak[LMT+2];
int soo_hol[LMT+2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q = {};
    int s,b;
    cin >> s >> b;
    fill(soo_hol, soo_hol+LMT+1,-1);
    fill(soo_zzak, soo_zzak+LMT+1,-1);
    int time = 0;
    q.push(s);
    soo_zzak[s] = 0;
    while(!q.empty()) { // 레벨별로 하지 않을 시 그 레밸을 다 돌기 전 time이 커질 수 있음 
        int cur = q.front(); q.pop();
        cout << cur << ' '<< soo_zzak[cur] << ' ' << soo_hol[cur] << ' ' << time << '\n';
        if(soo_hol[cur] == time || soo_zzak[cur] == time) {
            time++;}
        for(int nx : {cur-1,cur+1,2*cur}) {
            if(nx < 0 || nx > LMT) continue;
            if(time%2 == 0) {
                if(soo_zzak[nx] != -1) continue;
                soo_zzak[nx] = time;
                if(soo_hol[nx] == -1) q.push(nx);
            } 
            else {
                if(soo_hol[nx] != -1) continue;
                soo_hol[nx] = time;
                if(soo_zzak[nx] == -1) q.push(nx);
            }
        }
    }
    int ans = -1;
    time = 0;
    while (b <= 500000) {
        if(time%2 == 0 && soo_zzak[b] <= time) {
            ans = time;
            break;
        }
        else if(time%2 == 1 && soo_hol[b] <= time) {
            ans = time;
            break;

        }
      b += ++time;
    }
    cout << ans;
    return 0;
}
/*
*/