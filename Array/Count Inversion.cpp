#define ll long long

class Solution{
public:
    ll merge(ll arr[],ll l,ll m,ll r){
        ll nL = m-l+1;
        ll nR = r-m;
        ll left[nL];
        ll right[nR];
        ll countInversion = 0;
        for(ll i = l ;i<=m;i++)
            left[i-l] = arr[i];
        for(ll i = m+1;i<=r;i++)
            right[i-m-1] = arr[i];
        ll i,j,k;
        i=j=0;
        k=l;
        while (i<nL && j<nR){
            if(left[i] <= right[j])
                arr[k] = left[i++];
            else{
                arr[k] = right[j++];
                countInversion = countInversion+(m+1-i-l);
            }
            k++;
        }
        while (i<nL){
            arr[k] = left[i++];
            k++;
        }
        while (j<nR){
            arr[k] = right[j++];
            k++;
        }
        return countInversion;
    }
    ll mergeSort(ll arr[],ll l,ll r){
        ll countInversion = 0;
        if(l < r){
            ll mid = (l+r)>>1;
            countInversion += mergeSort(arr,l,mid);
            countInversion += mergeSort(arr,mid+1,r);
            countInversion += merge(arr,l,mid,r);
        }
        return countInversion;
    }
    long long int inversionCount(long long arr[], long long N){
        return mergeSort(arr,0,N-1);
    }