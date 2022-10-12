#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSubSeqOfSize3(int arr[],int n){
    vector<int> left;
    vector<int> right;
    int min = INT_MAX;
    for(int i =0;i<n;i++){
        if(min > arr[i])
            min = arr[i];
        left.push_back(min);
    }
    int max = INT_MIN;
    for(int i =n-1;i>-1;i--){
        if(max < arr[i])
            max = arr[i];
        right.insert(right.begin(),max);
    }
    for(int i =0;i<n;i++){
        if(left[i] < arr[i] && arr[i] < right[i])
            return vector<int> {left[i],arr[i],right[i]};
    }
    return vector<int> {};
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    vector<int> ans = sortedSubSeqOfSize3(arr,n);
    cout<<"Sorted Subseq : ";
    for(int i =0;i<ans.size();i++)
        cout<<ans[i]<<"\t";
    return 0;
}