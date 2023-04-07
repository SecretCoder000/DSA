vector<int> spiralOrder(vector<vector<int>>& arr) {
    int startRow,endRow,startCol,endCol;
    int n = arr.size();
    int m = arr[0].size();
    startRow=startCol=0;
    endRow=n-1;
    endCol=m-1;
    int count = n*m;
    vector<int> ans;
    while(count>0){
        for(int i =startCol;i<=endCol && count > 0 ;i++,count--)
            ans.push_back(arr[startRow][i]);
        startRow++;
        for(int i = startRow;i<=endRow && count > 0;i++,count--)
            ans.push_back(arr[i][endCol]);
        endCol--;
        for(int i = endCol;i>=startCol && count > 0;i--,count--)
            ans.push_back(arr[endRow][i]);
        endRow--;
        for(int i = endRow;i>=startRow && count > 0;i--,count--)
            ans.push_back(arr[i][startCol]);
        startCol++;
    }
    return ans;
}