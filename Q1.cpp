/*
 * Name: Agha Waleed Hassan
 * CMS ID: 540711
 * Section: BSCS-15-D
 */

#include <iostream>

// Array implementation of stack with
// a fixed size of 5 elements.
class Stack {
public:
    // Pushes an element onto the stack
    // Prints error message if stack is full.
    void push(int value) {
        if (full()) {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }

        stack[++top] = value;
    }

    // Removes top element and returns it
    // Popping an empty stack is will return -1 and print
    // an error message.
    int pop() {
        if (empty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }

        int value = stack[top];
        top--;
        return value;
    }

    // Return top element without popping
    // Error message is printed if stack is empty.
    int peek() {
        if (empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }

        return stack[top];
    }

    void display() {
        if (empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }

        for (int i = top; i >= 0; --i) {
            std::cout << stack[i] << " ";
        }
        std::cout << std::endl;
    }

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == SIZE - 1;
    }

private:
    static constexpr int SIZE = 5;
    int stack[SIZE]{};
    int top = -1;
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack currently: ";
    s.display();

    std::cout << "Popped element is: " << s.pop() << std::endl;
    std::cout << "Top element is: " << s.peek() << std::endl;
    std::cout << "Stack after popping: ";
    s.display();

    s.push(30);
    s.push(40);
    s.push(50);

    std::cout << "Trying to push 6th element (60) to stack: ";
    s.push(60); // This should trigger stack overflow

    for (int i = 0; i < 5; ++i) {
        s.pop();
    }

    std::cout << "Trying to pop from empty stack: ";
    s.pop(); // This should trigger stack underflow
}
