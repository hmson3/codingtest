#include <bits/stdc++.h>
using namespace std;

int n,m,r,c;
int ans;
int board[50][50];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i,j});
            if(board[i][j] == 2) chicken.push_back({i,j});
        }
    }
    vector<int> b(chicken.size(),1);
    int mn = 9999999;
    for(int i = 0; i < m; i++) {
        b[i] = 0;
    }
    do {
        int dis = 0;
        for(auto h : house) {
            int tmp = 9999999;
            for(int i = 0; i < chicken.size(); i++) {
                if(b[i] == 0) {
                    tmp = min(tmp,abs(chicken[i].first-h.first)+abs(chicken[i].second-h.second));
                }
            }
            dis += tmp;
        }
        mn = min(mn,dis);

    } while(next_permutation(b.begin(),b.end()));
    cout << mn;

}