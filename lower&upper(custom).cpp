#include <bits/stdc++.h>

using namespace std;

#define ll                        long long
#define sf                        scanf
#define pf                        printf


int n,arr[1000],val;

int LowerBound(int val)
{
	int low = 0, high = n-1, ans=n;
	
	while(low<high){
		int mid = low + (high-low)/2;
		if(val<=arr[mid]){
			ans = mid;
			high = mid;
		}
		else low = mid+1;
	}
	return ans;
}

int UpperBound(int val)
{
	int low = 0, high = n-1, ans = n;
	
	while(low<high){
		int mid = low + (high-low)/2;
		if(val<arr[mid]){
			ans = mid;
			high = mid;
		}
		else low = mid+1;
	}
	return ans;
}


int main()
{
	
	sf("%d",&n);
	for(int i=0; i<n; i++){
		sf("%d",&arr[i]);
	}
	sf("%d",&val);
	
	sort(arr,arr+n);
	
	int Low = LowerBound(val);
	int low = lower_bound(arr,arr+n,val)-arr;
	
	pf("myLow: %d, default_low: %d\n",Low,low);
	
	int High = UpperBound(val);
	int high = upper_bound(arr,arr+n,val)-arr;
	
	pf("myHigh: %d, default_high: %d\n",High,high);
	

	return 0;
}
