#include<bits/stdc++.h>
using namespace std;

pair<int,int> soo[100002];
vector<int> v;
int dx[3] = {1,-1,0};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q = {};
    int s,b;
    cin >> s >> b;

    soo[s].first = 1;
    q.push(s);
    while(soo[b].first == 0) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < 3; i++) {
            int nx = cur + dx[i];
            if(nx  == cur) nx = 2*cur;
            if(nx < 0 || nx >= 100002) continue;
            if(soo[nx].first != 0) continue;
            
            soo[nx].first = soo[cur].first + 1;
            soo[nx].second = cur;
            q.push(nx);
        }
          
    }

    int tmp = b;
    while(true) {
        v.push_back(tmp);
        if(tmp == s) break;
        tmp = soo[tmp].second;
    }
    cout << soo[b].first-1 << '\n';
    for(int i = v.size()-1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
}