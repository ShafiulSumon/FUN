#include <bits/stdc++.h>

using namespace std;

#define inf 1000000009

int hole_array(int *arr, int low, int mid, int high){
    int a,b;
    int sum=0;
    int mx=-inf;
    for(int i=mid; i>=low; i--){
        sum+=arr[i];
        if(sum>mx) mx=sum;
    }
    a=mx;
    sum=0;
    mx=-inf;
    for(int i=mid+1; i<=high; i++){
        sum+=arr[i];
        if(sum>mx) mx=sum;
    }
    b=mx;
    return a+b;
}

int divide_conquer(int *arr, int low, int high){
    if(low==high) return arr[low];
    int mid=(low+high)/2;
    int left=divide_conquer(arr,low,mid);
    int right=divide_conquer(arr,mid+1,high);
    int both=hole_array(arr,low,mid,high);
    return (max(left,max(right,both)));
}

int main()
{
    int n,arr[100005];
    while(cin>>n){
        if(n==0) break;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int x=divide_conquer(arr,0,n-1);
        if(x<=0) cout<<"Losing streak."<<endl;
        else cout<<"The maximum winning streak is "<<x<<"."<<endl;
    }
    return 0;
}
