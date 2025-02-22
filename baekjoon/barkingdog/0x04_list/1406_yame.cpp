#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    pre[nxt[addr]] = pre[addr];
    nxt[pre[addr]] = nxt[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << "\n";
}


int main(void) {
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string s;
    cin >> s;
    int cur = 0;
    for(auto c : s) {
        insert(cur,c);
        cur++;
    }
    int n;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if(s == "L") {
            if(pre[cur] != -1) {
                cur = pre[cur];
            }
        }
        else if(s == "D") {
            if(nxt[cur] != -1) cur = nxt[cur];
        }
        else if(s == "B") {
            if(pre[cur] != -1) {
                erase(cur);
                cur = pre[cur];
            }
        }
        else if(s == "P") {
            cin >> c;
            insert(cur,c);
            cur = nxt[cur];
        }
    }

    traverse();

}