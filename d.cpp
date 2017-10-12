#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbyfirst(const pair<int,int> &left, const pair<int,int> &right){
    if(left.first!=right.first) return left.first<right.first;
    else left.second>right.second;
}

int main()
{
    int n,i,a,b;
    while(scanf("%d",&n)==1){
        vector< pair<int,int> > vec;
        for(i=0; i<n; i++){
            scanf("%d %d",&a,&b);
            vec.push_back(make_pair(a,b));
        }
        sort(vec.begin(),vec.end(),sortbyfirst);
        for(i=0; i<n; i++){
            printf("%d %d\n",vec[i].first,vec[i].second);
        }
    }
    return 0;
}
