#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> vec;

void recursion(int x){
    /// base case:
    if(x==n){
        int sz = vec.size();
        if(sz==0) return;
        for(int i=0; i<sz; i++){
            cout<<vec[i];
        }
        cout<<endl;
        return;
    }

    /// make binary bit 0:
    vec.push_back(0);
    recursion(x+1);
    vec.erase(vec.end()-1);

    /// make binary bit 1:
    vec.push_back(1);
    recursion(x+1);
    vec.erase(vec.end()-1);
}


int main()
{
    while(cin>>n){
        recursion(0);
    }
    return 0;
}
