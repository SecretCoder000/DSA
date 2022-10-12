#include<bits/stdc++.h>
using namespace std;
void insertHeap(vector<int> & arr,int val){
    arr.push_back(val);
    int i = arr.size()-1;
    while(i > -1){
        int p = i/2;
        if(arr[p] < arr[i]){
            swap(arr[p],arr[i]);
            i = p;
        }
        else 
            return;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int val ;
    cin>>val;
    insertHeap(arr,val);
    cout<<endl<<"After insertion : ";
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<"\t";
    return 0;
}