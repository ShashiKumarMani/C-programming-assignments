/*
	Program to find if the tree satisfies child sum property

*/
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
	int l,r;
        if(root->left !=NULL)
        {
                        l = root->left->data;
        }
        else{l=0;}
        if(root->right != NULL)
        {
                        r = root->right->data;
        }
        else{r=0;}
	
	return l+r;
}
int ischildsum(struct node *root)
{
        int l,r;

        if(root==NULL || root->left==NULL && root->right==NULL)
        {
                return 1;
        }
        else
        {

                if((root->data == sum(root))&&(ischildsum(root->left))&&(ischildsum(root->right)))
                {
                        return 1;
                }

                return 0;
        }
}

int main()
{
    struct node *root=NULL;
    root = add_node(11);
    root->left = add_node(8);
    root->right = add_node(2);
    root->left->left = add_node(3);
    root->left->right = add_node(5);
    root->right->right = add_node(2);
    
    if(ischildsum(root))
    {
            printf("YES\n");
    }
    else
    {
            printf("NO\n");
    }
    return 0;
}

