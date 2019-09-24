#include<stdio.h>
#include<stdlib.h>


//beer=1
//bread=2
//cola=3
//diaper=4
//eggs=5
//milk=6



//f[0]={2,6}
//f[1]={2,4,1,5}
//f[2]={6,4,1,3}
//f[3]={2,6,4,1}
//f[4]={2,6,4,3}

int t=5;//number of transaction
int n=4;//max items in one transaction
int el=6;//number of items
int k[20]={1,2,0,0,1,3,4,5,2,3,4,6,1,2,3,4,1,2,3,6};
int supcount=3;//support count since its 60% 0.6*5=3

struct node
{
  int key[4];
  struct node *p[5];
};
typedef struct node *node;

struct itemset
{
  
}
node root,rooti;

node getnode();
void key_assign(node root,int fk[25],int a,int b);
void print(node root);
void apriori(int supcount);
void item(int x);

node getnode()
{
  node x;
  x=(node)malloc(sizeof(struct node));
  if(x==NULL)
  {
   printf("out of memory\n");
  }
  else
  return x;
}

void key_assign(node root,int fk[25],int a,int b)
{
 int i,j,count=0;
 node c;
 for(i=0;i<b;i++)
 {
  c=getnode();
  root->p[i]=c;
  for(j=0;j<a;j++)
  {
   root->p[i]->key[j]=fk[count];
   printf("%d ",root->p[i]->key[j]);
   count++;
  }
  printf("\n");
 }
}

void print(node root)
{
 int i,j;
 for(i=0;i<t;i++)
 {
  for(j=0;j<n;j++)
  {
  printf("%d ",root->p[i]->key[j]);
  item(root->p[i]->key[j]);
  
  }
  printf("\n");
 }
}

void apriori(int supcount)
{
 int i,k=1,fk[25],count,l=0,m,item_set=1;
 for(i=1;i<=el;i++)
 {
  count=counti(i);
  if(count>=supcount)
  {
    fk[l]=i;//the item which are frequent
    l++;
  }
 }
 root=getnode();
 key_assign(root,fk,item_set,l);//1 element itemset
 item_set++;
 check_for_match(itemset,fk,l);
 //for(m=0;m<l;m++)
  //{
  // printf("%d",fk[m]);
  // item(fk[m]);
 // } 
}

int counti(int item)
{
  int c=0,a,i;
  a=t*n;//total elements in array k
  for(i=1;i<=a;i++)
  {
   if(item==k[i])
   {
    c++;
   }
  }
  return c;
}
void item(int x)
{
 if(x==1)
 {
  printf(" Beer ");
 }
 else if(x==2)
 {
  printf(" Bread ");
 }
 else if(x==3)
 {
  printf(" Cola ");
 }
 else if(x==4)
 {
  printf(" Diaper ");
 }
 else if(x==5)
 {
  printf(" Egg ");
 }
 else if(x==6)
 {
  printf(" Milk ");
 }
 else 
 {
  printf(" Nothing ");
 }
}
void initial_assign(node rooti)//initial transaction is in rooti 
{
 int i,j,count=0;
 node a;
 for(i=0;i<t;i++)
 {
  a=getnode();
  rooti->p[i]=a;
  for(j=0;j<n;j++)
  {
   rooti->p[i]->key[j]=k[count];
   printf("%d ",rooti->p[i]->key[j]);
   count++;
  }
  printf("\n");
 }
}
void check_for_match(int item_set,int fk[25],int l)
{
  int item1,item2,i,j,k,m,count=0,q,r;
  for(i=0;i<l-1;i++)
  {
   for(m=i+1;m<l;m++)
   {
    item1=fk[i];//assign 2 elements and check for its existance in the transaction
    item2=fk[m];
    goto label;
   }
  }
 
label:
  {
  for(j=0;j<t;j++)
  {
   for(k=0;k<n;k++)
   {
    if(rooti->p[j]->key[k]==item1)
    {
      for(r=k+1;r<n-1;r++)
      {
      rooti->p[j]->key[r]==item2;
      count++;
      }
    }
   }
  }
  if(count>=supcount)
  {
   
  }
  }
}
void main()
{
 int i,supcount;
 rooti=getnode();
 initial_assign(rooti);
 supcount=3;//0.6*5;//asssuming support threshold to be 60%
 apriori(supcount);
}
