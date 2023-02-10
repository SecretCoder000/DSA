void reverse(int arr[],int i,int j){
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void rotate(vector<int> & arr, int k) {
    int n = arr.size();
    k = k%n;
    reverse(arr.data(),0,n-k-1);
    reverse(arr.data(),n-k,n-1);
    reverse(arr.data(),0,n-1);
}