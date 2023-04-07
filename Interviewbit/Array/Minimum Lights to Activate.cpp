https://www.interviewbit.com/problems/minimum-lights-to-activate/
int solve(vector<int> &arr, int b) {
    int steps = 0;
    int i = 0;
    int n = arr.size();
    while (i<n){
        int index=-1;
        for(int j = i+b-1;j>=i;j--) {
            if (arr[j] == 1){
                index = j;
                break;
            }
        }
        if(index!=-1){
            i = index+b;
            steps++;
            continue;
        }
        for(int j = i-1;j>=i-b+1 && j > -1;j--){
            if (arr[j] == 1){
                index = j;
                break;
            }
        }
        if(index!=-1){
            i = index+b;
            steps++;
        }else
            return -1;
    }
    return steps;
}