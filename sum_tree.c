#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *add_node(int val)
{
    struct node *temp=NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int sum(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return (root->data+sum(root->left)+sum(root->right));
	}
}
int issumtree(struct node *root)
{
	int l,r;

	if(root==NULL || root->left==NULL && root->right==NULL)
	{
		return 1;
	}
	else
	{
		l = sum(root->left);
		r = sum(root->right);

		if((root->data == l+r)&&(issumtree(root->left))&&(issumtree(root->right)))
		{
			return 1;
		}
		return 0;
	}
}
int main()
{
    struct node *root=NULL;
    root = add_node(27);
    root->left = add_node(10);
    root->right = add_node(3);
    root->left->left = add_node(4);
    root->left->right = add_node(6);
    root->right->right = add_node(3);
    if(issumtree(root))
    {
	    printf("YES\n");
    }
    else
    {
	    printf("NO\n");
    }
    return 0;
}

