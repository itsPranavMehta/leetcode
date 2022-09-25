class MyCircularQueue {
public:
    vector<int> ls;
    int count,rear,front,sz;
    
    MyCircularQueue(int k):ls(k), count(0),front(0),rear(-1),sz(k) {
    }
    
    bool enQueue(int value) 
    {
        if(count==sz)   return false;
        rear=(rear+1)%sz;
        ls[rear]=value;
        count++;
        return true;
    }
    
    bool deQueue() 
    {
        if(count==0)    return false;
        count--;
        front=(front+1)%sz;
        return true;
    }
    
    int Front() 
    {
        return isEmpty()?-1:ls[front];
    }
    
    int Rear() {
        return isEmpty()?-1:ls[rear];
        
    }
    
    bool isEmpty() 
    {
        return count==0;    
    }
    
    bool isFull() {
        return count==sz;
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