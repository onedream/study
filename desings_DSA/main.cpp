//Hierarchical traversal of a binary tree
#include<iostream>
#include<queue>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
node* createNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void preOrder(node* root)
{
	if(root == NULL)
	return NULL;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
//level by level
void levelOrder(node* root)
{
	if(root == NULL)
	return NULL;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* temp = q.front();
		cout<<temp->data<<" ";
	}
	q.pop();
	if(temp->left != NULL)
	q.push(temp->left);
	if(temp->right != NULL)
	q.push(temp->right);
	levelOrder(root);
}