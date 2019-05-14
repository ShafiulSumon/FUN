#include <bits/stdc++.h>

using namespace std;

int dp[105][105];
string A,B;

int LCS(int i, int j){
    if(A[i]=='\0' or B[j]=='\0') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(A[i]==B[j]){
        ans=1+LCS(i+1,j+1);
    }
    else{
        ans=max(LCS(i,j+1),LCS(i+1,j));
    }
    return dp[i][j]=ans;
}

int main()
{
    int test=1;
    while(getline(cin,A)){
        if(A=="#") break;
        getline(cin,B);
        memset(dp,-1,sizeof(dp));
        int value=LCS(0,0);
        printf("Case #%d: you can visit at most %d cities.\n",test++,value);
    }
    return 0;
}
