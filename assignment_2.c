/*
    A wire is the form of Arc at an angle of 60 degrees and the radius of the arc is 42.
    The wire is converted into a square. Find the area of the square
*/

#include<stdio.h>
int main()
{
    float angle,radius,length;
    char option;

  do{
    printf("Enter the angle and radius of the arc: ");
    scanf("%f %f",&angle,&radius);

    length = (angle / 360.0)*(2 * 3.14*radius);
    length = length/4;
    printf("The area of the square is %f\n",length*length);

    printf("Continue? [y|n] : ");
    scanf(" %c",&option);

    }while(option=='y');
    return 0;
}
