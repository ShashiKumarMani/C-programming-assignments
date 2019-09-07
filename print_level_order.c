#include<stdio.h>
#include<stdlib.h>
int front=-1;
int end=-1;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *queue[100];
 void enqueue(struct node *val)
{
    if(front==100)
    {
        printf("OVERFLOW\n");
        return;
    }
    else if(front==-1)
    {
        front=end=0;
        queue[end]=val;
        return;
    }
    end+=1;
    queue[end]=val;
}
struct node *dequeue()
{
    struct node *val;
    if(front==-1)
    {
        printf("UNDERFLOW\n");
        return NULL;
    }
    if(front==end)
    {
        val =queue[front];
        front=end=-1;
        return val;
    }
    return queue[front++];
}
struct node *new_node(int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void print_level(struct node *root)
{
    struct node *temp=NULL;
    temp=root;
    if(temp==NULL)
    {
        printf("EMPTTY\n");
        return;
    }
    enqueue(temp);
    while(front!=-1 && end!=-1)
    {
        temp = dequeue(temp);
        printf("%d ",temp->data);
        if(temp->left!=NULL)
            enqueue(temp->left);
        if(temp->right!=NULL)
            enqueue(temp->right);
    }

}
int main()
{
    struct node *root=NULL;
    root=new_node(10);
    root->left=new_node(20);
    root->right=new_node(30);
    root->left->left=new_node(40);
    root->left->right=new_node(50);
    root->right->right=new_node(60);
    root->right->left=new_node(70);
    printf("Tree created\n");
    print_level(root);
    return 0;
}
