#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test=1;
    string A,B;
    while(getline(cin,A)){
        if(A=="#") break;
        getline(cin,B);
        int n=A.length();
        int m=B.length();
        int LCS[n+2][m+2];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0) LCS[i][j]=0;
                else if(A[i-1]==B[j-1]) LCS[i][j]=1+LCS[i-1][j-1];
                else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",test++,LCS[n][m]);
    }
    return 0;
}
