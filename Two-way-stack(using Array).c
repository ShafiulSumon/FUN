#include <stdio.h>
#define N 5

int SINARRAY[N];
int a=0,b=N-1;

void pushSTACK1(int element){
    if(a==b){
        printf("Overflow first stack\n");
        return;
    }
    SINARRAY[a]=element;
    a++;
}

void pushSTACK2(int element){
    if(a==b){
        printf("Overflow second stack\n");
        return;
    }
    SINARRAY[b]=element;
    b--;
}

int popSTACK1(){
    if(a<=0){
        return 1;
    }
    a--;
    return 0;
}

int popSTACK2(){
    if(b>=(N-1)){
        return 1;
    }
    b++;
    return 0;
}

int topSTACK1(){
    if(a<=0) return -5;
    return a-1;
}

int topSTACK2(){
    if(b>=N-1) return -5;
    return b+1;
}


int main()
{
    int demand,x,y;
    while(1){
        printf("                        Press:\n");
        printf("                            1 to push first stack\n");
        printf("                            2 to push second stack\n");
        printf("                            3 to pop from first stack\n");
        printf("                            4 to pop from second stack\n");
        printf("                            5 to print top element of first stack\n");
        printf("                            6 to print top element of second stack\n");
        printf("                            0 to exit\n");
        scanf("%d",&demand);
        if(demand==0) return 0;
        else if(demand==1){
            printf("Enter the element: ");
            scanf("%d",&x);
            pushSTACK1(x);
        }
        else if(demand==2){
            printf("Enter the element: ");
            scanf("%d",&x);
            pushSTACK2(x);
        }
        else if(demand==3){
            y=popSTACK1();
            if(y==1) printf("Underflow first stack\n");
            else printf("last element is poped from first stack\n");
        }
        else if(demand==4){
            y=popSTACK2();
            if(y==1) printf("Underflow second stack\n");
            else printf("last element is popoed from second stack\n");
        }
        else if(demand==5){
            y=topSTACK1();
            if(y==-5) printf("Your first stack is empty\n");
            else printf("top element of the first stack is: %d\n",SINARRAY[y]);
        }
        else if(demand==6){
            y=topSTACK2();
            if(y==-5) printf("Your second stack is empty\n");
            else printf("top element of the second stack is: %d\n",SINARRAY[y]);
        }
        else{
            printf("Wrong KEY\n");
        }
    }
    return 0;
}
