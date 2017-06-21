// 求二叉树的深度和宽度.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>  
#include <iostream>
#include <queue>
#include <tchar.h> 
using namespace std;

struct BTNode
{
	char m_value;
	BTNode *m_left;
	BTNode *m_right;
};

//先序创建二叉树
void CreatBTree(BTNode *&root)
{	
	char nValue = 0;
	cin >> nValue;
	if ('#' == nValue)
	{
		return;
	}
	else
	{
		root = new BTNode();
		root->m_value = nValue;
		CreatBTree(root->m_left);
		CreatBTree(root->m_right);
	}	
}

//求二叉树的深度
int GetDepth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	return GetDepth(pRoot->m_left) > GetDepth(pRoot->m_right) ? 
		(GetDepth(pRoot->m_left) + 1) : (GetDepth(pRoot->m_right) + 1);
}

//求二叉树的宽度
int GetWidth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	int nLastLevelWidth = 0;//记录上一层的宽度
	int nTempLastLevelWidth = 0;
	int nCurLevelWidth = 0;//记录当前层的宽度
	int nWidth = 1;//二叉树的宽度
        queue<BTNode *> myQueue;
	myQueue.push(pRoot);//将根节点入队列
	nLastLevelWidth = 1;	
	BTNode *pCur = NULL;

	while (!myQueue.empty())//队列不空
	{
		nTempLastLevelWidth = nLastLevelWidth;
		while (nTempLastLevelWidth != 0)
		{
            pCur = myQueue.front();//取出队列头元素
			myQueue.pop();//将队列头元素出对

			if (pCur->m_left != NULL)
			{
				myQueue.push(pCur->m_left);
			}

			if (pCur->m_right != NULL)
			{
				myQueue.push(pCur->m_right);
			}

			nTempLastLevelWidth--;
		}

		nCurLevelWidth = myQueue.size();
		nWidth = nCurLevelWidth > nWidth ? nCurLevelWidth : nWidth;
		nLastLevelWidth = nCurLevelWidth;
	}

	return nWidth;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BTNode *pRoot = NULL;	
	CreatBTree(pRoot);
    cout << "二叉树的深度为：" << GetDepth(pRoot) << endl;
	cout << "二叉树的宽度为：" << GetWidth(pRoot) << endl;	
	system("pause");
	return 0;
}
