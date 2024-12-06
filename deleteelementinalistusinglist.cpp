#include <iostream>
#include <list>
#include <algorithm> // For std::find
using namespace std;

int main() {
    // Create a list of integers
    list<int> myList = {10, 20, 30, 40, 50};

    // Function to display the list
    auto displayList = [](const list<int>& l) {
        for (int val : l) {
            cout << val << " ";
        }
        cout << endl;
    };

    // Display initial list
    cout << "Initial list: ";
    displayList(myList);

    // 1. Erase a single element by value
    auto it = find(myList.begin(), myList.end(), 30);
    if (it != myList.end()) {
        myList.erase(it);
    }
    cout << "After erasing element with value 30: ";
    displayList(myList);

    // 2. Erase a single element by position
    it = myList.begin();  // Point to the first element
    advance(it, 1);       // Move to the second element (20)
    myList.erase(it);     // Erase the second element
    cout << "After erasing the second element: ";
    displayList(myList);

    // 3. Erase a range of elements
    it = myList.begin();  // Point to the first element
    auto it_end = it;     // Initialize it_end to the start of the range
    advance(it, 1);       // Move to the second element
    advance(it_end, 3);   // Move it_end to the fourth element
    if (it_end != myList.end()) {
        myList.erase(it, it_end); // Erase elements from the second to the fourth
    }
    cout << "After erasing elements from the second to the fourth: ";
    displayList(myList);

    // 4. Erase all elements
    myList.clear();       // Clears all elements in the list
    cout << "After clearing all elements: ";
    displayList(myList);

    return 0;
}
