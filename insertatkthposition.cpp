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

    Node* head ;

    CircularLL(){
        head=NULL;
    }

    void display(){

        Node* temp = head;
        do{
            cout<<temp->val<<"->";
            temp = temp->next;
        }while(temp!=head);
        cout<<endl;
    }

    void printCircular(){
        Node* temp=head;
        for(int i=0;i<15;i++){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<endl;
    }

    void insertAtStart(int val){

        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            new_node->next = head; 
            return;
        }

        Node* tail = head;
        while(tail->next!=head){
            tail=tail->next;
        }
        //now tail node is pointing to the last node

        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void instertAtEnd(int val){

        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            new_node->next = head; 
            return;
        }

        Node* tail = head;
        while(tail->next!=head){
            tail=tail->next;
        }
        //here tail will be pointing to last node

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
};

int main() {

    CircularLL cll;
    cll.insertAtStart(3);
    cll.insertAtStart(2);
    cll.insertAtStart(1);
    cll.display();
    cll.printCircular();
    cll.instertAtEnd(5);
    cll.display();
    cll.insertAtKthPosition(4,4);
     cll.display();
}
