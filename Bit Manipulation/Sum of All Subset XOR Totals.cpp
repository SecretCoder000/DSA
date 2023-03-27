bool checkBitSet(int n ,int i) {
    return n&(1<<i);
}
int subsetXORSum(vector<int> arr) {
    int n = arr.size();
    int r = 1<<n;
    int ans=0;
    for(int i =1;i<r;i++){
        int myxor = 0;
        for(int j = 0;j<n;j++){
            if(checkBitSet(i,j))
                myxor ^= arr[j];
        }
        ans += myxor;
    }
    return ans;
}