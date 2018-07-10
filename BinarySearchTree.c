#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
   int info;
  struct node*left;
    struct node*right;
}
void pre_order(struct node*root)
{
    if(root!=NULL)
{
printf("%d ",root->info);
pre_order(root->left);
pre_order(root->right);
	}
}
void post_order(struct node *root)
{
if(root!=NULL)
{
post_order(root->left);
post_order(root->right);
printf("%d ",root->info);
	}
}
void in_order(struct node*root)
{
if(root!=NULL)
{
in_order(root->left);
printf("%d ",root->info);
in_order(root->right);
		}
}
struct node*search(struct node*root,int x)
{
if(root->info==x||root==NULL)
return root;
else if(root->info>x)
return search(root->left,x);
else 
return search(root->right,x);
}
struct node*findl(struct node*tree)
{
if(tree==NULL||tree->right==NULL)
return tree;
else
return findl(root->right);
}
void insert(struct node**tree,int x)
{
if((*tree)==NULL)
{
(*tree)=(struct node*)malloc(sizeof(struct node*));
(*tree)->info=x;
(*tree)->left=NULL;
(*tree)->right=NULL;
}
else if((*tree)->info>x)
insert(&((*tree)->left),x);
else
insert(&((*tree)->right),x);
}
void deletet(struct node**tree,int x)
{
if((*tree)==NULL)
printf("NO node\n");
else if((*tree)->info>x)
deletet(&((*tree)->left),x);
else if((*tree)->info<x)
deletet(&((*tree)->left),x);
else if((*tree)->left &&(*tree)->right)
{
struct node*temp;
temp=findl((*tree)->left);
(*tree)->info=temp->info;
deletet(&((*tree)->left),temp->info);
}
else
{
temp=(*tree);
if((*tree)->left==NULL&&(*tree)->right==NULL)
(*tree)=NULL;
else if ((*tree)->left!=NULL)
(*tree)=(*tree)->left;
else
(*tree)=(*tree)->right;
free(temp);
}
}
void main()
{
int x,c;
struct node*root,loc;
char ch;
do{
printf("----MAIN MENU-----\n1.In order traversal\n2.Pre order traversal\n3.Post order traversal\n4.Search an element \n5.Insert\n6.Delete\nEnter your choice\n");
scanf("%d",&c);
switch(c)
{
case 1: pre_order(root);
	 break;
   case 2: in_order(root);
	    break;
case 3: post_order(root);
                break;
case 4: printf("Enter the element to be searched\n");
          scanf("%d",&x);
        loc=search(root,x);
        break;
case 5:	printf("Enter the element to be inserted\n");
        scanf("%d",&x);
	insert(&(root),x);
	break;
case 6: printf("Enter the element to be deleted\n");
       scanf("%d",&x);
      deletet(&(root),x);
        break;
default:printf("Wrong choice\n");	   							  
		}
printf("Do you want to continue?\n");
scanf("%c",&ch);
 scanf("%c",&ch);	
	}
while(ch=='y'||ch=='Y');
getch();
}

