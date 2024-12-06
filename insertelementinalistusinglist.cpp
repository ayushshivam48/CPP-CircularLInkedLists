#include <iostream>
#include <list>
using namespace std;

int main() {
    // Create an empty list of integers
    list<int> myList;

    // 1. Insert a single element at the beginning using list::insert with str_itr (start iterator)
    list<int>::iterator str_itr = myList.begin();  // Start iterator
    myList.insert(str_itr, 10);
    cout << "After inserting 10 at the beginning: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // 2. Insert a single element at the end using end_itr (end iterator)
    list<int>::iterator end_itr = myList.end();  // End iterator
    myList.insert(end_itr, 20);
    cout << "After inserting 20 at the end: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // 3. Insert multiple elements at a specific position
    list<int>::iterator it = myList.begin();
    advance(it, 1);  // Move the iterator to the second position
    myList.insert(it, 3, 15);  // Insert three 15s at the second position
    cout << "After inserting three 15s at the second position: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // 4. Insert elements from another list using range insertion
    list<int> anotherList = {30, 40, 50};
    end_itr = myList.end();  // Update end iterator
    myList.insert(end_itr, anotherList.begin(), anotherList.end());
    cout << "After inserting elements from another list at the end: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // 5. Insert an element before a specific position using str_itr
    str_itr = myList.begin();
    advance(str_itr, 2);  // Move the iterator to the third position
    myList.insert(str_itr, 25);  // Insert 25 before the third position
    cout << "After inserting 25 before the third position: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
