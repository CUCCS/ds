#include "BiTree.h"

int max = 0;

bool EQ(KeyType kval, KeyType data){
	if(kval == data){
		return true;
	}
	else{
		return false;
	}
}

bool LT(KeyType kval, KeyType data){
	if(kval != data && kval < data){
		return true;
	}
	else{
		return false;
	}
}

Status preOrderTraverse(BiTree T){
	if(T){
		printf("%d", T->data);
		if(T->data != max){
			printf(", ");
		}
		preOrderTraverse( T->lchild);
		preOrderTraverse( T->rchild);
		return OK;
	}
	else{
		return ERROR;
	}
}

bool SearchBST(BiTree T, KeyType kval, BiTree f, BiTree *p){
	if(!T){
		*p = f;
		return false;
	}else if(EQ(kval, T->data)){
		*p = T;
		return true;
	}else if(LT(kval, T->data)){
		return SearchBST( T->lchild, kval, T, p);
	}else{
		return SearchBST( T->rchild, kval, T, p);
	}
}

bool InsertBST(BiTree *T, KeyType e, BiTree p){
	BiTree s = NULL;
	if(max < e){
		max = e;
	}
	if(!(s = (BiTNode * )malloc(sizeof(BiTNode)))){
		exit(OVERFLOW);
	}
	if(!(p = (BiTNode * )malloc(sizeof(BiTNode)))){
		exit(OVERFLOW);
	}
	if(!SearchBST(*T, e, NULL, &p)){
		s->data = e;
		s->lchild = s->rchild = NULL;
		if(!p){
			*T = s;
		}else if(LT(e, p->data)){
			p->lchild = s;
		}else{
			p->rchild = s;
		}
		return true;
	}else{
		return false;
	}
}

Status Delete(BiTree *p){
	BiTree q = NULL;
	BiTree s = NULL;
	if(!(*p)->rchild){
		q = *p;
		(*p) = (*p)->lchild;
	}else if(!(*p)->lchild){
		q = *p;
		(*p) = (*p)->rchild;
	}else{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild){
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q != (*p)){
			q->rchild = s->lchild;
		}else{
			q->rchild = s->lchild;
		}
	}
	return OK;
}

bool DeleteBST(BiTree *T, KeyType kval){
	if(!T){
		return false;
	}else{
		if(EQ(kval, ( *T )->data)){
			Delete(T);
			return true;
		}else if(LT(kval, ( *T )->data)){
			return DeleteBST(&(*T)->lchild, kval);
		}else{
			return DeleteBST(&(*T)->rchild, kval);
		}
	}
}