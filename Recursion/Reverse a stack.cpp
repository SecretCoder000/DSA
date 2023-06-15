void push(stack<int> & st,int x){
    if(st.empty())  {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    push(st,x);
    st.push(temp);
}
void Reverse(stack<int> &st){
    if(st.size() == 1) return;
    int temp = st.top();
    st.pop();
    Reverse(st);
    push(st,temp);
}