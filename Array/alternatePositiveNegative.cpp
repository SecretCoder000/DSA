#include<bits/stdc++.h>
using namespace std;
void segreggate(int arr[],int n){
    int i,j;
    i=0;
    j=n-1;
    while(i<j){
        if(arr[i]>=0)
            i++;
        if(arr[j]<0)
            j--;
        if(arr[i] < 0 && arr[j] >= 0)
            swap(arr[i++],arr[j++]);
    }
}
void rearrange(int arr[], int n) {
    int f;
    f=-1;
    for(int i =0;i<n;i++){
        if(f == -1 && (arr[i] >= 0 && i%2 != 0 || arr[i] < 0 && i%2 == 0)){
            f = i;
            continue;
        }
        if( f != -1 && ((arr[f] < 0 && arr[i] >= 0)|| (arr[f] >= 0 && arr[i] < 0))){
            int temp = arr[i];
            for(int j = i;j>f;i--)
                arr[j] = arr[j-1];
            arr[f] = temp;
            i = f;
            f=-1;
        }
    }
}
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int i,j;
    i=0;
    j=1;
    for(int k = 0;k<n;k++){
        if(nums[k] < 0){
            ans[j] = nums[k];
            j += 2;
        }else {
            ans[i] = nums[k];
            i += 2;
        }
    }
    return ans;
}
int main(){
    int n=12;
    int arr[n] = {9, 4, -2, -1, 5, 0, -5, -3, 2,-7,-10,-11};
    segreggate(arr,n);
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"\t";
    
}