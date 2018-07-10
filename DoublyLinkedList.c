#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int info;
	struct node *prev;
	struct node *next;
}*head=NULL,*tail=NULL;
void dinsbeg(int x)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(head==NULL)
	{
		temp->info=x;
		temp->prev=NULL;
		temp->next=NULL;
		head=temp;
		tail=temp;
	}
	else{
		temp->info=x;
		temp->prev=NULL;
		temp->next=head;
		head=temp;
	}
	printf("Element added\n");
	}
void dinsend(int x)
{
	struct node*temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(head==NULL)
	printf("EMPTY\n");
	else{
		ptr=head;
		while(ptr!=tail)
		ptr=ptr->next;
		temp->info=x;
		temp->prev=tail;
		temp->next=NULL;
		tail->next=temp;
	}
	printf("Element added\n");
}
struct node*search(struct node*ptr,int x)
{
	if(ptr==NULL)
	printf("Empty\n");
	else{
		while(ptr->next!=NULL&&ptr->info!=x)
		ptr=ptr->next;	
	}
	return ptr;
}
void dinsaft(int x)
{
	struct node*temp,*ptr,*loc;
	int y;
	printf("Enter the element you want to add\n");
	scanf("%d",&y);
	temp=(struct node*)malloc(sizeof(struct node*));
	if(head==NULL)
	printf("Empty\n");
	else
	{
		loc=search(head,x);
		if(loc==NULL)
		printf("Element not found\n");
		else{
			ptr=head;
			while(ptr!=loc)
			ptr=ptr->next;
			temp->info=y;
			temp->prev=ptr;
			temp->next=loc->next;
			loc->next=temp;
			loc->next->prev=temp;
		}
	}
	printf("Element successfully added\n");
}
void dinsbef(int x)
{
	struct node *temp,*ptr,*ptr1,*loc;
	int y;
	printf("Enter the element you want to add\n");
	scanf("%d",&y);
	temp=(struct node*)malloc(sizeof(struct node*));
	if(head==NULL)
	printf("EMPTY LIST\n");
	else{
		loc=search(head,x);
		if(loc==NULL)
		printf("ELEMENT NOT FOUND\n");
		else
		{
			ptr=head;
			while(ptr!=loc)
			{
			ptr1=ptr;
			ptr=ptr->next;
		    }
		    temp->info=y;
		    temp->prev=ptr1;
		    temp->next=ptr;
		    ptr1->next=temp;
		    ptr->prev=temp;
		}
	}
	printf("Element added\n");
}
void ddelbeg()
{
	struct node*temp;
	if(head==NULL)
	printf("EMPTY!\n");
	else{
		 temp=head;
		 head=head->next;
		 head->prev=NULL;
		 free(temp);
		 }
		 printf("ELEMENT DELETED\n");
}
void ddelend()
{
	struct node*temp;
	if(head==NULL)
	printf("EMPTY!\n");
	else{
		temp=head;
		while(temp!=tail)
		temp=temp->next;
		tail=tail->prev;
		tail->next=NULL;
		free(temp);
	}
}
void delbef(int x)
{
	struct node*temp,*ptr,*ptr1,*loc;
	if(head==NULL)
	printf("NO NODE\n");
	else
	{
		loc=search(head,x);
		if(loc==NULL)
		printf("Element not found\n");
		else
		{
			ptr=head;
			while(ptr!=loc)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			temp=ptr1;
			ptr1->prev->next=loc;
			ptr->prev=ptr1->prev;
			free(temp);
		}
	}
}
void delaft(int x)
{
	struct node*temp,*ptr,*ptr1,*loc;
	if(head==NULL)
	printf("NO NODE\n");
	else
	{
		loc=search(head,x);
		if(loc==NULL)
		printf("NO ELEMENT\n");
		else{
			ptr=head;
			while(ptr!=loc->next)
			{
			ptr=ptr->next;
		    }
			temp=ptr;
			ptr->next->prev=ptr->prev;
			loc->next=ptr->next;
			free(temp);
		}
	}
}
void traverse()
{
	struct node*temp;
	if(head==NULL)
	printf("NO NODE\n");
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->next;
		}
	}
}
void revtraverse()
{
	struct node*temp;
	if(head==NULL)
	printf("NO NODE\n");
	else
	{
		temp=tail;
		while(temp!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->prev;
		}
	}
}
int main()
{
	int x,c;
	char ch;
	do{
		printf("---MAIN MENU----\n1.Insert at begining\n2.Insertion at end\n3.Insert after\n4.Insert before\n5.Deletion at begining\n6.Deletion at end\n7.Delete before\n8.Delete after\n9.In order Traverse\n10.Reverse Order traversal\nEnter your choice\n");
		scanf("%d",&c);
	   switch(c)
	   {
	   case 1: printf("Enter the element to be added\n");
	           scanf("%d",x);
	           dinsbeg(x);
	           break;
	    case 2: printf("Enter the element to be added\n");
	           scanf("%d",x);
	           dinsend(x);
	           break;
	    case 3: printf("Enter the element to be added\n");
	           scanf("%d",x);
               dinsaft(x);
			   break;
		case 4: printf("Enter the element to be added\n");
	           scanf("%d",x);
	           dinsbef(x);
			   break;
		case 5: ddelbeg();
		        break;
		case 6:ddelend();
		       break;
		case 7: printf("Enter the element before which the element has to be deleted\n");
		        delbef(x);
				break;
		case 8: printf("Enter the element before which the element has to be deleted\n");
		      	delaft(x);
				  break;
		case 9: traverse();	
		        break;
		case 10: revtraverse();
		         break;
		default:printf("Wrong input\n");
		         break;
	}
     printf("DO you want to continue\n");
	 scanf("%c",&ch);
	 scanf("%c",&ch);  
	}
	while(ch=='y'||ch=='Y');
	return 0;
}

