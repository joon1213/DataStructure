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

node * search(int num, node* root) // 노드검색함수
{
	while ( root!=NULL )
	{
		if ( root->data > num ) 
		{
			root=root->left;
		}
		else if ( root->data == num ) return root;
		else
		{
			root=root->right;
		}
	}
	
}

node* maxNode(node* root) // 좌측 서브트리에서 key 값이 가장 큰 노드 반환
{
	node* temp=root->left;

	while ( temp->right != NULL )
	{
		temp=temp->right;
	}
	
	return temp;
}

node* minNode(node* root) // 우측 서브트리에서 key 값이 가장 작은 노드 반환
{
	node* temp=root->right;

	while ( temp->left != NULL )
	{
		temp=temp->left;
	}

	return temp;
}

void print(node* root) // 노드 출력함수
{
	if ( root!=NULL )
	{
		printf("%d ",root->data);
		print(root->left);
		print(root->right);
	}
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

	print(root);

	return 0;
}