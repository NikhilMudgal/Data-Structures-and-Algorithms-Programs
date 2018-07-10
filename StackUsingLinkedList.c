#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;	
}*top=NULL;
void push(int c)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(top==NULL)
	{
		temp->info=c;
		temp->link=NULL;
		top=temp;
	}
	else
{	
	temp->info=c;
	temp->link=top;
	top=temp;
}
printf("Element added\n");
}
void pop()
{
	struct node*temp;
	if(top==NULL)
	printf("No node\n");
	else if(top->link==NULL)
	{
		 temp=top;
		 top=NULL;
		 free(temp);
 		
	}
	
	else
	{
	temp=top;
	top=top->link;
	free(temp);
}
printf("Element deleted\n");

}
void display()
{
	struct node *temp;
	if(top==NULL)
	printf("NO NODE\n");
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d ->",temp->info);
			temp=temp->link;
		}
	}
	
}
void main()
{
	int ch;
	int c;
	char n;
	system("cls");
	
	do
	{
      printf("--------MAIN MENU------\n\t1.PUSH OPERATION\n\t2.POP OPERATION\n\t3.DIPLAY ELEMENTS\n Enter your choice\n");
      scanf("%d",&ch);	 
	  switch(ch)
	{
     case 1:  
	            printf("Enter the element");
	            scanf("%d",&c);
	            push(c);
	            break;
     case 2:
     	        pop();
     	        break;
     case 3:
     	       display();
     	       break;
	
	default: printf("Wrong choice\n");
	}
printf("Do you want to continue\n");
scanf("%c",&n);
scanf("%c",&n);
}
while(n=='Y'||n=='y');
 getch();
}

