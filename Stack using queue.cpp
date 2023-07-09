class Stack {
	// Define the data members.
    queue<int> q1, q2;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1=q2;
        while(!q2.empty())
            q2.pop();
    }

    int pop() {
        if(q1.empty())
            return -1;
        int val=q1.front();
        q1.pop();
        return val;
        // Implement the pop() function.
    }

    int top() {
        // Implement the top() function.
        if(q1.empty())
            return -1;
        return q1.front();
    }
};