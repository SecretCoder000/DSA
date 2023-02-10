#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,long long sum){
    int count =0;
    for(int i =0;i<arr.size();i++)
        if(arr[i]>sum)
            count++;
    return count;
}

int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        long long sum =0;
        vector<int> arr(n,0);
        for(int i =0;i<n;i++) {
            cin>>arr[i];
            sum += arr[i];
        }

        if(sum%n != 0)
            cout<<-1<<endl;
        else
            cout<<solve(arr,sum/n)<<endl;
    }
}