#include "Queue.h"  
#include <stdio.h>  
void visit(PNode pq)  
{  
  
printf("�ýڵ��Ԫ��Ϊ: %d\n",pq->data);  
  
}  
  
int main()  
{  
  
Queue* pq = InitQueue();  
int i,item;  
  
printf("����0-9��10���������\n");  
  
for(i =0; i < 10; i++)  
{  
    EnQueue(pq,i);  
    GetRear(pq,&item);  
    printf("%d ",item);  
  
}  
printf("\n");  
  
  
  
printf("����������У���ִ��visit����:\n");  
  
QueueTraverse(pq,&visit);  
printf("����Ԫ�س��Ӳ������������: \n");  
for(i = 0; i < 10 ; i++)  
{  
    DelQueue(pq,&item);  
    printf("%d",item);  
  
}  
ClearQueue(pq);  
if(IsEmpty(pq))  
printf("�ɹ���������Ϊ��\n");  
DestroyQueue(pq);  
printf("�����ѱ�����\n");  
return 0;  
}