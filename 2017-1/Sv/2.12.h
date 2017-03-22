#define LISTSIZE 100
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

void MergeList_L(LinkList, LinkList, LinkList);
