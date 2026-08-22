#include <iostream>
using namespace std;

class FrontMiddleBackQueue {
    int front;
    int rear;
    int* arr;
    int size;

public:
    FrontMiddleBackQueue() {
        front = -1;
        rear = -1;
        size = 1000;
        arr = new int[size];
    }

    bool isempty() { return front == -1; }
    bool isfull() { return (rear + 1) % size == front; }

    void pushFront(int val) {
        if (isfull()) return;
        if (isempty()) {
            front = rear = 0;
        } else {
            front = (front + size - 1) % size;
        }
        arr[front] = val;
    }

    void pushMiddle(int val) {
        if (isfull()) return;
        if (isempty()) { // handle empty case
            front = rear = 0;
            arr[front] = val;
            return;
        }

        int count = (rear - front + size) % size + 1;
        int mid = (front + count / 2) % size; // insert after front‑middle

        // shift elements right safely
        for (int i = rear; i != (mid - 1 + size) % size; i = (i - 1 + size) % size) {
            arr[(i + 1) % size] = arr[i];
        }

        arr[mid] = val;
        rear = (rear + 1) % size;
    }

    void pushBack(int val) {
        if (isfull()) return;
        if (isempty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }

    int popFront() {
        if (isempty()) return -1;
        int temp = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return temp;
    }

    int popMiddle() {
        if (isempty()) return -1;
        int count = (rear - front + size) % size + 1;
        int mid = (front + (count - 1) / 2) % size; // remove front‑middle
        int temp = arr[mid];

        for (int i = mid; i != rear; i = (i + 1) % size) {
            arr[i] = arr[(i + 1) % size];
        }

        rear = (rear - 1 + size) % size;
        if (front == (rear + 1) % size) front = rear = -1;
        return temp;
    }

    int popBack() {
        if (isempty()) return -1;
        int temp = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        return temp;
    }
};
