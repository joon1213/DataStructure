#include <stdio.h>
#include <stdlib.h>

typedef struct tree{

	int data;
	struct tree* left;
	struct tree* right;

}tree;

tree* getnode(int data) 
{
	tree* ex;

	ex=(tree*)malloc(sizeof(tree));
	ex->data=data;
	ex->left=NULL;
	ex->right=NULL;

	return ex;
}

tree* input(int data,tree* ex1, tree* ex2)  // 노드 입력함수
{
	tree* ex;

	ex=(tree*)malloc(sizeof(tree));
	ex->data=data;
	ex->left=ex1;
	ex->right=ex2;

	return ex;
}

void output(tree* root)    // 노드 출력함수
{
	printf("%d ",root->data);

	if ( root->left!=NULL )
	{
		printf("%d ",root->left->data);
	}

	if ( root->right!=NULL )
	{
		printf("%d ",root->right->data);
	}

	printf("\n");
	

}

int main()
{
	tree* root;
	tree* ex[10];
	int i;
	int n;

	root=(tree*)malloc(sizeof(tree));
	for ( i=0; i<10; i++ )
	{
		ex[i]=(tree*)malloc(sizeof(tree));
	}

	ex[4]=getnode(70);
	ex[5]=getnode(90);
	ex[2]=input(30,ex[4],ex[5]);

	ex[7]=getnode(130);
	ex[8]=getnode(80);
	ex[6]=input(120,ex[7],ex[8]);

	ex[3]=input(50,NULL,ex[6]);
	ex[1]=input(20,ex[2],ex[3]);

	scanf("%d",&n);

	if ( n>8 || n<1 )
	{
		printf("-1\n");
		return 0;
	}

	output(ex[n]);

	return 0;
}