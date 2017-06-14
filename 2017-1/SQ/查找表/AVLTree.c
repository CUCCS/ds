#include "AVLTree.h"

Status CreateAVLT(AVLTree *T, ElemType d[], int n) {
	// 构造二叉平衡树
	int i;
	bool taller = false;
	for (i = 0; i < n; i++) {
		InsertAVLT(T, d[i], &taller); 
	}
	if (!T) {
		return OK;
	}
	return ERROR;
}

Status SearchAVLT(AVLTree *T, KeyType kval, AVLTree f, AVLTree *p) {
	// 在根指针 T 所指二叉树中递归地查找其关键字等于 kval 的数据元素
	// 若查找成功，则返回指针 p 指向该数据元素的结点，并返回函数值为 true
	// 否则表明查找不成功，返回指针 p 指向查找路径上访问的最后一个结点，并返回函数值为false
	// 指针 f 指向当前访问的结点的双亲，其初始调用值为NULL
	if (!*T) { // 空树，查找不成功
		*p = f;
		return ERROR;
	}
	else if (EQ(kval, (*T)->key)) {
		*p = *T;
		return OK;   // 查找成功
	}
	else if (LT(kval, (*T)->key)) { // 在左子树中继续查找
		return SearchAVLT(&(*T)->lchild, kval, *T, p);
	}
	else { // 在右子树中继续查找
		return SearchAVLT(&(*T)->rchild, kval, *T, p);
	}
}

bool EQ(KeyType a, KeyType b) {
	// 若a与b相等，返回true，否则返回false 
	if (a == b) {
		return true;
	}
	return false;
}

bool LT(KeyType a, KeyType b) {
	// 若a小于b，返回true，否则返回false 
	if (a < b) {
		return true;
	}
	return false;
}

