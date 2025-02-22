#include<bits/stdc++.h>
using namespace std;

int soo[100002];
int cnt[100002];
int dx[3] = {1,-1,0};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q = {};
    int s,b;
    cin >> s >> b;
    fill(soo, soo+100001,-1);
    soo[s] = 0;
    cnt[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == b) break;
        for(int i = 0; i < 3; i++) {
            int nx = cur + dx[i];
            if(nx  == cur) nx = 2*cur;
            if(nx < 0 || nx >= 100002) continue;
            if(soo[nx] == -1) {
                soo[nx] = soo[cur] + 1;
                cnt[nx] += cnt[cur];
                q.push(nx);
            }
            else if(soo[nx] == soo[cur]+1){
                cnt[nx] += cnt[cur];
            }
        }
    }
    cout << soo[b] << '\n' << cnt[b];

}