class MyCircularQueue {
private:
    vector<int> queue;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        queue.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        queue[rear] = value;
        rear = (rear + 1) % capacity;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return queue[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        int index = (rear - 1 + capacity) % capacity;
        return queue[index];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};