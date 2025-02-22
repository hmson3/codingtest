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
    void pop() {
        if (!empty()) {
            Node* temp = head;
            int a = temp->elem;
            head = temp->next;
            delete temp;
            num--;
        }
    }
};

int main() {
    Stack s,s2,s3;

    int ele, N;
    int n = 1;
    int check = 0;
    string c;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> ele;

        while(true) {
            if (ele == s.top()) {
                s.pop();
                s2.push(-1);
                break;
            }
            else if (ele > s.top()) {
                s.push(n);
                s2.push(1);
                n++;
            }
            else if (ele < s.top()) {
                check = 1;
                break;
            }                
        }
    }

    if (check) cout << "NO\n";
    else {
        while(!s2.empty()) {
            s3.push(s2.top());
            s2.pop();
        }
        while(!s3.empty()) {
            if(s3.top() == 1) cout << "+\n";
            else cout << "-\n";
            s3.pop();
        }
    }
    return 0;
}