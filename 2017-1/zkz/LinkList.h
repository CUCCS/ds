typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node * next;
}Node;
typedef Node* LinkList;

typedef enum Status { OK, ERROR, OVERFLOW } Status;

/*用宏定义快速创建新节点*/
#define NEWNODE (LinkList)malloc(sizeof(Node))
/*这三个宏用于在创建节点时生成随机的有序数据*/
#define RANDBASE 10
#define RANDMAXINCREMENT 5
#define RANDMININCREMENT 1
/*这个宏用于指定是否输出函数运行过程*/
#define DEBUG 1

/*函数声明*/
/*创建链表*/
Status CreateList(LinkList, const int);
/*遍历输出链表*/
Status TravelList(const LinkList);
/*算法2.12 归并链表*/
Status MergeList(LinkList, LinkList, LinkList);