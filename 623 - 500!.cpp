#include <bits/stdc++.h>

using namespace std;

#define PI                   acos(-1)
#define inf                  1e9
#define SZ(a)                a.size()
#define ms(a,b)              memset(a,b,sizeof a)
#define clr(a)               memset(a,0,sizeof a)
#define INPUT                freopen("in.txt","r",stdin)
#define OUTPUT               freopen("out.txt","w",stdout)
#define fast                 ios_base::sync_with_stdio(0); cin.tie(0)
#define LL                   long long
#define isValid(a,b,A,B)     ((0<=a&&a<A) && (0<=b&&b<B))
#define ABS(a,b)             a>b ? a-b : b-a // if a>b is true return a-b eles b-a
#define pb                   push_back
#define mp                   make_pair
#define spc                  printf(" ")
#define nl                   printf("\n")
#define sf                   scanf
#define pf                   printf
#define sq(a)                (a*a)
#define powoftwo(a)          (a&(a-1)) // if a is power of two or not

/// bool Check(int A,int B){return A&(1<<B);}
/// int  Set(int A,int B){return A|(1<<B);}

/// int ax[]={1, 1, -1, -1, 2, 2, -2, -2}; //knight moves
/// int ay[]={2,-2,  2, -2, 1,-1,  1, -1}; //knight moves

/*.......................................................*/


int main()
{
    int n;
    while(cin>>n){
        int arr[3000];
        int digit=1;
        int carry=0;
        arr[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<digit; j++){
                int x=arr[j]*i+carry;
                arr[j]=x%10;
                carry=x/10;
            }
            if(carry>0){
                while(carry>0){
                    arr[digit]=carry%10;
                    carry/=10;
                    digit++;
                }
            }
        }
        pf("%d!\n",n);
        for(int i=digit-1; i>=0; i--){
            pf("%d",arr[i]);
        }
        nl;
    }
    return 0;
}

