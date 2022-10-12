#include<bits/stdc++.h>
using namespace std;
void reverseInGroup(vector<int> & arr,int k){
    int temp;
    for(int i =0;i<arr.size();i=i+k){
        if(i+k>arr.size())
            k = arr.size()-i; 
        temp=k/2;
        int j = i;
        int l = i+k-1;
        while (temp--){
            swap(arr[j++],arr[l--]);
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    reverseInGroup(arr,k);
    cout<<"After Swapping : ";
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}