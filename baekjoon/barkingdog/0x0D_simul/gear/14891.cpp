#include<bits/stdc++.h>
using namespace std;

deque<char> gear[4];

void rot(int k, int h) {
    if(h == -1) {
        gear[k].push_back(gear[k].front());
        gear[k].pop_front();
    }
    else {
        gear[k].push_front(gear[k].back());
        gear[k].pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    for(int k = 0; k < 4; k++) {
        for (int i = 0; i < 8; i++) {
            cin >> c;
            gear[k].push_back(c);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int k,h;
        cin >> k >> h;
        queue<pair<int,int>> q;
        q.push({k-1,h});
        int i = k-1;
        int j = -h;
        while(i < 3) {
            if(gear[i][2] != gear[i+1][6]) {
                q.push({i+1,j});
                j = -j;
                i++;
            }
            else {
                break;
            }
        }
        i = k-1;
        j = -h;
        while(i > 0) {
            if(gear[i-1][2] != gear[i][6]) {
                q.push({i-1,j});
                j = -j;
                i--;
            }
            else {
                break;
            }
        }
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            rot(cur.first,cur.second);
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++) {
        if(gear[i][0] == '1') ans += 1<<i;
    }
    cout << ans;
}