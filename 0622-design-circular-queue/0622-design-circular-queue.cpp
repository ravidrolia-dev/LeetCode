class MyCircularQueue {
public:
    int front = -1;
    int rear = -1;
    int* arr;
    int size;
    MyCircularQueue(int k) {
        arr = new int [k];
        size = k;
    }
    
    bool enQueue(int value) {
        int k = size;
        if(front == -1){
            front = rear = 0;
            arr[rear] = value;
        }else{
            if((rear+1)%k == front){
                return false;
            }else{
                rear = (rear+1)%k;
                arr[rear] = value;
            }
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front+ 1)%size;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return arr[front];
    }
    
    int Rear() {
        if(rear == -1)return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear +1)%size == front;
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