class MyCircularQueue {
    int N;
    vector<int> v;   
    int beg = 0;
    int end = 0;
    int size = 0;
public:
    MyCircularQueue(int k): N(k), v(k,0){
        
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        v[end % N] = value;
        end++;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        beg = (beg+1) % N;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()? -1 : v[beg];
    }
    
    int Rear() {
        return isEmpty()? -1 : v[(end+N-1)%N];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == N;
    }
    

};