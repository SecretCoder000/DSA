#include<bits/stdc++.h>
using namespace std;
void kSorted(vector<int> & arr,int k){
    priority_queue<int,vector<int>,greater<int>> que;
    int i =0;
    for(i;i<arr.size();i++){
        que.push(arr[i]);
        while(que.size() > k){
            arr[i-k] = que.top();
            que.pop();
        }
    }
    while(!que.empty()){
        arr[i-k] = que.top();
        i++;
        que.pop();
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<arr.size();i++)
        cin>>arr[i];
    int k ;
    cin>>k;
    kSorted(arr,k+1);
    cout<<endl;
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<"\t";
    return 0;
}