#include <stddef.h>
#include <iostream>
#include <unistd.h>

using namespace std;

class List{
    private:
    struct Node{
        int val;
        Node* next;
    };
    Node* head;
    int count;
//    Node* last;
    public:
    int pop() {  //used for popping at the end of list
        if (head == nullptr) {
            cout << "empty list" << endl;
            return -1;
        }
        else if (size() == 1) {
            Node* currNode = head;
            int retVal = currNode->val;
            delete currNode;
            head = nullptr;
            
            count--;
            return retVal;
        }
        else {
            Node* currNode = head;
            while (currNode->next->next != nullptr) {
                currNode = currNode->next;
            }
            /* currNode now points to second to last node */
            Node* lastNode = currNode->next;
            int retVal = lastNode->val;
            delete lastNode;
            currNode->next = nullptr;
            
            count--;
            return retVal;
        }
    }
    int popFront() {  //used for popping at the end of list
        if (head == nullptr) {
            cout << "empty list" << endl;
            return -1;
        }
        else if (size() == 1) {
            Node* currNode = head;
            int retVal = currNode->val;
            delete currNode;
            head = nullptr;
            
            count--;
            return retVal;
        }
        else {
            Node* currNode = head;
            head = head->next;
            currNode->next = nullptr;
            int retVal = currNode->val;
            delete currNode;
            
            count--;
            return retVal;
        }
    }
    void create(){
        head = nullptr;
        count = 0;
//        last = nullptr;
    }
    int size(){
        return count;
    }
    void append(int newVal){ //used for pushing onto the end of the queue
        Node* NewNode = new Node;
        NewNode->val = newVal;
        NewNode->next = nullptr;
        if(head == nullptr){  //check for size 0
            head = NewNode;
        }
        else{  //check for size > 0
            Node* currNode = head;
            while (currNode->next != nullptr) {
                currNode = currNode->next;
            }
            currNode->next = NewNode;
        }
        count++;
    }
    void delete_list(){  //frees all memory
        Node* curr = head;
        Node* prev = head;
        while(curr != nullptr){
            curr = curr->next;
            delete prev;
            prev = curr;
        }
        count = 0;
    }
    void print() {  //print for test will become play
        Node* curr = head;
        if(curr != nullptr) {
            while(curr != nullptr) {
                cout << curr->val << " ";
                curr = curr->next;
            }
        }
        else{
            cout << "empty queue" << endl;
        }
    }
};
