#include <iostream>
#include "list.h"
using namespace std;

int main () {
    List numList;
    numList.create();   // Empty List
    
    numList.size();
    numList.append(34); // 34
    numList.append(43);
    numList.append(23);
    numList.append(76);
    numList.print();
    cout << "SIZE: " << numList.size() << endl;
    cout << numList.pop() << " ";
    cout << numList.pop() << " ";
    cout << numList.popFront() << " ";
    cout << "SIZE: " << numList.size() << endl;
    cout << "Thank you. Exiting." << endl;
    numList.delete_list();
    cout << "List Deleted" << endl;
    return 0;
}
