#define OK 0
#define ERROR 1
#define OVERFLOW 2

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;


void CreateList_L(LinkList L);

void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc);

void PrintList(const LinkList L);
