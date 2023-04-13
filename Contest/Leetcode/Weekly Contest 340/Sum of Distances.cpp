#define ll long long
class Solution {
public:
    vector<ll> distance(vector<int>& nums) {

        map<int,pair<vector<ll>,ll>> temp;
        ll n = nums.size();
        vector<ll> ans(n,0);
        for(ll i =0;i<n;i++){
            if(temp.find(nums[i]) == temp.end()){
                temp[nums[i]].first.push_back(i);
                temp[nums[i]].second = i;
            }
            else {
                temp[nums[i]].first.push_back(i);
                temp[nums[i]].second += i;
            }
        }
        for(auto itr : temp){
            if(itr.second.first.size()==1) continue;
            vector<ll> arr = itr.second.first;
            ll totlSum = itr.second.second;
            n = arr.size();
            ll leftSum=0;
            for(ll i =0;i<n;i++){
                ll sum = (i*arr[i]-leftSum);
                sum +=  (totlSum-arr[i]-leftSum-(n-1-i)*arr[i]);
                leftSum += arr[i];
                ans[arr[i]] = sum;
            }
        }
        return ans;
    }
};