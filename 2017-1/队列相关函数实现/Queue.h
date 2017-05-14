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
      
      
      
      
    /*构造一个空队列*/  
    Queue* InitQueue();  
      
    /*销毁一个队列*/  
    void DestroyQueue(Queue* pqueue);  
      
    /*清空一个队列*/  
    void ClearQueue(Queue* pqueue);  
      
    /*判断一个队列是否为空*/  
    int IsEmpty(Queue* pqueue);  
      
    /*返回队列大小*/  
    int GetSize(Queue* pqueue);  
      
    /*返回对头元素*/  
    PNode GetFront(Queue* pqueue,Item *pitem);  
      
    /*返回队尾元素*/  
    PNode GetRear(Queue* pqueue,Item *pitem);  
      
    /*将新元素入队*/  
    PNode EnQueue(Queue* pqueue,Item item);  
      
    /*将队头元素出队*/  
    PNode DelQueue(Queue* pqueue,Item *pitem);  
      
      
      
    /*遍历队列，并对各项数据调用visit函数*/  
    void QueueTraverse(Queue* pqueue,void (*visit)(PNode));  
      
      
    #endif  