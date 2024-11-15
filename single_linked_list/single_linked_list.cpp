#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = NULL;
    }
    bool isEmpty() {
        return(head == NULL);
    }

    // Add at the end
    void add(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {//First case
            head = newNode;
        }
        else {
            Node* temp = head;//Temperay pointers starts from head to traverse
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;//The temp now is the last updated
            //The difference between single and doubly is 
            //newNode->prev = temp;
        }
    }

    // Traverse function
    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        // In travaerse function single and doubly are the same
    }
    
    int count() {
        int counter = 0;
        Node* temp = head;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
        // In travaerse function single and doubly are the same
    }
    // Delete 
    void deleteNode(int val) {
        if (isEmpty()) return;
        Node* delPtr = head;
        // If is head
        if (head->data == val) {
            
            head = head->next;
            
            delete delPtr;
            return;
        }
        else {
            Node* prev = NULL;
            
            delPtr = head;
            while (delPtr->data != val) {
                prev = delPtr;
                delPtr = delPtr->next;
            }
            prev->next = delPtr->next;
            delete delPtr;
        }

    }
};

int main() {
    SingleLinkedList myList;

   
    myList.add(10);
    myList.add(20);
    myList.add(30);
    myList.add(40);
    myList.traverse();
    myList.deleteNode(10);
    myList.deleteNode(40);
    myList.traverse();
    myList.add(10);
    myList.add(40);
    myList.traverse();
    cout<<myList.count();
   


    return 0;
}

//// Traverse 
//Node* temp = head;
//while (temp->next != NULL && temp->next->data != val) {
//    temp = temp->next;
//}
//
//if (temp->next != NULL) {
//    Node* nodeToDelete = temp->next;
//    temp->next = temp->next->next;
//    delete nodeToDelete;
//}