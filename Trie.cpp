#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	bool foundWord;
	Node *arr[27];
	Node() {
		this->foundWord = false;
		for(int i=0; i<26; i++) {
			this->arr[i] = NULL;
		}
	}
};

Node *root = new Node();

string str,s;

void TrieInsert(string s) {
	Node *curr = root;
	int l = s.size();
	for(int i=0; i<l; i++){
		int id = s[i]-'a';
		if(curr->arr[id] == NULL) {
			Node *newNode = new Node();
			curr->arr[id] = newNode;
			curr = newNode;
		}
		else {
			curr = curr->arr[id];
		}
	}
	curr->foundWord = true;
}

bool TrieSearch(string s) {
	Node *curr = root;
	int l = s.size();
	for(int i=0; i<l; i++) {
		int id = s[i] - 'a';
		if(curr->arr[id] == NULL) {
			return false;
		}
		else {
			curr = curr->arr[id];
		}
	}
	return curr->foundWord;
}

void TrieDelete(Node *curr) {
	for(int i=0; i<26; i++) {
		if(curr->arr[i] != NULL) {
			TrieDelete(curr->arr[i]);
		}
	}
	delete(curr);
}

int main() 
{	
	int n, m;
	cin >> n;
	for(int i=0; i<n; i++) {
		getchar();
		cin >> str;
		TrieInsert(str);
	}

	cin >> m;

	while(m--) {
		getchar();
		cin >> s;
		bool flag = TrieSearch(s);
		printf(flag ? "Yes\n" : "No\n");
	}
	TrieDelete(root);
	return 0;
}
