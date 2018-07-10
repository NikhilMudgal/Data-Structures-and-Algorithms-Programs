#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node*next;
}*f=NULL,*r=NULL;
void qins(int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(f==NULL)
	{
		temp->info=x;
		temp->next=NULL;
		f=temp;
		r=temp;
	}
	else{
		temp->info=x;
		temp->next=NULL;
		r->next=temp;
		r=temp;
		printf("Element added\n");
		}
}
void qdel()
{
	struct node *temp;
	if(f==NULL)
	printf("Empty node\n");
	else{
		temp=f;
		f=f->next;
		free(temp);
	}
	printf("Element deleted\n");
}
void display()
{
	struct node *temp;
	if(f==NULL)
	printf("Empty node\n");
	else{
		temp=f;
		while(temp->next!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->next;
			
		}
		printf("%d",temp->info);
	}
}
int main()
{
	int c,x;
	char ch;
	
	do{
		printf("--MAIN MENU\n1.INSERT\n2.DELETE\n3.DISPLAY\nENTER YOUR CHOICE\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter the element to be added\n");
			        scanf("%d",&x);
			        qins(x);
			        break;
			case 2: qdel();
			         break;
			case 3 : display();
			        break;
			default: printf("Wrong chioce\n");
			break;				         
		}
		printf("Do you want to continue\n");
		scanf("%c",&ch);
		scanf("%c",&ch);
	}
	while(ch=='y'||ch=='Y');
	getch();
	return 0;
}

