#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "solveException.h"

#define DEBUG 1
#define debug_print(...) if(DEBUG){printf(__VA_ARGS__);}

typedef char Elemtype;
typedef struct _Node {
	Elemtype data;
	struct _Node* parent;
	struct _Node* left;
	struct _Node* right;
}Node, *Tree;
typedef enum _Order { pre, in, post, all } Order;

/*===字符串相关===*/
/*手动获取子串*/
char* substr(char* source, int begin, int end);
/*手动分割字符串*/
void divideString(char* source, char delim, char** pDes1, char** pDes2);

inline Node* newNode();
void InitializeTree(Tree* pT);
void _TraverseTree(const Tree root, Order order);
/*遍历二叉树*/
/*root : 待遍历的二叉树*/
/*order : 遍历顺序(pre , in , post , all 分别为前序、中序、后序及所有顺序)*/
void TraverseTree(const Tree root, Order order);
inline int getDepth(const Tree t);
/*新建一个完全二叉树*/
void NewCBTree(Tree* pRoot, int depth);
/*删除树中数据为c的节点*/
void DeleteSpecialNode(Tree *pRoot, Elemtype c);
/*根据一个完整先序序列建立二叉树*/
Tree newBinaryTree(char* str);
/*根据一个不完整的先序序列与一个不完整的中序序列建立二叉树*/
Tree _newBinaryTree2(char* pre, char* in);
Tree newBinaryTree2(char*pre, char* in);