#include<iostream>
#include<string>

using namespace std;

class Node {
    public:
    char elem;
    Node* next;
    friend class Stack;
};

class Stack {
    Node* head;
    int num;
public:
    Stack() : head(nullptr), num(0) { }
    ~Stack() {
        while(!empty()) {
            pop();
        }
        num = 0;
    }
    int size() const { return num; }
    bool empty() const {
        return (head == nullptr);
    }
    int top() const {
        if (empty()) return -1;
        return head->elem;
    }
    void push(char e) {
        Node* newNode = new Node;
        newNode->elem = e;
        newNode->next = head; 
        head = newNode;
        num++;
    }
    char pop() {
        if (empty()) return 0; 
        else {
            Node* temp = head;
            char a = temp->elem;
            head = temp->next;
            delete temp;
            num--;
            return a;
        }
    }
};

int main() {
    Stack l,r;
    string s;
    char d;
    getline(cin,s);
    for(int i = 0; i < s.length(); i++) {
        l.push(s[i]);
    }
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        getline(cin,s);
        if(s[0] == 'L') {
            if(!l.empty()) {
                r.push(l.pop());
            }
        }
        else if(s[0] == 'D') {
            if(!r.empty()) {
                l.push(r.pop());
            }
        }
        else if(s[0] == 'B') {
            if(!l.empty()) {
                d = l.pop();
            }
        }
        else if(s[0] == 'P') {
            l.push(s[2]);
        }    
    }
    while(!l.empty()) {
        r.push(l.pop());
    }
    while(!r.empty()) {
        cout << r.pop();
    }
    cout << "\n";

    return 0;
}