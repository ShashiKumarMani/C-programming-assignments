/*
    Find if two trees are identical using recursion

*/

#include<stdio.h>
#include<stdlib.h>
int TRY_ITERATIVE;
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
int check_identical(struct node *root1,struct node *root2)
{
    if(root1==NULL && root2 ==NULL)
    {
        return 1;
    }
    if(root1==NULL ||root2==NULL)
    {
        return 0;
    }
    if(root1!=NULL && root2!=NULL)
    {
        return (root1->data == root2->data) && check_identical(root1->left,root2->left) && check_identical(root1->right,root2->right);
    }
}
int main()
{
    struct node *root1=NULL,*root2=NULL;;
    root1 = add_node(10);
    root1->left = add_node(20);
    root1->right = add_node(30);
    root1->left->left = add_node(40);
    root1->left->right = add_node(50);
    root1->right->right = add_node(70);

    root2 = add_node(10);
    root2->left = add_node(20);
    root2->right = add_node(30);
    root2->left->left = add_node(40);
    root2->left->right = add_node(50);
    root2->right->right = add_node(70);
    check_identical(root1,root2)?printf("Identical\n"):printf("Not identical\n");


    return 0;
}
