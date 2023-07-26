class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int> full;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        full.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(full.empty())
            return -1;
        stack<int> temp;
        while(!full.empty())
        {
            temp.push(full.top());
            full.pop();
        }
        int val=temp.top();
        temp.pop();
        while(!temp.empty())
        {
            full.push(temp.top());
            temp.pop();
        }
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        if(full.empty())
            return -1;
        stack<int> temp;
        stack<int> temp_full=full;
        while(!temp_full.empty())
        {
            temp.push(temp_full.top());
            temp_full.pop();
        }
        // while(!temp.empty())
        // {
        //     full.push(temp.top());
        //     temp.pop();
        // }
        return temp.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return full.empty();
    }
};