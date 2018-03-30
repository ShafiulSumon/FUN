#include <bits/stdc++.h>

using namespace std;

#define PI                   acos(-1)
#define inf                  1e9
#define SZ(a)                a.size()
#define ms(a,b)              memset(a,b,sizeof a)
#define clr(a)               memset(a,0,sizeof a)
#define input                freopen("in.txt","r",stdin)
#define output               freopen("out.txt","w",stdout)
#define fast                 ios_base::sync_with_stdio(0); cin.tie(0)
#define LL                   long long
#define isValid(a,b,A,B)     ((0<=a&&a<A) && (0<=b&&b<B))
#define Abs(a,b)             a>b ? a-b : b-a // if a>b is true return a-b eles b-a
#define pb                   push_back
#define mp                   make_pair
#define sf                   scanf
#define pf                   printf

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

typedef pair<int,int> Pr;


/* .......................................................*/



struct node{
    int data;
    node *address;
};

struct node *head, *tail;

void linked_list(int data){
    struct node *temp=(struct node*) malloc(sizeof (struct node));
    temp->data=data;
    temp->address=NULL;
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->address=temp;
        tail=temp;
    }
}

int main()
{
    int n,x;
    head=tail=NULL;
    while(cin>>n){
        for(int i=0; i<n; i++){
            cin>>x;
            linked_list(x);
        }
        struct node *ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->address;
        }
        cout<<endl;
        while(ptr!=NULL){
            node *ex=ptr;
            free(ptr);
            ptr=ex;
        }
    }
    return 0;
}
