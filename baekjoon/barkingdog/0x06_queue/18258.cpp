#include <bits/stdc++.h>
using namespace std;

int dat[2000005];
int head,tail;

void push(int x) {
    dat[tail++] = x;
}
int pop() {
    if(head == tail) return -1;
    return dat[head++];
}
int size() {
    return tail-head;
}
int empty() {
    return tail == head;
}
int front() {
    if(head == tail) return -1;
    return dat[head];
}
int back() {
    if(head == tail) return -1;
    return dat[tail-1];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if(s == "pop") {
            cout << pop() << "\n";
        }
        else if(s == "front") {
            cout << front() << "\n";
        }
        else if(s == "back") {
            cout << back() << "\n";
        }
        else if(s == "size") {
            cout << size() << "\n";
        }
        else if(s == "empty") {
            cout << empty() << "\n";
        }
    }
}