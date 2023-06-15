int Solution::solve(vector<int> &A, int B) {
    int lo,hi;
    lo=0;
    hi = A.size()-1;
    int ind = -1;
    if(A.size() == 1){
        if(A[0] <= B)
            return 1;
        else
            return 0;
    }
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(A[mid] == B){
            ind = mid;
            break;
        }else if(B < A[mid]){
            if(B > A[mid-1]){
                ind = mid-1;
                break;
            }
            hi = mid-1;
        }else{
            if(B < A[mid+1]){
                ind = mid;
                break;
            }
            lo = mid+1;
        }

    }
    if(ind == -1)
        return ind;
    while(ind < A.size()-1 && A[ind+1] == B){
        ind++;
    }
    return ind+1;
}
