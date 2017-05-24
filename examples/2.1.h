#define LISTSIZE 100    // 容量：存储空间的最大分配量

typedef int ElemType;

typedef  struct _SqList{
    ElemType elem[LISTSIZE];
    int      length;          // 当前长度
	int      listsize;
} SqList;

#define OK 0
#define ERROR 1
#define OVERFLOW 2

#define List SqList

void Union(List *a, List b);

int ListLength(List a);

void GetElem(List Lb, int i, ElemType *e);

int LocateElem(List La, ElemType e, int (*equal)(ElemType, ElemType));

int ListInsert(List *L, int i, ElemType e);

int (*equal)(ElemType, ElemType);

void InitList(List *L);

void ListTraverse(List L);
