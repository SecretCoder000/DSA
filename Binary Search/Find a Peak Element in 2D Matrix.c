class Solution {
        public:
        int findMax(vector<int> & arr){
            int max=INT_MIN;
            int pos = -1;
            int n = arr.size();
            for(int i =0;i<n;i++)
                if(max<arr[i]){
                    max=arr[i];
                    pos=i;
                }
            return pos;
        }
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int n = mat.size();
            int lo = 0;
            int hi = n-1;
            while(lo <= hi){
                int mid = (hi+lo)>>1;
                int maxPos=findMax(mat[mid]);
                if(mid == 0 && mat[mid][maxPos] > mat[mid+1][maxPos])
                    return {mid,maxPos};
                else if(mid == n-1 && mat[mid][maxPos] > mat[mid-1][maxPos])
                    return {mid,maxPos};
                if(mat[mid][maxPos] > mat[mid+1][maxPos] && mat[mid][maxPos] > mat[mid-1][maxPos])
                    return {mid,maxPos};
                else if(mat[mid][maxPos] < mat[mid+1][maxPos])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
            return {-1,-1};
        }
};