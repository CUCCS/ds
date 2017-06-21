// �����������ȺͿ��.cpp : �������̨Ӧ�ó������ڵ㡣
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

//���򴴽�������
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

//������������
int GetDepth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	return GetDepth(pRoot->m_left) > GetDepth(pRoot->m_right) ? 
		(GetDepth(pRoot->m_left) + 1) : (GetDepth(pRoot->m_right) + 1);
}

//��������Ŀ��
int GetWidth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	int nLastLevelWidth = 0;//��¼��һ��Ŀ��
	int nTempLastLevelWidth = 0;
	int nCurLevelWidth = 0;//��¼��ǰ��Ŀ��
	int nWidth = 1;//�������Ŀ��
        queue<BTNode *> myQueue;
	myQueue.push(pRoot);//�����ڵ������
	nLastLevelWidth = 1;	
	BTNode *pCur = NULL;

	while (!myQueue.empty())//���в���
	{
		nTempLastLevelWidth = nLastLevelWidth;
		while (nTempLastLevelWidth != 0)
		{
            pCur = myQueue.front();//ȡ������ͷԪ��
			myQueue.pop();//������ͷԪ�س���

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
    cout << "�����������Ϊ��" << GetDepth(pRoot) << endl;
	cout << "�������Ŀ��Ϊ��" << GetWidth(pRoot) << endl;	
	system("pause");
	return 0;
}
