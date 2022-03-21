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
		List x = List(val);
		x.next = head;
		head = &x;
	}
	else{
		List x = List(val);
		List *temp = head;
		for(int i=2; i<pos; i++){
			if(temp->next!=NULL) temp = temp->next;
		}
		x.next = temp->next;
		temp->next = &x;
	}
	return head;
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
	head = insertion(head,7,100);
	traverse(head);
	return 0;
}
