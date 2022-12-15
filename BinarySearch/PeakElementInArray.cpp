int peakIndexInMountainArray(vector<int>& arr) {
    int lo =0;
    int hi = arr.size()-1;
    while(lo<hi){
        if(arr[lo] > arr[hi]){
            hi--;
        }
        else if(arr[lo] < arr[hi]) {
            lo++;
        }
        else {
            lo++;
            hi--;
        }
    }
    return lo;
}