#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left , *right;

};

struct Node* newNode(int data){
	struct Node* node = new Node;
 	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void excludeLeftmost(Node* root){

	if(root==NULL)
		return ;
	queue<Node*> q;
	q.push(root);

	while(1){
		int count = q.size();
		if(count == 0)
			break;
		int flag = 1;

		while(count){
			Node* node = q.front();
			if(flag)
				flag = 0;

			else
				cout<<node->data<<" ";

			q.pop();
			if (node->left != NULL) 
		        q.push(node->left); 
		        if (node->right != NULL) 
		        q.push(node->right); 
		    	count--; 

		}
		cout<<endl;

	}


}


int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->right->left = newNode(8); 
    root->left->right->right = newNode(9); 
    root->left->right->right->right = newNode(10); 
  
    excludeLeftmost(root); 
  
    return 0; 
}
