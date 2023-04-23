bool contains(queue<int> que,int n){
    while(!que.empty()){
        if(que.front() == n)
            return true;
        que.pop();
    }
    return false;
}
void removeAdd(queue<int> & que,int n) {
    queue<int> st;
    while(!que.empty()){
        if(que.front() != n)
            st.push(que.front());
        que.pop();
    }
    st.push(n);
    while(!st.empty()){
        que.push(st.front());
        st.pop();
    }
}
int pageFaults(int n, int c, int pages[]){
    queue<int> que;
    int pageFault = 0;
    for(int i =0;i<n;i++){
        if(contains(que,pages[i]))
            removeAdd(que,pages[i]);
        else {
            pageFault++;
            que.push(pages[i]);
            if(que.size() > c)
                que.pop();
        }
    }
    return pageFault;
}