Status InsertAVLT(AVLTree *T, ElemType e, bool *taller) {
	// 若再平衡的二叉排序树T中不存在和e相等的结点，则插入一个数据元素为e的新结点，并返回成功
	// 若因插入而使二叉排序树失去平衡，则作平衡旋转处理，布尔变量taller反应T长高与否
	if (!(*T)) {
		*T = (AVLTree)malloc(sizeof(AVLTNode));
		(*T)->key = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else {
		if (EQ(e, (*T)->key)) {
			*taller = false;
			return ERROR;
		}
		if (LT(e, (*T)->key)) {
			if (InsertAVLT(&(*T)->lchild, e, taller)) {
				return ERROR;
			}
			if (*taller) {
				switch ((*T)->bf) {
				case LH:
					LeftBalance(T);
					*taller = false;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = false;
					break;
				}
			}	
		}
		else {
			if (InsertAVLT(&(*T)->rchild, e, taller)) {
				return ERROR;
			}
			if (*taller) {
				switch ((*T)->bf) {
				case LH:
					(*T)->bf = EH;
					*taller = false;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = true;
					break;
				case RH:
					RightBalance(T);
					*taller = false;
					break;
				}
			}
		}
	}
	return OK;
}

Status L_Rotate(AVLTree *T) {
	// 对以指针 *T 为根的二叉排序树作左旋处理，处理之后 T 指向新的根节点
	AVLTree rc;
	rc = (*T)->rchild;
	(*T)->rchild = rc->lchild;
	rc->lchild = (*T);
	(*T) = rc;
	return OK;
}

Status R_Rotate(AVLTree *T) {
	// 对以指针 *T 为根的二叉排序树作右旋处理，处理之后 T 指向新的根节点
	AVLTree lc;
	lc = (*T)->lchild;
	(*T)->lchild = lc->rchild;
	lc->rchild = (*T);
	(*T) = lc;
	return OK;
}

Status LeftBalance(AVLTree *T) {
	// 对以指针T所指结点为根的二叉树作左平衡旋转处理，算法结束时T指向新的根节点
	AVLTree lc, rc;
	lc = (*T)->lchild;
	rc = NULL;
	if (lc) {
		switch (lc->bf) {
		case LH:
			(*T)->bf = lc->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			rc = lc->rchild;
			switch (rc->bf) {
			case LH:
				(*T)->bf = RH;
				lc->bf = EH;
				break;
			case EH:
				(*T)->bf = lc->bf = EH;
				break;
			case RH:
				(*T)->bf = EH;
				lc->bf = LH;
				break;
			}
			rc->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
			break;
		}
		return OK;
	}
	return ERROR;
}

Status RightBalance(AVLTree *T) {
	// 对以指针T所指结点为根的二叉树作右平衡旋转处理，算法结束时T指向新的根节点
	AVLTree lc, rc;
	rc = (*T)->rchild;
	lc = NULL;
	if (rc) {
		switch (rc->bf) {
		case RH:
			(*T)->bf = rc->bf = EH;
			L_Rotate(T);
			break;
		case LH:
			lc = rc->lchild;
			switch (lc->bf) {
			case LH:
				(*T)->bf = EH;
				rc->bf = RH;
				break;
			case EH:
				(*T)->bf = rc->bf = EH;
				break;
			case RH:
				(*T)->bf = LH;
				rc->bf = EH;
				break;
			}
			lc->bf = EH;
			R_Rotate(&(*T)->rchild);
			L_Rotate(T);
			break;
		}
		return OK;
	}
	return ERROR;
}

Status PreOrderTraverse(AVLTree T, FILE *p, Status(*Visit)(ElemType)) {
	// 先序遍历二叉树,对每个数据元素调用函数Visit
	if (T) {
		fprintf(p, ", ");
		Visit(T->key, p);
		PreOrderTraverse(T->lchild, p, Visit);
		PreOrderTraverse(T->rchild, p, Visit);
		return OK;
	}
	return ERROR;
}

Status Visit(ElemType e, FILE *p) {
	// 输出元素
	fprintf(p, "%d", e);
	return OK;
}

Status PrintTree(AVLTree T, FILE *p) {
	// 打印输出整棵二叉树
	Visit(T->key, p);
	PreOrderTraverse(T->lchild, p, Visit);
	PreOrderTraverse(T->rchild, p, Visit);
	fprintf(p, "\n");
}

//===============以下参考代码(删除操作)=============//
// 参数说明：*T为待进行调整的子树的根结点
// bfChild为*T在删除结点前的平衡因子
Status DelLeftCase(AVLTree *T, int bfChild)
{
	// 当bf为-1或1变为0，或者孩子为空时说明子树高降低     
	if ((!(*T)->lchild) || (EH != bfChild && EH == (*T)->lchild->bf)) {
		switch ((*T)->bf) { // 左子树树高降低
		case EH:
			(*T)->bf = RH;
			break;
		case LH:
			(*T)->bf = EH;
			break;
		case RH:        // 原本右子树比较高   
			RightBalance(T);
			break;
		}
		return OK;
	}
	else {
		return ERROR;
	}
}

Status DelRightCase(AVLTree *T, int bfChild)
{
	// 当bf为LH或RH变为EH，或者孩子为空时说明子树高降低
	if ((!(*T)->rchild) || (EH != bfChild && EH == (*T)->rchild->bf)) {
		switch ((*T)->bf) { // 右子树树高降低
		case EH:
			(*T)->bf = LH;
			break;
		case RH:
			(*T)->bf = EH;
			break;
		case LH:    //原本左子树比较高    
			LeftBalance(T);
			break;
		}
		return OK;
	}
	else {
		return ERROR;
	}
}

AVLTree DeleteNode(AVLTree *T, KeyType key)
{
	// 递归找到元素值为key的元素，删除该元素，调整当前子树的平衡
	// 跳出递归时，依次利用递归调整子树的平衡直至根节点
	int bfChild = 0;
	if (*T) {
		if (LT(key, (*T)->key)) { // 当前元素大于待删除元素
			bfChild = (*T)->lchild->bf;
			(*T)->lchild = DeleteNode(&(*T)->lchild, key); // 继续在左子树中进行查找
			DelLeftCase(T, bfChild);
		}
		else if (LT((*T)->key, key)) { // 当前元素小于待删除元素
			bfChild = (*T)->rchild->bf;
			(*T)->rchild = DeleteNode(&(*T)->rchild, key); // 继续在右子树中进行查找
			DelRightCase(T, bfChild);
		}
		else // 当前节点就是要删除的节点
		{
			if ((*T)->lchild)        // *T不是叶子结点并且具有直接前驱
			{
				AVLTree farRight, temp;
				// AVLTree farRight = GofarRight((*T)->lchild);
				// 根据http://www.cs.usfca.edu/~galles/visualization/RedBlack.html
				// 人工输入数据，看动态图的演示推测出farRight的指向
				temp = (*T)->lchild->rchild; 
				while (temp) {
					farRight = temp;
					temp = temp->rchild;
				}
				(*T)->key = farRight->key; // 交换元素值
				// 可以确定，删除的节点为当前节点的左子树的某一个节点
				(*T)->lchild = DeleteNode(&(*T)->lchild, farRight->key); // 删除元素值为key的节点
				DelLeftCase(T, bfChild); // 左子树平衡调整
			}
			else if ((*T)->rchild)    // *T不是叶子结点并且具有直接后驱
			{
				AVLTree farLeft, temp;
				// AVLTree farLeft = GofarLeft((*T)->rchild);
				// 根据http://www.cs.usfca.edu/~galles/visualization/RedBlack.html
				// 人工输入数据，看动态图的演示推测出farLeft的指向
				temp = (*T)->rchild->lchild;
				while(temp){
					farLeft = temp;
					temp = temp->lchild;
				}
				(*T)->key = farLeft->key; // 交换元素值
				(*T)->rchild = DeleteNode(&(*T)->rchild, farLeft->key); // 删除元素值为key的节点
				DelRightCase(T, bfChild); // 右子树平衡调整
			}
			else             // *T是叶子结点
			{
				free(*T);
				*T = NULL;
			}
		}
	}
	return (*T); // 包含了返回NULL与正常的当前节点
}