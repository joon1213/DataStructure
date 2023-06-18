#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int data;
	struct node *left;
	struct node *right;

}node;

node* left(node* root) // 왼쪽자식 만들기
{
	node* child;

	child=(node*)malloc(sizeof(node));
	child->left=NULL;
	child->right=NULL;
	root->left=child;

	return child;
}

node* right(node* root) // 오른쪽 자식 만들기
{
	node* child;

	child=(node*)malloc(sizeof(node));
	child->left=NULL;
	child->right=NULL;
	root->right=child;

	return child;
}

node* thread(int data,node* root) // 순회함수
{
	node* q=root;
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	while ( root!=NULL )
	{
		if ( root->data > data ) 
		{
			q=root;
			root=root->left;
		}
		else if ( root->data == data ) break;
		else
		{
			q=root;
			root=root->right;
		}
	}

	if ( data < q->data )
	{
		q->left=temp;
	}

	if ( data > q->data )
	{
		q->right=temp;
	}

	return q;
}

int main()
{
	node* root;
	node* stand;
	node* ex;
	node* max=NULL, *min=NULL;
	int n;

	root=(node*)malloc(sizeof(node)); // root 노드 만들기
	root->data=8;
	root->left=NULL;
	root->right=NULL;

	ex = left(root); // 제시된 트리를 만들기
	ex->data = 3;
	ex = left(root->left);
	ex->data = 2;
	ex = right(root->left);
	ex->data = 5;
	ex = left(root->left->right);
	ex->data = 4;
	ex = right(root);
	ex->data = 10;
	ex = right(root->right);
	ex->data = 14;
	ex = left(root->right->right);
	ex->data = 11;
	ex = right(root->right->right);
	ex->data = 16;


	return 0;
}