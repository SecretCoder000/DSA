class Solution{
public:
    int findPos(vector<int> & a,int k){
        int n = a.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(a[mid] <= k){
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return lo;
    }
    int median(vector<vector<int>> &mat, int r, int c){
        int lo = 1;
        int hi = 1e6;
        int k = (r*c)/2;
        int ans = INT_MAX;
        while (lo<=hi){
            int mid = (lo+hi)>>1;
            int count = 0;
            for(int i =0;i<r;i++)
                count += findPos(mat[i],mid);
            if(count > k)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return lo;
    }