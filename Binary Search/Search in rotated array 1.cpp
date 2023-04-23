int search(int nums[], int lo, int hi, int target){
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(nums[mid] == target)
            return mid;
        if(nums[lo] <= nums[mid]){
            if(target < nums[mid] && target >= nums[lo])
                hi = mid-1;
            else
                lo = mid+1;
        }else {
            if(target > nums[mid] && target <= nums[hi])
                lo = mid+1;
            else
                hi = mid-1;
        }
    }
    return -1;
}