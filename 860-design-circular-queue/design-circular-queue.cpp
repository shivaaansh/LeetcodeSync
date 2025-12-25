class MyCircularQueue {
public:
    int k = 0;
    vector<int> q;
    int size = 0;
    int front = 0;
    int rear = 0;
    MyCircularQueue(int k) {
        this->k = k;
        q.assign(k, 0);
        rear = k - 1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear + 1) % k;
        q[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1) % k;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */