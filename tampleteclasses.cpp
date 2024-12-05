#include<iostream>
using namespace std;

template<typename T>  // Correct spelling is 'template'
// Template class
class Node { 
public:
    T val;
    Node* next;

    Node(T data) {  // Constructor name should match the class name
        val = data;
        next = NULL;
    }
};

int main() {
    Node<int>* node1 = new Node<int>(3);
    cout << node1->val << endl;

    Node<char>* node2 = new Node<char>('a');
    cout << node2->val << endl;

    return 0;
}
