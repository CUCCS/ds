typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node * next;
}Node;
typedef Node* LinkList;

typedef enum Status { OK, ERROR, OVERFLOW } Status;

/*�ú궨����ٴ����½ڵ�*/
#define NEWNODE (LinkList)malloc(sizeof(Node))
/*�������������ڴ����ڵ�ʱ�����������������*/
#define RANDBASE 10
#define RANDMAXINCREMENT 5
#define RANDMININCREMENT 1
/*���������ָ���Ƿ�����������й���*/
#define DEBUG 1

/*��������*/
/*��������*/
Status CreateList(LinkList, const int);
/*�����������*/
Status TravelList(const LinkList);
/*�㷨2.12 �鲢����*/
Status MergeList(LinkList, LinkList, LinkList);