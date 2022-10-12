#include<bits/stdc++.h>
using namespace std;
void deleteHeap(vector<int> & arr){
    arr[1] = arr[arr.size()];
    arr.pop_back();
    int i =1;
    while(i<=arr.size()){
        if(i*2>arr.size())
            break;
        if(i*2+1 > arr.size()){
            if(arr[i*2] > arr[i]){
                swap(arr[i*2],arr[i]);
                i = i*2;
            }else 
                break;
        }
        else {
            int left = arr[i*2];
            int right = arr[i*2+1];
            int max = left>right?i*2:i*2+1;
            if(arr[max] > arr[i]){
                swap(arr[max],arr[i]);
                i = max;
            }
            else
                break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =1;i<=n;i++)
        cin>>arr[i];
    deleteHeap(arr);
    cout<<endl<<"After Deletion : ";
    for(int i =1;i<=arr.size();i++)
        cout<<arr[i]<<"\t";
    return 0;
}