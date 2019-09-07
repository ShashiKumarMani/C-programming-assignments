/*
	Program to print tree traversals
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
int count =0;
struct node *add_node(int val)
{
    struct node *temp=NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);

}
int main()
{
    struct node *root=NULL;
    root = add_node(10);
    root->left = add_node(20);
    root->right = add_node(30);
    root->left->left = add_node(40);
    root->left->right = add_node(50);
    root->right->right = add_node(60);

    printf("POST ORDER : ");postorder(root);
    printf("PRE ORDER : ");preorder(root);
    printf("IN ORDER : ");inorder(root);

    return 0;
}

