vector<int> Solution::solve(vector<int> &a) {
    int n = a.size();
    int i,j;
    i=j=0;
    while(j<n){
        if(a[j] == 0){
            swap(a[j],a[i]);
            i++;
        }
        j++;
    }
    return a;
}
