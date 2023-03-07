long long countSubarrays(vector<int>& nums, int mnK, int mxK) {
    long long count = 0;
    int n = nums.size();
    int j,i;
    i=j=0;
    pair<int,int> mn,mx;
    mn = {INT_MAX,-1};
    mx = {INT_MIN,-1};
    while (i < n && j < n){
        if(nums[j] >= mx.first)
            mx = {nums[j],j};
        if(nums[j] <= mn.first)
            mn = {nums[j],j};
        if(mn.first < mnK || mx.first > mxK ){
            mn = {INT_MAX,-1};;
            mx = {INT_MIN,-1};
            j++;
            i = j;
            continue;
        }
        if(mn.first == mnK && mx.first == mxK)
            count = count + min(mn.second,mx.second)-i+1;

        j++;
    }
    return count;
}