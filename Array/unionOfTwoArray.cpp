#include<bits/stdc++.h>
using namespace std;
int doUnion(int a[], int n, int b[], int m)  {
        int max = INT_MIN;
        for(int i =0;i<n;i++)
            max = max<a[i]?a[i]:max;
        for(int i =0;i<m;i++)
            max = max<b[i]?b[i]:max;
        int hash[max];
        for(int i =0;i<max;i++)
            hash[i] = 0;
        for(int i =0;i<n;i++)
            hash[a[i]-1]++;
        for(int i =0;i<m;i++)
            hash[b[i]-1]++;
        
        int count=0;
        for(int i =0;i<max;i++)
            if(hash[i] != 0)
                count++;
        return count;
    }