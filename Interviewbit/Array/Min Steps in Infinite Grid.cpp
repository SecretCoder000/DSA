int Solution::coverPoints(vector<int> &a, vector<int> &b) {
    int steps = 0;
    int n = a.size();
    for(int i =1;i<n;i++){
        int row = abs(a[i-1]-a[i]);
        int col = abs(b[i-1]-b[i]);
        steps += max(row,col);
    }
    return steps;
}
