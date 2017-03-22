#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

typedef struct LNODE{
	int data;
	struct LNODE *next;
}LNODE,*LinkList;
LNODE  *Create()  //����ֵ: �������ָ��
{
    LNODE  *p1, *p2, *head;    int a;   head = NULL;
    //����һ������, �� ��1 ����: 
    scanf("%d",&a);
    while( a != -1 ) // ѭ���������ݣ���������
    {
        p1=(LNODE *)malloc(sizeof(LNODE));
        p1->data = a;
        if(head==0 ) // �ٽ����׽��
        {
            head=p1;
            p2=p1;
        }
        else // �ڴ����м���
        {
            p2->next=p1;
            p2=p1;
        }
        printf("������һ������, �� ��1 ����: ");
        scanf("%d",&a);
    }
    if(head != 0)
        p2->next=0;//�۴���β���, ���ܵ�1�ξ����� -1
    return(head); //���ش����������ָ��
}
LinkList MergeList_L(LinkList La,LinkList Lb)//�ϲ�
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
int PrintLinkList(LinkList L) //��ӡ���� 
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