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
        Node* temp = head;
        char a = temp->elem;
        head = temp->next;
        delete temp;
        num--;
        return a;
    }
};

int main() {
    Stack s;
    int l, N;   
    string c;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        getline(cin,c);
        l = c.length();
        for(int j = 0; j < l; j++) {
            if(j == l-1) {
                s.push(c[j]);
                while(!s.empty()) cout << s.pop();
                break;
            }
            else if(c[j] == ' ') {
                while(!s.empty()) cout << s.pop();
                cout << ' ';
                continue;
            }
            s.push(c[j]);
        }
        cout << "\n";
    }
    
    return 0;
}