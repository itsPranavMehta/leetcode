class MyCircularQueue {
public:
    vector<int> vec;
    int front,rear,sz,curr;
    MyCircularQueue(int k) {
        vec.assign(k,0);
        front=0;
        rear=0;
        sz=k;
        curr=0;
    }
    
    bool enQueue(int value) {
        if(isFull())  return 0;
        vec[rear++]=value;
        rear%=sz;
        curr++;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()) return 0;
        front++;
        curr--;
        front%=sz;
        return 1;
    }
    
    int Front() {
        if(curr==0) return -1;
        return vec[front];
    }
    
    int Rear() {
        
        if(curr==0) return -1;
        return vec[(rear-1+sz)%sz];
    }
    
    bool isEmpty() {
        return curr==0;
    }
    
    bool isFull() {
        
        return curr==sz;
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