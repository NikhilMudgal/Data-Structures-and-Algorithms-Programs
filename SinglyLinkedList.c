#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node* link;
}*start=NULL;
void insbeg(int x)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(start==NULL)
	{
		temp->info=x;
		temp->link=NULL;
		start=temp;
		printf("ELEMENT SUCCESSFULLY ADDED\n");
	}
	else
	{
		temp->info=x;
		temp->link=start->link;
		start=temp;
		printf("ELEMENT SUCCESSFULLY ADDED\n");
	}
}
void insend(int x)
{
	struct node*temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(start==NULL)
	printf("NO NODE\n");
	else
	{
			ptr=start;
			while(ptr->link!=NULL)
			ptr=ptr->link;
			temp->info=x;
			temp->link=NULL;
			ptr->link=temp;
			printf("ELEMENT SUCCESSFULLY ADDED\n");
	}

}
struct node* search(struct node*ptr,int x)
{
	if(ptr==NULL)
	printf("NO NODE\n");
	else
	while(ptr->link!=NULL&&ptr->info!=x)
	ptr=ptr->link;
	return ptr;
}
void insaft(int x)
 {   int y;
	printf("Enter the element to be addded\n");
	scanf("%d",&y);
	struct node*temp,*loc;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(start==NULL)
	printf("NO NODE\n");
	else
	{
		loc=search(start,x);
		if(loc==NULL)
		printf("ELEMENT NOT FOUND\n");
		else
		{
			temp->info=y;
			temp->link=loc->link;
			loc->link=temp;
			printf("ELEMENT SUCCESSFULLY ADDED\n");
		}
	}
}
void insbef(int x)
{
	int y;
	printf("Enter the element to be addded\n");
	scanf("%d",&y);
	struct node *temp,*loc,*ptr;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(start==NULL)
	printf("NO NODE\n");
	else
	{
		loc=search(start,x);
		if(loc==NULL)
		printf("ELEMENT NOT FOUND\n");
		else
		{
			ptr=start;
			while(ptr->link!=loc)
			ptr=ptr->link;
			temp->info=y;
			temp->link=loc;
			ptr->link=temp;	
			printf("Element successfully added\n");
		}
		
	}
}
void delbeg()
{
struct node *temp;
if(start==NULL)
printf("NO NODE\n");
else if(start->link==NULL)
{   
     temp=start;
	free(temp);
	start=NULL;
	
}
	else
	{
		temp=start;
		start=start->link;
		free(temp);
	}
}
void delend()
{
	struct node* temp,*ptr;
	if(start==NULL)
	printf("NO NODE\n");
	else
	{
	temp=start;
	while(temp->link!=NULL)
	{
	ptr=temp;
	temp=temp->link;
}
ptr->link=NULL;
free(temp);
printf("Element successfully deleted\n");
}
}
void delaft(int x)
{
	struct node* temp,*ptr,*loc;
	if(start==NULL)	
	printf("NO NODE\n");
	else
	{
		loc=search(start,x);
		if(loc==NULL)
		printf("NO ELEMENT\n");
		else if(loc->link==NULL)
		printf("NO ELEMENT AFTER A GIVEN NODE\n");
		else
		{
			temp=start;
			while(temp->link!=loc)
			temp=temp->link;
			ptr=temp->link;
			temp->link=ptr->link;
			free(ptr);
			printf("ELEMENT SUCCESSFULLY DELETED\n");
		}
		
	}
}
void delbef(int x)
{
	struct node*temp,*ptr,*loc;
	if(start==NULL)
	printf("NO NODE\n");
	else
	{
		loc=search(start,x);
		if(loc==NULL)
		printf("NO ELEMENT\n");
		else
		{
			temp=start;
			while(temp->link!=loc)
			{
			ptr=temp;
			temp=temp->link;
		}
		ptr->link=temp->link;
		free(temp);
		printf("ELEMENT SUCCESSFULLY DELETED\n");
		}
	}
}
void traversal()
{
	struct node* temp;
	if(start==NULL)
	printf("NO NODE\n");
	else
	{
		temp=start;
		while(temp->link!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->link;
			
		}
		printf("%d\n",temp->info);
	}
}
void retraversal(struct node*ptr)
{
	if(ptr->link!=NULL)
	retraversal(ptr->link);
	printf("%d\n",ptr->info);
}
int  main()
{
	int x;
	char ch;
	int n;
	system("cls");
	
  do
{   
    printf("----MAIN MENU----\n1.Insertion at begining\n2.Insertion at end\n3.Insert after a given node\n4.Insert before a given node\n5.Deletion at begining\n6.Deletion at end\n7.Delete after a given node\n8.Delete before a given node\n9.Traversing in order\n10.Reverse order traversing\nEnter your choice\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:printf("Enter the element to be added\n");
              scanf("%d",&x);
              insbeg(x);
              break;
        case 2: printf("Enter the element to be added\n");
                scanf("%d",&x);
                insend(x);
                break;
        case 3: printf("Enter the element to be added\n");
                scanf("%d",&x);
                insaft(x);
                break;
	   case 4: printf("Enter the element to be added\n");
                scanf("%d",&x);
                insbef(x);
                break;
        case 5: delbeg();
                break;
        case 6: delend();
                 break;
        case 7: printf("Enter the element after which node has to be deleted\n");
                scanf("%d",&x);
                delaft(x);
                break;
        case 8:printf("Enter the element before which element has to be deleted\n");
               scanf("%d",&x);
               delbef(x);
               break;
        case 9: traversal();
                break;
        case 10:retraversal(start);
                break;
                default: printf("Wrong choice\n");
                break;
            }
            printf("Do you want to continue\n");
            scanf("%c",&ch);
            scanf("%c",&ch);
}
while(ch=='Y'||ch=='y');
getch();
return 0;
}

