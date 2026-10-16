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
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Queue elements: ";
    q.display();

    // Filling up the queue
    q.enqueue(40);
    q.enqueue(50);

    std::cout << "Trying to enqueue 6th element (60) to queue: ";
    q.enqueue(60); // This should trigger queue overflow
}
