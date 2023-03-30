struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
vector<int> JobScheduling(Job arr[], int n) {
    vector<pair<int,int>> jobs;
    int maxDeadline = INT_MIN;
    for(int i =0;i<n;i++){
        jobs.push_back({arr[i].profit,arr[i].dead});
        if(arr[i].dead > maxDeadline)
            maxDeadline = arr[i].dead;
    }
    sort(jobs.begin(),jobs.end(),greater<>());
    vector<int> vis(maxDeadline,-1);
    int totalJobs = 0;
    int totalProfit = 0;
    for(int i=0;i<n;i++){
        int deadline = jobs[i].second;
        int profit = jobs[i].first;
        for(int j = deadline-1;j>=0;j--){
            if(vis[j] == -1){
                vis[j] = profit;
                totalJobs++;
                totalProfit += profit;
                break;
            }
        }
    }
    return {totalJobs,totalProfit};
}