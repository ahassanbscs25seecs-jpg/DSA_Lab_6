/*
 * Name: Agha Waleed Hassan
 * CMS ID: 540711
 * Section: BSCS-15-D
 */

#include <iostream>

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
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Queue elements: ";
    q.display();

    std::cout << "Dequeued element: " << q.dequeue() << std::endl;
    std::cout << "Front element: " << q.peekFront() << std::endl;

    // Emptying queue
    while (!q.empty()) {
        q.dequeue();
    }

    std::cout << "Trying to dequeue from empty queue: ";
    q.dequeue(); // This should trigger queue underflow
}