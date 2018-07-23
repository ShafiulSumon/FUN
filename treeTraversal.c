#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	char data;
	struct node* left;
	struct node* right;
};

/* this is a function*/
struct node* newNode(char data){
	struct node* node= (struct node*) malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}


void postorder(struct node* root){
	
}




void inorder(struct node* root){
	printf("In_order:");
	struct node* STACK[100];
	int top=0;
	STACK[top]=NULL;
	struct node* PTR=root;
	while(true){
		if(PTR!=NULL){
			top=top+1;
			STACK[top]=PTR;
			PTR=PTR->left;
		}
		else{
			if(STACK[top]!=NULL){
				PTR=STACK[top];
				top=top-1;
				printf(" %c",PTR->data);
				PTR=PTR->right;
			}
			else{
				break;
			}
		}
	}
	printf("\n");
}


void preorder(struct node* root){
	printf("Pre_order:");
	int top=0;
	struct node* STACK[100];
	STACK[top]=NULL;
	struct node* PTR=root;
	while(PTR!=NULL){
		/*print always root*/
		printf(" %c",PTR->data);
		if(PTR->right!=NULL){
			top=top+1;
			STACK[top]=PTR->right;
		}
		if(PTR->left!=NULL){
			PTR=PTR->left;
		}
		else{
			PTR=STACK[top];
			top=top-1;
		}
	}
	printf("\n");
}


int main()
{
	/*taking input*/
	struct node* root= newNode('A');
	root->left=newNode('B');
	root->right=newNode('C');
	root->left->left=newNode('D');
	root->left->left->left=newNode('G');
	root->left->left->right=newNode('H');
	root->left->left->right->right=newNode('K');
	root->right->left=newNode('E');
	root->right->right=newNode('F');

	preorder(root);

	inorder(root);

	postorder(root);

	return 0;
}
