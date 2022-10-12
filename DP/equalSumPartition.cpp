#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4][5];
    for(int i =0;i<4;i++)
        for(int j =0;j<5;j++)
            arr[i][j] = i*10+j;
    printf("%d",*(arr[1]+9));
    return 0;
}