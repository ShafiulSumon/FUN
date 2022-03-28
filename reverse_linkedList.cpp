#include <bits/stdc++.h>

using namespace std;

class LinkedList{
public: 
	int data;
	LinkedList *next;
	LinkedList(){
		this->next = NULL;
	}
	LinkedList(int data){
		this->data = data;
		this->next = NULL;
	}
	void append(int data){
		LinkedList *temp = this;
		LinkedList *x = new LinkedList(data);
		while(temp->next !=NULL){
			temp = temp->next;
		}
		temp->next = x;
	}
};

LinkedList *reverse(LinkedList *head){
	LinkedList *prev = NULL;
	LinkedList *curr = head;
	LinkedList *store = NULL;
	while(curr != NULL){
		store = curr->next;
		curr->next = prev;
		prev = curr;
		curr = store;
	}
	return prev;
}

void traverse(LinkedList *head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<"null"<<endl;
}

int main()
{
	LinkedList list = LinkedList(10);
	LinkedList *head = &list;
	list.append(2);
	list.append(1);
	list.append(3);
	
	traverse(head);
	
	head = reverse(head);
	
	traverse(head);
	
	
	return 0;
}
