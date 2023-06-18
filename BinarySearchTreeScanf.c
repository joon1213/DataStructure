#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree{  // 기본노드 구조체

	int id;
	struct tree* left;
	struct tree* right;

}tree;

tree* hel;

tree* getnode(int id)  // 빈노드 추가함수
{
	tree* ex;

	ex=(tree*)malloc(sizeof(tree));
	ex->id=id;
	ex->left=NULL;
	ex->right=NULL;

	return ex;
}

void search(tree* root, int id)   // 노드 검색함수
{
	if ( root!=NULL )
	{
		if ( root->id==id )
		{
			hel=root;
			
		}
		search(root->left,id);
		search(root->right,id);
	}

}

void input(tree* root,int pa,int ch1,int ch2) // 노드 입력함수
{
	tree* ex;

	if ( root->id==0 )
	{
		root->id=pa;
	}

	if ( root!=NULL )
	{
		search(root,pa);
		ex=hel;
		if ( ch1!= 0 )
		{
			ex->left=getnode(ch1);
		}
		if ( ch2!= 0 )
		{
			ex->right=getnode(ch2);
		}
	}

	
}

tree* exp(tree* root,char c)  // 왼쪽 오른쪽으로 갈지 선택
{
	tree* temp=root;

	if ( c=='L' )
	{
		temp=temp->left;
		printf(" %d",temp->id);
		return temp;
	}

	if ( c=='R' )
	{
		temp=temp->right;
		printf(" %d",temp->id);
		return temp;
	}

}

int main()
{
	tree* root;
	tree* ex;
	
	int i,j;
	int n,m;
	int x,y,z;
	char c[101]="";
	int l;

	root=(tree*)malloc(sizeof(tree));
	root->id=0;
	root->left=NULL;
	root->right=NULL;

	scanf("%d",&n);
	for ( i=0; i<n; i++ )
	{
		scanf("%d %d %d",&x,&y,&z);
		input(root,x,y,z);
	}

	scanf("%d",&m);
	
	for ( i=0; i<m; i++ )
	{
		ex=root;
		scanf("%s",c);
		l=strlen(c);
		printf(" %d",root->id);
		for ( j=0; j<l; j++ )
		{
			ex=exp(ex,c[j]);
		}
		printf("\n");
	}
	

	return 0;
}