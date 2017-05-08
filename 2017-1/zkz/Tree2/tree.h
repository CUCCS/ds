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

/*===�ַ������===*/
/*�ֶ���ȡ�Ӵ�*/
char* substr(char* source, int begin, int end);
/*�ֶ��ָ��ַ���*/
void divideString(char* source, char delim, char** pDes1, char** pDes2);

inline Node* newNode();
void InitializeTree(Tree* pT);
/*���������*/
/*root : �������Ķ�����*/
/*order : ����˳��(pre , in , post , all �ֱ�Ϊǰ�����򡢺�������˳��)*/
void Show(const Tree root, Order order);
inline int getDepth(const Tree t);
/*ɾ����������Ϊc�Ľڵ�*/
void DeleteSpecialNode(Tree *pRoot, Elemtype c);
/*����һ�������������н���������*/
Tree newBinaryTree(char* str);
/*����һ��������������������һ�����������������н���������*/
Tree _newBinaryTree2(char* pre, char* in);
Tree newBinaryTree2(char*pre, char* in);
/*������������������*/
void CalculateDepthAndWidth(const Tree t, int* pD, int * pW);
/*ͳ�ƶ�����������Ҷ���Ҷ�ڵ�ĸ���*/
void CountLeaves(const Tree t, int* pLeaf);
void CountBranches(const Tree t, int* pBranch);
/*�ж��Ƿ�Ϊ��ȫ������*/
int isCompleteBinaryTree(const Tree t);