/*
 * Name: Agha Waleed Hassan
 * CMS ID: 540711
 * Section: BSCS-15-D
 */

#include <iostream>

// Linked list implementation of stack
// Is dynamic. No size restriction
class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* topNode = nullptr;

public:
    // No full condition for linked list implementation
    void push(int value) {
        // create a new node and link it to the current top
        Node* newNode = new Node{value, topNode};
        topNode = newNode;
    }

    int pop() {
        if (topNode == nullptr) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }

        // Save old top node for deletion
        Node* temp = topNode;
        int value = temp->data;
        topNode = topNode->next;
        delete temp;

        return value;
    }

    int peek() {
        if (topNode == nullptr) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return topNode->data;
    }
    
    void display() {
        if (topNode == nullptr) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }

        Node* current = topNode;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool empty() {
        return topNode == nullptr;
    }   
};

int main() {
    Stack s;
    s.push(5);
    s.push(15);
    s.push(25);

    std::cout << "Stack elements: ";
    s.display();

    std::cout << "Popped element: " << s.pop() << std::endl;
    std::cout << "Top element: " << s.peek() << std::endl;

    while (!s.empty()) {
        s.pop();
    }

    std::cout << "Trying to pop from empty stack: ";
    s.pop(); // This should trigger stack underflow

    return 0;
}