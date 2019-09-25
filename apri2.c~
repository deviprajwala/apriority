#include <stdio.h>
#include <stdlib.h>

int matrix[25][25];
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
int el=6;//number of items
int fk[20];//frequent 1 itemset
int supcount=3;//support count ,we assume it to be 60% 0.6*5=3
struct two_itemset {
   int key1;
   int key2;
   struct two_itemset *link;
};

typedef struct two_itemset *two_item;
two_item head = NULL;

void init_matrix();
void print_matrix();
int frequent_1itemset();
void frequent_2itemset(int fk_size);
void print();
void insertFirst(int key1, int key2) ;
void frequent_3itemset();
void item(int x);

void init_matrix()
{
  int i,j;
  printf("Enter the matrix elements\n");
  for(i=1;i<=t;i++)
  {
   for(j=1;j<=el;j++)
   {
     scanf("%d",&matrix[i][j]);
   }
  }
}
void print_matrix()
{
  int i,j;
  printf("\n\nThe matrix elements\n");
  for(i=1;i<=t;i++)
  {
   for(j=1;j<=el;j++)
   {
     printf("%d ",matrix[i][j]);
   }
   printf("\n");
  }
}
int frequent_1itemset()
{
  int i,j,count1=0,k=0;
  for(j=1;j<=el;j++)
  {
   for(i=1;i<=t;i++)
   {
     if(matrix[i][j]==1)
     {
       count1++;
     }
   }
   if(count1>=supcount)
   {
    fk[k]=j;
    k++;
   }
   count1=0;
  }
  printf("\n\nThe frequent 1-item set is:\n");
  for(i=0;i<k;i++)
  {
   printf("%d ",fk[i]);
   item(fk[i]);
   printf("\n");
  }
  return k-1;
}
void frequent_2itemset(int fk_size)
{
 int i,j,k,key1,key2,count2=0,p=0;
 for(i=1;i<=fk_size-1;i++)
 {
  for(j=i+1;j<=fk_size;j++)
  {
   key1=fk[i];
   key2=fk[j];
   for(k=1;k<=t;k++)
   {
   if(matrix[k][key1]==1&&matrix[k][key2]==1)
    {
     count2++;
    }
   }
   if(count2>=supcount)
   {
    insertFirst(key1,key2);
    p++;
   }
   count2=0;
  }
 }
 
}
 
void print() 
{
   two_item cur;
   cur = head;
   printf("\n\nThe frequent 2-itemset is:\n");
   //printf("\n[ ");  
   while(cur != NULL) 
  {
      printf("(%d,%d) ",cur->key1,cur->key2);
      item(cur->key1);
      item(cur->key2);
      cur = cur->link;
      printf("\n");
  }	
  // printf(" ]\n");
}


void insertFirst(int key1, int key2) 
{
   
   two_item temp;
   temp = (two_item) malloc(sizeof(struct two_itemset));
   temp->key1 = key1;
   temp->key2 = key2;
   temp->link = head;
   head = temp;
}

void frequent_3itemset()
{
  two_item cur;
  int item1,count3=0,k;
  item1=head->key1;
  cur=head->link;
  printf("\n\nItems which are bought together are:\n");
  while(cur!=NULL)
  {
   if(cur->key2==item1)
   {
    for(k=1;k<=t;k++)
    {
     if(matrix[k][cur->key1]==1&&matrix[k][head->key2]==1&&matrix[k][head->key1]==1)
     {
     count3++;
     }
    }
  
    printf("(%d ,%d ,%d)\n",cur->key1,head->key2,head->key1);
    item(cur->key1);
    item(head->key2);
    item(head->key1);
    printf("\nThe frequency of this combination is %d",count3);
    printf("\n");
    
   }
   cur=cur->link;
  }
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
void main() 
{
  int fk_size;
  //printf("Enter the number of transactions\n");
  //scanf("%d",&t);
  printf("The number of transactions is %d\n",t); 
  //printf("Enter the number of items\n");
  //scanf("%d",&el);
  printf("The number of items is %d\n",el); 
   init_matrix();
   print_matrix();
   fk_size=frequent_1itemset();
   frequent_2itemset(fk_size);
   print();
   frequent_3itemset();
}
