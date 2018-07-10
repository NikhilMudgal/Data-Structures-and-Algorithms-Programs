#include<stdio.h>
#include<conio.h>
#include<process.h>
#define max 5
int stack[max],i,top=-1;
void push(int a)
{
  if(top==max-1)
  printf("Stack Over flow\n");
  else
  top++;
  stack[top]=a;
}
void pop()
{
  if(top==-1)
  printf("Stack empty\n");
  else
  top--;
}
void display()
{
  for(i=top;i>-1;i--)
  printf("%d\n",stack[i]);
}
void main()
{
  int a;
  char c='z',ch='z';
  clrscr();
do
{
  printf("MAIN MENU\nA.PUSH\nB.POP\nC.DISPLAY\nD.EXIT\n");
  printf("Enter your choice\n");
  scanf(" %c",&ch);
  switch(ch)
{
  case 'A':  printf("Enter the element to be added\n");
	     scanf("%d",&a);
	     push(a);
	     break;
  case 'B' : pop();
	     break;
  case 'C' : display();
	     break;
  case 'D' : exit(0);
	     break;
  default: printf("Wrong choice\n");
}
  printf("Do you want to continue\n");
  scanf(" %c",&c);
} while(c=='y'||c=='Y');
  getch();
}

