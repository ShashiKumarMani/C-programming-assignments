#include<stdio.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
    int count;
    int middle;
};

int main()
{
        struct node *head;


}
void push(struct node *s,int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    s->data = data;
    s->prev = NULL;
    s->next = s->head;
    s->count +=1;

    if(s->count == 1)
    {
        s->middle = temp;
    }
    else
    {
        s->head->prev = temp;
        if(s->count & 1)
        {
            s->middle = s->middle->prev;
        }
        s->head = temp;
    }
}
int delete_middle(struct stack *s)
{
    struct node *temp=s->middle;
    int data =temp->data;

    s->middle = (s->count &1)?temp->next:temp->prev;

    s->count -= 1;

    if(temp->prev)
    {
        temp->prev->next = temp->next;
    }
    if(temp->next)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);

    if(s->count == 0)
    {
        s->head = NULL;
        s->middle = NULL;
    }
    return data;

}

