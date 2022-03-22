#include <bits/stdc++.h>

using namespace std;

class List{
public:
	int data;
	List *next;
	List(){
		this->next = NULL;
	}
	List(int data){
		this->data = data;
		this->next = NULL;
	}
};

void traverse(List *head){
	List *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

List* insertion(List *head, int pos, int val){
	if(pos==1){
		List *x = new List(val);
		x->next = head;
		head = x;
		return head;
	}
	else{
		List *x = new List(val);
		List *temp = head;
		for(int i=2; i<pos; i++){
			if(temp->next!=NULL) temp = temp->next;
		}
		x->next = temp->next;
		temp->next = x;
		return head;
	}
}

List* deletion(List *head, int pos){
	if(pos==1){
		head = head->next;
	}
	else{
		List *temp = head;
		for(int i=2; i<pos; i++){
			if(temp->next!=NULL) temp = temp->next;
		}
		if(temp->next!=NULL) temp->next = temp->next->next;
	}
	return head;
}

bool searching(List *head, int key){
	List *temp = head;
	while(temp!=NULL){
		if(temp->data==key) return true;
		temp = temp->next;
	}
	return false;
}

void sorting(List *head){
	List *x = head;
	List *y = NULL;
	while(x!=NULL){
		y = x->next;
		while(y!=NULL){
			if(x->data > y->data){
				swap(x->data, y->data);
			}
			y = y->next;
		}
		x = x->next;
	}
}

int main()
{
	List A,B,C;
	List *head;
	head = &A;
	
	A = List(5);
	B = List(7);
	C = List(3);
	
	A.next = &B;
	B.next = &C;
	
	traverse(head);
	head = insertion(head,1,100);
	traverse(head);
	sorting(head);
	traverse(head);
	head = insertion(head,1,70);
	traverse(head);
	
	
	
	return 0;
}
