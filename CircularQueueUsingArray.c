#include<stdio.h>
#include<conio.h>
#define N 5
int f=-1,r=-1,Q[N];
void cinsert(int x)
{
	if((f==0&&r==N-1)||f==r+1)
	printf("Queue overflow\n");
	else if(f==-1)
	{
		f=r=0;
		Q[f]=x;
	}
	else if(r==N-1)
	r=0;
	else
	{
		r++;
		Q[r]=x;
	}
}

void cdelete()
{
	if(f==-1)
	printf("Queue underflow\n");
	else if(f==r)
	
		f=r=-1;
		else if(f==N-1)
	f=0;
	else 
	f++;
}
void cdisplay()
{
	int i;
	if(f==-1)
	printf("Queue underflow\n");
	for(i=f;i<=r;i++)
	printf("%d ",Q[i]);
	printf("\n");
}
int main()
{
	int x,c;
	char ch;
	do{
		printf("MAIN MENU\n1.Insert\n2.Delete\n3.Display\nEnter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter the element to be added\n");
			        scanf("%d",&x);
			        cinsert(x);
					break;
			case 2: cdelete();
			        break;
			case 3: cdisplay();
			        break;
			default : printf("Wrong choice\n");
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

