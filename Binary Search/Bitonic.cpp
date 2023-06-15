int solve(vector<int> &A, int B) {
    int lo,hi;
    lo = 0;
    hi = A.size()-1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(A[mid] == B)
            return mid;
        else if(mid =0 && A[mid-1] <= A[mid]){
            if(B < A[mid])
                hi = mid-1;
            else
                lo = mid+1;
        }else {
            if(B < A[mid])
                lo = mid+1;
            else
                hi = mid-1;
        }
    }
    return -1;
}