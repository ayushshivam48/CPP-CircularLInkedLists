#include <iostream>
#include <list>
using namespace std;

int main() {
    // Create a list of integers
    list<int> myList = {10, 20, 30, 40, 50};

    // 1. Using list::begin() and list::end()
    // Traverse the list from the beginning to the end using an iterator
    cout << "Forward Traversal using list::begin() and list::end():" << endl;
    list<int>::iterator it;
    for (it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";  // Dereference the iterator to access the element
    }
    cout << endl;

    // 2. Using list::rbegin() and list::rend()
    // Traverse the list in reverse order using a reverse iterator
    cout << "Reverse Traversal using list::rbegin() and list::rend():" << endl;
    list<int>::reverse_iterator rit;
    for (rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        cout << *rit << " ";  // Dereference the reverse iterator to access the element
    }
    cout << endl;

    // 3. Using std::advance to move an iterator forward
    // Move an iterator to the third element in the list
    it = myList.begin();     // Start at the beginning
    advance(it, 2);          // Move the iterator forward by 2 positions
    cout << "Element at the third position after advancing by 2: " << *it << endl;

    // 4. Using a range-based loop
    // Traverse the list using a range-based loop
    cout << "Forward Traversal using a range-based loop:" << endl;
    for (int value : myList) {
        cout << value << " ";  // Access each element directly
    }
    cout << endl;

    // 5. Reverse traversal without reverse iterators (using standard iterators)
    // Traverse the list in reverse order manually
    cout << "Reverse Traversal using standard iterators:" << endl;
    it = myList.end();  // Start from the end (past-the-last element)
    do {
        --it;  // Move the iterator back to the previous element
        cout << *it << " ";
    } while (it != myList.begin());
    cout << endl;

    return 0;
}
