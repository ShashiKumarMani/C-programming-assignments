/*
Write a program that converts and prints user given measurement in inches into
1. foot(12 inches)
2. yard(36 inches)
3. centimetres(2.54 inches)
4. meter(39.37 inches)

*/
#include<stdio.h>
int main()
{
    float inches;
    int option;
    char choice;

    do{
    printf("Enter the value : ");
    scanf("%f",&inches);

    printf("Options : \n1. Inches to foot\n2. Inches to yard\n3. Inches to Centimeters\n4. Inches to Meter\nEnter your choice : ");
    scanf("%d",&option);

    switch(option)
    {
        case 1:
                printf("Foot : %f\n",inches/12);
                break;
        case 2:
                printf("Yard : %f\n",inches/36);
                break;
        case 3:
                printf("Centimeters : %f\n",inches/2.54);
                break;
        case 4:
                printf("Meters : %f\n",inches/39.37);
                break;
        default :
                printf("Invalid option!\n");
    }

    printf("Continue? [y|n] : ");
    scanf(" %c",&choice);
    }while(choice=='y');
    
    return 0;
}
