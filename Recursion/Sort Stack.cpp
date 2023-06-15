void solve(int val,stack<int> & s){
    if(s.empty() || s.top() < val){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    solve(val,s);
    s.push(temp);
}
void sort(){
    if(s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    sort();
    solve(temp,s);
}