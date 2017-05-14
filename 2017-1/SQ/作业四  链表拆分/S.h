

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkList;

typedef enum {
	ERROR,
	OK
}Status;

typedef enum {
	false,
	true
}bool;

ElemType GetElem(LinkList *L, int i);
LinkList* CreateList(LinkList *L, int n);
LinkList* ListInsert(LinkList *L, ElemType e);
LinkList* Connect(LinkList *L);
Status Traverse(LinkList *L);
Status DestroyList(LinkList *L);
bool ListEmpty(LinkList *L);
int InputSize();