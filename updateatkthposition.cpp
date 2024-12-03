#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

class CircularLL{
    public:

    Node* head;

    CircularLL(){
        head = NULL;
    }

    void display(){
        if(head == NULL) return;

        Node* temp = head;
        do{
            cout << temp->val << "->";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }

    void insertAtStart(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
            return;
        }

        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void instertAtEnd(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
            return;
        }

        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
    }

    void insertAtKthPosition(int val, int k){
        Node* new_node = new Node(val);

        if(k == 1) {
            insertAtStart(val);
            return;
        }

        Node* temp = head;
        for(int i = 1; i < k - 1; i++){
            temp = temp->next;
            if(temp == head) {
                cout << "Position out of bounds" << endl;
                return;
            }
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void updateAtKthPosition(int k, int new_val){
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        for(int i = 1; i < k; i++){
            temp = temp->next;
            if(temp == head) {
                cout << "Position out of bounds" << endl;
                return;
            }
        }

        temp->val = new_val;
    }
};

int main() {
    CircularLL cll;
    cll.insertAtStart(3);
    cll.insertAtStart(2);
    cll.insertAtStart(1);
    cll.display();
    cll.instertAtEnd(4);
    cll.display();
    cll.insertAtKthPosition(5, 2);
    cll.display();
    
    cll.updateAtKthPosition(2, 2);
    cll.display();
    
}
