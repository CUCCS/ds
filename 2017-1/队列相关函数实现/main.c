#include "Queue.h"  
#include <stdio.h>  
void visit(PNode pq)  
{  
  
printf("该节点的元素为: %d\n",pq->data);  
  
}  
  
int main()  
{  
  
Queue* pq = InitQueue();  
int i,item;  
  
printf("输入0-9共10个数字入队\n");  
  
for(i =0; i < 10; i++)  
{  
    EnQueue(pq,i);  
    GetRear(pq,&item);  
    printf("%d ",item);  
  
}  
printf("\n");  
  
  
  
printf("遍历这个队列，并执行visit函数:\n");  
  
QueueTraverse(pq,&visit);  
printf("队列元素出队并依次输出如下: \n");  
for(i = 0; i < 10 ; i++)  
{  
    DelQueue(pq,&item);  
    printf("%d",item);  
  
}  
ClearQueue(pq);  
if(IsEmpty(pq))  
printf("成功将队列置为空\n");  
DestroyQueue(pq);  
printf("队列已被销毁\n");  
return 0;  
}