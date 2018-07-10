include<stdio.h>
#include<conio.h>
void bserc(int A[],int N,int x)
{int first=0,last=N-1,mid;
	while(first<=last&&x!=A[mid])
	{
		mid=(first+last)/2;
		if(A[mid]==x)
		printf("The position of the element is %d\n",mid+1);
		else if(x>A[mid])
		first=mid+1;
		else
		last=mid-1;
	}
	}
int main()
{            int A[10],N,i,x;
	printf("Enter the no. of elements to be taken\n");
	scanf("%d",&N);
	printf("Enter %d elements of array\n",N);
	for(i=0;i<N;i++)
	scanf("%d",&A[i]);
	printf("Enter the element to be searched\n");
	scanf("%d",&x);
	bserc(A,N,x);
    getch();
return 0;	
}

