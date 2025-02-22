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
    void pop() {
        if (!empty()) {
            Node* temp = head;
            head = temp->next;
            delete temp;
            num--;
        }
    }
};

int main() {
    Stack s;
    int l, N;
    int check = 0;
    string c;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        getline(cin,c);
        l = c.length();
        check = 0;
        s.~Stack();
        for(int j = 0; j < l; j++) {
            if(c[j] == '(') {
                s.push(c[j]);
            }
            else if(c[j] == ')') {
                if (s.empty()) check = 1;
                s.pop();
            }
        }
        if (!s.empty()) check = 1;
        if (check) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}