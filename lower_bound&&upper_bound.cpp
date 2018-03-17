#include <bits/stdc++.h>

using namespace std;

int main()
{
	int arr[]={1,2,2,2,3,4,4,5,6,6,7,8,9,9,9,10}; ///16 element
	
	vector<int> v(arr,arr+16);
	sort(v.begin(),v.end());/// the vector must be sorted 
	
	vector<int> :: iterator it1,it2;
	
	it1=upper_bound(v.begin(),v.end(),2);
	it2=lower_bound(v.begin(),v.end(),2);
	
	/// zero based indexing
    	
	cout<<"upper bound position: "<<it1-v.begin()-1<<endl;
    	cout<<"lower bound position: "<<it2-v.begin()<<endl;
	
	return 0;
}

