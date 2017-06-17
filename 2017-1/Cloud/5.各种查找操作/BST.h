#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#define TElemType int 
#define KeyType int 

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild, *parent;

}BiTNode, *BiTree;
typedef enum {
	FALSE,
	TRUE
}bool;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

/* 查找表的初始化建立 */
Status _CreateBST(BiTree *T, TElemType * c);

/* 在T树中查找关键字key */
Status SearchBST(BiTree T, TElemType key, BiTree f, BiTree * p);

/* c插入关键字key */
Status InsertBST(BiTree *T, TElemType key);

/* 打印一遍查找表 */
Status _print(BiTree T);

/* 先序遍历二叉树 */
Status PreOrderTraverse(BiTree T, int i);

/* 删除一个结点 */
Status Delete(BiTree  p, BiTree f);

/* 在查找表中查找 */
Status _Search(BiTree T, TElemType * a);

#endif // !1
