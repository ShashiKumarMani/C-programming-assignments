#include<stdio.h>

int main()
{

    FILE *fptr;
    char c;

    fptr = fopen("test1","w");
    if(fptr==NULL)
    {
        exit(1);
    }
    while(c = getchar()!=EOF)
    {
        putc(c,fptr);
    }
    fclose(fptr);
    return 0;

/*
    FILE *fptr;
    fptr = fopen("test1","r");
    char c;
    while(c=fgetc(fptr)!=EOF)
    {
        printf("%c\n",c);
    }
    fcloseall();
    return 0;
    */
}
