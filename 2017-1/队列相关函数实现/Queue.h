    #ifndef QUEUE_H_  
    #define QUEUE_H_  
      
    typedef int Item;  
      
    typedef struct node  
    {  
        Item data;  
        struct node* next;  
    }Node,*PNode;  
      
    typedef struct   
    {  
        PNode front;  
        PNode rear;  
        int size;  
      
    }Queue;  
      
      
      
      
    /*����һ���ն���*/  
    Queue* InitQueue();  
      
    /*����һ������*/  
    void DestroyQueue(Queue* pqueue);  
      
    /*���һ������*/  
    void ClearQueue(Queue* pqueue);  
      
    /*�ж�һ�������Ƿ�Ϊ��*/  
    int IsEmpty(Queue* pqueue);  
      
    /*���ض��д�С*/  
    int GetSize(Queue* pqueue);  
      
    /*���ض�ͷԪ��*/  
    PNode GetFront(Queue* pqueue,Item *pitem);  
      
    /*���ض�βԪ��*/  
    PNode GetRear(Queue* pqueue,Item *pitem);  
      
    /*����Ԫ�����*/  
    PNode EnQueue(Queue* pqueue,Item item);  
      
    /*����ͷԪ�س���*/  
    PNode DelQueue(Queue* pqueue,Item *pitem);  
      
      
      
    /*�������У����Ը������ݵ���visit����*/  
    void QueueTraverse(Queue* pqueue,void (*visit)(PNode));  
      
      
    #endif  