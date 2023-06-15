class Solution {
    int solve(string str){
        int sum = 0;
        for(auto it : str){
            sum = sum*2+(it-'0');
        }
        return sum;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int total = pow(2,n);
        vector<bool> a(total+1,false);
        for(int i =0;i<n;++i){
            int temp = solve(nums[i]);
            a[temp] = true;
        }

        for(int i=0;i<=total;++i){
            if(!a[i]){
                total = i;
                break;
            }
        }
        string ans;
        while(total>0 || ans.size() < n){
            int r = total%2;
            ans.push_back('0'+r);
            total /= 2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};