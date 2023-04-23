int minOperations(vector<int>& nums) {
    int nonOne = 0;
    int totalGcd = nums[0];
    bool isOne = false;
    int n = nums.size();
    for(int i =0;i<n;i++){
        totalGcd = __gcd(totalGcd,nums[i]);
        if(!isOne && nums[i] == 1)
            isOne = true;
        else if(nums[i] > 1)
            nonOne++;
    }
    if(totalGcd != 1)
        return -1;
    if(isOne)
        return nonOne;
    int minOperation = INT_MAX;
    for(int i=0;i<n;i++){
        int totalGcd = nums[i];
        for(int j=i;j<n;j++){
            totalGcd = __gcd(totalGcd,nums[j]);
            if(totalGcd == 1){
                minOperation = min(minOperation,j-i);
                break;
            }
        }
    }
    return minOperation+nonOne-1;
}