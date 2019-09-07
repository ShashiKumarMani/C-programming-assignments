/*
	Split the circular linked list

*/

int main()
{
        struct node *head1=NULL,*head2=NULL;
        int N,n,i,j,*val=NULL;

        scanf("%d",&N);
        struct node *cases[N*2];

        for(i=0;i<N;i++)
        {
                scanf("%d",&n);
                val = (int *)malloc(sizeof(int)*n);
                for(j=0;j<n;j++)
                {
                        scanf("%d",&val[j]);
                }
                head1 = quick_list(head1,val,n);

                printf("LIST CREATED\n");

                head2 = divide(head1);
                //print_nodes(head1);
                //print_nodes(head2);
                cases[i*2]=head1;
                cases[i*2+1]=head2;
                head1=NULL;
                head2=NULL;
        }
        for(i=0;i<N*2;i++)
        {
                print_nodes(cases[i]);
        }
        return 0;
}

