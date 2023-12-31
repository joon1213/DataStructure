#include <stdio.h>
#include <stdlib.h>

typedef struct tree{

	int data;
	int id;
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

void search1(tree* root)
{
	if ( root!=NULL )
	{
		printf(" %d",root->data);
		search1(root->left);
		search1(root->right);
	}
}


void search2(tree* root)
{
	if ( root!=NULL )
	{
		search2(root->left);
		printf(" %d",root->data);
		search2(root->right);
	}
}


void search3(tree* root)
{
	if ( root!=NULL )
	{
		search3(root->left);
		search3(root->right);
		printf(" %d",root->data);
	}
}

int search_sum(tree* root)
{
	int sum1=0;
	int sum2=0;

	if ( root!=NULL )
	{
		if ( root->left!=NULL )
		{
			sum1=search_sum(root->left);
		}
		if ( root->right!=NULL )
		{
			sum2=search_sum(root->right);
		}
	}

	return sum1+sum2+root->data;
}

int main()
{
	tree* root;
	tree* ex[10];
	int i;
	int n;
	int id;

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

	scanf("%d",&id);

	if ( id>8 || id<1 )
	{
		printf("-1\n");
		return 0;
	}

	n=search_sum(ex[id]);

	printf("%d",n);

	return 0;
}