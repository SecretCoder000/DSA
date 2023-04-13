vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    ans.push_back(arr[0]);
    for(int i =1;i<n;i++){
        int ind = ans.size()-1;
        int end = ans[ind][1];
        if(arr[i][0] <= end ){
            if(arr[i][1] > end)
                ans[ind][1] = arr[i][1];
        }
        else
            ans.push_back(arr[i]);
    }
    return ans;
}
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
    int n = intervals.size();
    if(n == 0)
        return {newInterval};
    if(newInterval[1] < intervals[0][0]){
        intervals.insert(intervals.begin(),newInterval);
        return intervals;
    }
    for(int i = 0;i<n;i++){
        if(newInterval[0] <= intervals[i][0] && newInterval[1] >= intervals[i][1]){
            intervals[i][0] = newInterval[0];
            intervals[i][1] = newInterval[1];
            break;
        }else if(newInterval[0] <= intervals[i][0] && newInterval[1] > intervals[i][0]){
            intervals[i][0] = newInterval[0];
            break;
        }else if(newInterval[0] <= intervals[i][1] && newInterval[1] > intervals[i][1]){
            intervals[i][1] = newInterval[1];
            break;
        }else if(newInterval[0] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
            return intervals;
        }else if(i == n-1){
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end());
            return intervals;
        }
    }

    return overlappedInterval(intervals);
}