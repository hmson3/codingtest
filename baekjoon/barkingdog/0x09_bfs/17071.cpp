#include<bits/stdc++.h>
using namespace std;

int soo_zzak[500002];
int soo_hol[500002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q = {};
    int s,b;
    cin >> s >> b;
    fill(soo_hol, soo_hol+500001,-1);
    fill(soo_zzak, soo_zzak+500001,-1);
    int time = 0;
    q.push(s);
    soo_zzak[s] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(soo_hol[cur] == time || soo_zzak[cur] == time) {
            b += time;
            time++;
            if(b > 500000) {
                cout << -1;
                return 0;
            }
        }
        if(soo_hol[b] != -1 && (time-1)%2 == soo_hol[b]%2) {
            cout << time-1;
            return 0;
        }
        if(soo_zzak[b] != -1 && (time-1)%2 == soo_zzak[b]%2) {
            cout << time-1;
            return 0;
        }
        for(int nx : {cur-1,cur+1,2*cur}) {
            if(nx < 0 || nx > 500000) continue;
            if(time%2 == 0) {
                if(soo_zzak[nx] != -1) continue;
                soo_zzak[nx] = time;
                q.push(nx);
            } 
            else {
                if(soo_hol[nx] != -1) continue;
                soo_hol[nx] = time;
                q.push(nx);
            }
        }
    }
    cout << -1;
    return 0;
}