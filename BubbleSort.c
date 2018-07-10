#include<stdio.h>
#include<conio.h>
#define N 5
 void sort(int c[])
 {
  int i,j,small,pos,temp;
  for(i=0;i<N-1;i++)
  {
    small=c[i];
    pos=i;
    for(j=i+1;j<N;j++)
    {
    if(c[j]<small)
    {
      small=c[j];
      pos=j;
      }
      }
      temp=c[i];
      c[i]=c[pos];
      c[pos]=temp;
      }
      printf("The elements after sorting wil be printed as\n");
      for(i=0;i<N;i++)
      printf("%d ",c[i]);
}
int  main()
{
 int i,a[N];
 printf("Enter the elements of array to  be sorted\n");
 for(i=0;i<N;i++)
 scanf("%d",&a[i]);
 sort(a);
 getch();
 return 0;
 }

