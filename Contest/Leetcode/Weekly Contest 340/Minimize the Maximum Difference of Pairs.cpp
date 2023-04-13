class Solution {
public:
    bool isPossible(int x,vector<int> & nums,int p){
        int n = nums.size();
        int pairs = 0;
        for(int i =1;i<n;i++){
            if((nums[i]-nums[i-1]) <= x){
                pairs++;
                i++;
            }
        }
        return pairs >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1]-nums[0];
        while (l<r){
            int mid = (l+r)/2;
            if(isPossible(mid,nums,p)){
                r = mid;
            }else
                l = mid+1;
        }
        return l;
    }
};