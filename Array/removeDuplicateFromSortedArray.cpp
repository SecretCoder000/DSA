int removeDuplicates(vector<int>& nums) {
    int i =0;
    int prev = nums[0];
    int k=0;
    while(i<nums.size()){
        if(prev != nums[i]){
            nums[k++] = prev;
            prev  = nums[i];
        }
        if(i == nums.size()-1)
            nums[k++] = prev;
        i++;
    }
    return k;
}
//method 2
int removeDuplicates2(vector<int>& nums) {
    int i =0;
    int prev = nums[0];
    int k=0;
    int count = 0;
    while(i<nums.size()){
        if(prev == nums[i]){
            count++;
            if(count<=2)
                nums[k++] = nums[i];
        }else {
            nums[k++] = nums[i];
            prev = nums[i];
            count = 1;
        }
        i++;
    }
    return k;
}