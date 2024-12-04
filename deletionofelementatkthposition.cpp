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

class CircularLL {
public:

    Node* head;

    CircularLL() {
        head = NULL;
    }

    void display() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->val << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void insertAtStart(int val) {
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            return;
        }

        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void deleteAtStart() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {  // Check if the list is empty
            return;
        }

        // If the list has only one node
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* tail = head;

        // Traverse to the second-to-last node
        while (tail->next->next != head) {
            tail = tail->next;
        }

        Node* lastNode = tail->next;  // This is the last node
        tail->next = head;  // Update the second-to-last node's next to head
        delete lastNode;  // Delete the last node
    }

    void deleteAtKthPosition(int k) {
        if (head == NULL) {  // If the list is empty
            return;
        }

        if (k == 1) {  // If the position is the first node
            deleteAtStart();
            return;
        }

        Node* temp = head;

        // Traverse to the (k-1)th node
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
            if (temp == head) {  // If k is greater than the number of nodes
                cout << "Position out of bounds" << endl;
                return;
            }
        }

        // If the node to delete is the last one
        if (temp->next->next == head) {
            deleteAtEnd();
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;  // Free the memory of the node to delete
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

    cll.deleteAtKthPosition(3);  // Deletes the node at 3rd position
    cll.display();

    cll.deleteAtKthPosition(1);  // Deletes the node at the 1st position
    cll.display();

    cll.deleteAtKthPosition(3);  // Attempts to delete a node at an out-of-bounds position
    cll.display();
}
