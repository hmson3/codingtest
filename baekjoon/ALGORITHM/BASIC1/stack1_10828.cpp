#include<iostream>
#include<string>

using namespace std;

class Node {
    public:
    int elem;
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
    void push(int e) {
        Node* newNode = new Node;
        newNode->elem = e;
        newNode->next = head; 
        head = newNode;
        num++;
    }
    int pop() {
        if (empty()) return -1;
        Node* temp = head;
        int a = temp->elem;
        head = temp->next;
        delete temp;
        num--;
        return a;
    }
};

int main() {
    Stack s;
    int ele, N;   
    string c;
    cin >> N;
    for(int i = 0; i < N; i++) {
        
        cin >> c;

        if(c == "push") {
            cin >> ele;
            s.push(ele);
        }
        else if(c == "pop") {
            cout << s.pop() << "\n";
        }
        else if(c == "size") {
            cout << s.size() << "\n";
        }
        else if(c == "empty") {
            cout << s.empty() << "\n";
        }
        else if(c == "top") {
            cout << s.top() << "\n";
        }
    }
    
    return 0;
}