#include <iostream>
using namespace std;

class Linkedlist {
    struct Node{
        int val;
        Node* next;
    };
    public:
    Linkedlist(){
        head = NULL;
    }
    ~Linkedlist(){
        Node* node = head;
        while(node) {
            Node* deleteNode = node;
            node = node->next;
            delete  deleteNode;
        }
    }
    void insert(int num){
        Node* n = new Node;
        n->val = num;
        n->next = head;
        head = n;
    }
    int pop(){
        Node* n = head;
        int x = n->val;
        head = head->next;
        delete n;
        return x;
    }
    void print(){
        Node* ptr = head;
        while(ptr) {
            ptr->next ? cout << ptr->val << "->": cout << ptr->val << endl;
            ptr = ptr->next;
        }
    }
    
    void Listreserve(){
        Node* n = head;
        Node* m = NULL;
        while(n){
            Node* next = n->next;
            n->next = m;
            m = n;
            n = next;
        }
        head = m;
    }
    
    private:
        Node* head;
};

int main() {
    Linkedlist n;
    Linkedlist m;
    n.insert(1);
    n.insert(2);
    n.insert(3);
    n.print();
    n.Listreserve();
    n.print();
    n.Listreserve();
    n.print();
    //cout<<"Hello World";

    return 0;
}
