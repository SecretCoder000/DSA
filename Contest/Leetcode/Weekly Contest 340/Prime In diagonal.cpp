class Solution {
public:
    bool isPrime(int n){
        if(n<=1)
            return false;
        int end = sqrt(n);
        for(int i =2;i<=end;i++)
            if(n%i==0)
                return false;
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int i;
        i=0;
        int n = nums.size();
        int m = nums[0].size();
        int ans = 0;
        while(i<n && i < m){
            if(isPrime(nums[i][i]))
                ans = max(ans,nums[i][i]);
            if(isPrime(nums[i][n-1-i]))
                ans = max(ans,nums[i][n-1-i]);
            i++;
        }
        return ans;
    }
};