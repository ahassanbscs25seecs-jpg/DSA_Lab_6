/*
 * Name: Agha Waleed Hassan
 * CMS ID: 540711
 * Section: BSCS-15-D
 */

#include <iostream>
#include <limits>

class Queue {
private:
    constexpr static int SIZE = 5;
    int front = -1;
    int rear = -1;
    int queue[SIZE];

public:
    void enqueue(int value) {
        if (full()) {
            std::cout << "Queue overflow!" << std::endl;
            return;
        }

        if (empty()) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }

    void display() {
        if (empty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        for (int i = front; i <= rear; ++i) {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }

    bool full() {
        return rear == SIZE - 1;
    }

    bool empty() {
        return front == -1;
    }

    int peekFront() {
        if (empty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return queue[front];
    }

    int dequeue() {
        if (empty()) {
            std::cout << "Queue underflow!" << std::endl;
            return -1;
        }

        int value = queue[front];
        if (front == rear) { // Queue has only one element
            front = rear = -1; // Reset to empty state
        } else {
            front++;
        }
        return value;
    }

    bool contains(int value) {
        if (empty()) {
            return false;
        }

        for (int i = front; i <= rear; ++i) {
            if (queue[i] == value) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Queue customers;
    int choice = 0;

    do {
        std::cout << "\nCustomer Service Queue\n"
                  << "1. Add customer\n"
                  << "2. Serve next\n"
                  << "3. View next\n"
                  << "4. Display queue\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";

        /* Prevent non integer input */
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                return 0;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Enter a number from 1 to 5.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            if (customers.full()) {
                std::cout << "Cannot add a customer: the queue is blocked because "
                             "rear is at index 4. This linear queue cannot reuse "
                             "freed slots until it becomes empty.\n";
                break;
            }

            int token;
            std::cout << "Enter customer token number: ";
            if (!(std::cin >> token)) {
                if (std::cin.eof()) {
                    return 0;
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid token. Enter an integer.\n";
                break;
            }
            if (customers.contains(token)) {
                std::cout << "Customer with token " << token
                          << " is already in the queue.\n";
                break;
            }
            customers.enqueue(token);
            std::cout << "Customer added.\n";
            break;
        }
        case 2:
            if (customers.empty()) {
                std::cout << "No customers to serve; the queue is empty.\n";
            } else {
                std::cout << "Serving customer token "
                          << customers.dequeue() << ".\n";
            }
            break;
        case 3:
            if (customers.empty()) {
                std::cout << "No next customer; the queue is empty.\n";
            } else {
                std::cout << "Next customer token: "
                          << customers.peekFront() << '\n';
            }
            break;
        case 4:
            std::cout << "Customer tokens in arrival order: ";
            customers.display();
            break;
        case 5:
            std::cout << "Exiting customer service queue.\n";
            break;
        default:
            std::cout << "Invalid choice. Enter a number from 1 to 5.\n";
            break;
        }
    } while (choice != 5);
}
