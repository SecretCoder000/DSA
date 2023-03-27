int search(int arr[], int N){
    int myxor = 0;
    for(int i =0;i<N;i++)
        myxor = myxor ^ arr[i];
    return myxor;
}