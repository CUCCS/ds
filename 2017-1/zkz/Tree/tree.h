#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
/*输出二叉树*/
/*root : 待遍历的二叉树*/
/*order : 遍历顺序(pre , in , post , all 分别为前序、中序、后序及所有顺序)*/
void Show(const Tree root, Order order);
inline int getDepth(const Tree t);
/*删除树中数据为c的节点*/
void DeleteSpecialNode(Tree *pRoot, Elemtype c);
/*根据一个完整先序序列建立二叉树*/
Tree newBinaryTree(char* str);
/*根据一个不完整的先序序列与一个不完整的中序序列建立二叉树*/
Tree _newBinaryTree2(char* pre, char* in);
Tree newBinaryTree2(char*pre, char* in);
/*计算二叉树的深度与宽度*/
void CalculateDepthAndWidth(const Tree t, int* pD, int * pW);
/*统计二叉树中所有叶与非叶节点的个数*/
void CountLeaves(const Tree t, int* pLeaf);
void CountBranches(const Tree t, int* pBranch);
/*判断是否为完全二叉树*/
int isCompleteBinaryTree(const Tree t);