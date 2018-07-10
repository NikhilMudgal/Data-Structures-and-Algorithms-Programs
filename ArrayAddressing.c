#include<conio.h>
#include<stdio.h>
int B,W,LB1,UB1,LB2,UB2,M,N;
void rowmaj(int J,int K)
{
	int c;
	c= B+W*(N*(J-LB1)+(K-LB2));
	printf("The location of A[J,K] is %d\n",c);
}
void colmaj(int J,int K)
{
	int c;
	c=B+W*((J-LB1)+M*(K-LB2));
	printf("The location of A[J,K] is %d\n",c);
}
int main()
{
	int c,J,K;
	char ch;
	printf("Enter the base address\n");
	scanf("%d",&B);
	W=sizeof(int);
	printf("Enter the first lower bound\n");
	scanf("%d",&LB1);
	printf("Enter the first upper bound\n");
	scanf("%d",&UB1);
	printf("Enter the second lower bound\n");
	scanf("%d",&LB2);
	printf("Enter the second upper bound\n");
	scanf("%d",&UB2);
	M=UB1-LB1+1;
	N=UB2-LB2+1;
	printf("A[%d : %d ,%d : %d]\n",LB1,UB1,LB2,UB2);
	printf("Total no. of rows are M= %d",M);
	printf("\nTotal no. of columns are N= %d",N); 
    do{
	printf("\n----Which address do you want to find out ?------\n1.ROW MAJOR\n2.COLUMN MAJOR\nENTER YOUR CHOICE\n");
    scanf("%d",&c);
    switch(c)
    {
    	case 1 :  printf("Enter the value of J & K\n");
    	        scanf("%d%d",&J,&K);
	             rowmaj(J,K);
		        break;
		case 2: printf("Enter the value of J & K\n");
    	        scanf("%d%d",&J,&K);
		        colmaj(J,K);
		        break; 
		default: printf("Wrong choice\n");
		break;		       
	}
	printf("Do you want to continue\n");
	scanf("%c",&ch);
	scanf("%c",&ch);
}
while(ch='y'||ch=='Y');
getch();
return 0;
}

