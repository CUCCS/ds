#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

typedef struct LNODE{
	int data;
	struct LNODE *next;
}LNODE,*LinkList;
LNODE  *Create()  //返回值: 链表的首指针
{
    LNODE  *p1, *p2, *head;    int a;   head = NULL;
    //输入一个整数, 以 －1 结束: 
    scanf("%d",&a);
    while( a != -1 ) // 循环输入数据，建立链表
    {
        p1=(LNODE *)malloc(sizeof(LNODE));
        p1->data = a;
        if(head==0 ) // ①建立首结点
        {
            head=p1;
            p2=p1;
        }
        else // ②处理中间结点
        {
            p2->next=p1;
            p2=p1;
        }
        printf("请输入一个整数, 以 －1 结束: ");
        scanf("%d",&a);
    }
    if(head != 0)
        p2->next=0;//③处理尾结点, 可能第1次就输入 -1
    return(head); //返回创建链表的首指针
}
LinkList MergeList_L(LinkList La,LinkList Lb)//合并
{
  LinkList   pa,pb,pc,Lc; 
  Lc=(LinkList)malloc(sizeof(LNODE)); 
  Lc-> data=La-> data+Lb-> data; 
  pa=La-> next; 
  pb=Lb-> next; 
  Lc=pc=La; 
  while(pa&&pb) 
    { 
      if(pa-> data <=pb-> data) 
        { 
          pc-> next=pa;pc=pa;pa=pa->next; 
        } 
      else 
        {pc-> next=pb;pc=pb;pb=pb-> next;} 
    } 
    pc-> next=pa?pa:pb; 
    free(Lb); 
    return   Lc; 
} 
int PrintLinkList(LinkList L) //打印链表 
{ 
  LinkList   q; 
  q=L; 
  if(q!=NULL) 
  {
    q=q-> next; 
    do 
      { 
        printf( "%d ",q-> data); 
                q=q-> next; 
      } 
    while(q!=NULL); 
  printf( "\n "); 
  } 
  return 0; 
} 
int main()
{
	LinkList L1=Create();
	LinkList L2=Create();
	LinkList L3;
	L3=MergeList_L(L1,L2);                           
    PrintLinkList(L3);  

	return 0;


}