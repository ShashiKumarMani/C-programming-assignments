#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
int count = 0;
void num_nodes(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    count+=1;
    if(root->left!=NULL)
    {
        num_nodes(root->left);
    }
    if(root->right!=NULL)
    {
        num_nodes(root->right);
    }
}
int main()
{
    struct node *tree=NULL;
    tree = (struct node *)malloc(sizeof(struct node));
    tree->data=1;
    tree->left=NULL;
    tree->right=NULL;

    printf("%d\n",count);

    num_nodes(tree);

    printf("%d\n",count);
    return 0;
}

