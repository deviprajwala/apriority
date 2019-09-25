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

//int t=5;//number of transaction
//int n=4;//max items in one transaction
//int el=6;//number of items
//int k[20]={1,2,0,0,1,3,4,5,2,3,4,6,1,2,3,4,1,2,3,6};
//int supcount=3;//support count since its 60% 0.6*5=3

struct two_itemset
{
  int a;
  int b;
  struct two_itemset *link;
};
typedef struct two_itemset *two_item;

struct three_itemset
{
  int x;
  int y;
  int z;
};
typedef struct three_itemset three_item;

//void item(int x);
//two_item get();
//two_item insert(int x,int y,two_item head);
//void print(two_item head);
 

two_item get()
{
 two_item x;
 x=(two_item)malloc(sizeof(struct two_itemset));
 return x;
}
two_item insert(int x,int y,two_item head)
{
  two_item prev,cur;
  prev=NULL;
  cur=head;
  if(cur==NULL)
  {
   return head;
  }
  while(cur!=NULL)
  {
    prev=cur;
    cur=cur->link;
  }
  cur=get();
  cur->a=x;
  cur->b=y;
  prev->link=cur;
  cur->link=NULL;
  return head;
}
void print(two_item head)
{
 two_item cur;
 cur=head;
 if(head==NULL)
{
  printf("empty\n");
  return;
}
 while(cur!=NULL)
 {
  printf("%d %d ",cur->a,cur->b);
  cur=cur->link;
 }
 printf("\n");
 return;
}
int main()
{
 
 two_item head,cur;
 head->a=1;
 head->b=2;
 head->link=NULL;
 three_item p;
 head=insert(3,4,head);
 
 
 p.x=1;
 p.y=2;
 p.z=3;
 
 printf("%d %d %d\n",p.x,p.y,p.z);
 print(head);
 return(0);
}
