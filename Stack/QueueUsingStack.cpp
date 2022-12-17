class MyQueue {
public:
    stack<int> st;
    MyQueue() {

    }

    void push(int x) {
        st.push(x);
    }

    int pop() {
        if(st.empty())
            return -1;
        stack<int> temp;
        while(st.size() > 1){
            temp.push(st.top());
            st.pop();
        }
        int ans = st.top();
        st.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return ans;
    }

    int peek() {
        if(st.empty())
            return -1;
        stack<int> temp;
        while(st.size() > 1){
            temp.push(st.top());
            st.pop();
        }
        int ans = st.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return ans;
    }

    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */