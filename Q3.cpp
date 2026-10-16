/*
 * Name: Agha Waleed Hassan
 * CMS ID: 540711
 * Section: BSCS-15-D
 */

#include <iostream>

class Stack {
public:
    // Pushes an element onto the stack
    // Prints error message if stack is full.
    void push(char value) {
        if (full()) {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }

        stack[++top] = value;
    }

    // Removes top element and returns it
    // Popping an empty stack is will return -1 and print
    // an error message.
    char pop() {
        if (empty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }

        char value = stack[top];
        top--;
        return value;
    }

    // Return top element without popping
    // Error message is printed if stack is empty.
    char peek() {
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
    static constexpr int SIZE = 20;
    char stack[SIZE]{};
    int top = -1;
};

int main() {
    Stack tmp;
    std::string word;
    std::string reversed_word;

    do {
        std::cout << "Enter a word: ";
        std::cin >> word;

        if (word.length() > 20) {
            std::cout << "Word exceeds maximum length of 20 characters. Please try again." << std::endl;
        }
    } while (word.length() > 20);

    for (char ch : word) {
        tmp.push(ch);
    }

    while (!tmp.empty()) {
        reversed_word += static_cast<char>(tmp.pop());
    }

    std::cout << "Reversed word: " << reversed_word << std::endl;
}
