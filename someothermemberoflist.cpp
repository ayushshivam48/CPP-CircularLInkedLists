#include <iostream>
#include <list>
using namespace std;

int main() {
    // Create an empty list of integers
    list<int> myList;

    // 1. Push elements to the front of the list
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    cout << "After pushing 30, 20, and 10 to the front: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // 2. Pop an element from the front of the list
    myList.pop_front(); // Removes 30
    cout << "After popping from the front: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // 3. Push elements to the back of the list
    myList.push_back(40);
    myList.push_back(50);
    cout << "After pushing 40 and 50 to the back: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // 4. Pop an element from the back of the list
    myList.pop_back(); // Removes 50
    cout << "After popping from the back: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
