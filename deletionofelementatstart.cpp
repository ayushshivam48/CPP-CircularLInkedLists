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

    void deleteAtStart(){

        if(head==NULL){
            return;
        }

        Node* temp = head;
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

        head = head->next;
        tail->next = head;
        free(temp);
    }

};

int main() {

    CircularLL cll;
    cll.insertAtStart(5);
    cll.insertAtStart(4);
    cll.insertAtStart(3);
    cll.insertAtStart(2);
    cll.insertAtStart(1);
    cll.display();
    cll.deleteAtStart();
    cll.display();
}
