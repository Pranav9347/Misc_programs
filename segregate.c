#include <stdio.h>
#include<stdlib.h>
void swap(int* x, int* y);

//Problem to segregate all odd-positioned elements together and all even-positioned elements together:(shouldn't use extra array)

int main (void) 
{
    int n=0;
    printf("Size of input (give odd n): ");
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int));
    printf("Elements to be arranged: ");
    for(int i=0;i<n;i++)
    {
        printf("Element (%d):",i+1);
        scanf(" %d",(ptr+i));
    }
    
    for(int i=0,k=2;i<((n-1)/2);i++,k++)
    {
        swap((ptr+i+1),(ptr+i+k));
    }
    printf("\nAfter segregation:\n");
    for(int i=0;i<n;i++)
    {
        printf("Element (%d)=%d\n",i+1,*(ptr+i));
    }
    

    return 0;
}
void swap(int* x, int* y)
{
  float container;
  container=*x;
  *x=*y;
  *y=container;
}

