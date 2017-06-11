#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef int ElemType;
typedef struct Node
{
    ElemType key;        //�ؼ���
    struct Node *left;   //����
    struct Node *right;  //�Һ���
    struct Node *parent; //���ڵ�
} Node, *PNode;

//����
void Insert(PNode &root, ElemType key)
{
    //��ʼ��b��������
    PNode p=(PNode)malloc(sizeof(Node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    //����
    if(root == NULL)
    {
        root = p;
        return;
    }
    //����
    if(root->left == NULL && root->key > key)
    {
        p->parent = root;
        root->left = p;
        return;
    }
    //�Һ���
    if(root->right == NULL && root->key < key)
    {
        p->parent = root;
        root->right = p;
        return;
    }

    //�ؼ�ֵС�ڴ�ʱ�Ľڵ�ֵ����������
    //׼���Ļص����ģ�����û�ɹ�...
    if(key < root->key)
        Insert(root->left,key);
    else
        Insert(root->right,key);
}

//����Ԫ��,�ҵ����عؼ��ֵĽ��ָ�룬û�ҵ�����NULL
PNode Search(PNode root, ElemType key)
{
    if(root == NULL || root->key == key)
        return root;

    if(key < root->key) //����������
        return Search(root->left,key);
    else //����������
        return Search(root->right,key);
}

//������С�ؼ���,����ʱ����NULL
PNode SearchMin(PNode root)
{
    if(root == NULL)
        return root;

    while(root->left != NULL)
        root = root->left;
    return root;
}

//�������ؼ���,����ʱ����NULL
PNode SearchMax(PNode root)
{
    if(root == NULL)
        return root;

    while(root->right != NULL) //����
        root = root->right;
    return root;
}

//����ǰ��
PNode SearchPredecessor(PNode x)
{
    if(x == NULL)  //��
        return x;

    //���������ӣ�ǰ������������������
    if(x->left != NULL)
        return SearchMax(x->left);

    PNode y = x->parent;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = x->parent;
    }
    return y;
}

//���Һ��
PNode SearchSuccessor(PNode x)
{
    if(x == NULL)  //��
        return x;

    //�������Һ��ӣ������������������С��
    if(x->right != NULL)
        return SearchMin(x->right);

    PNode y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = x->parent;
    }
    return y;
}

int DeleteNode(PNode &root,ElemType key)
{
    PNode q;
    //���ҵ�Ҫɾ���Ľ��
    PNode p = Search(root, key);

    //û�鵽�˹ؼ���
    if(p == NULL)
        return 0;
    //һ��������������ýڵ���Ҷ�ӽڵ㡢ֻ�����ӡ�ֻ���Һ��ӡ����Һ��Ӷ���
    //Ҷ�ӽ��
    if(p->left == NULL && p->right == NULL)
    {
        //ֻ�и��ڵ�
        if(p->parent == NULL)
        {
            free(p);
            root = NULL;
        }
        else
        {
            //ɾ���Ľ��������
            if(p->parent->left == p)
                p->parent->left = NULL;
            else
                p->parent->right = NULL;
            free(p);
        }
    }

    //����
    else if(p->left != NULL && p->right == NULL)
    {
        p->left->parent = p->parent;
        //���ɾ���Ǹ����
        if(p->parent == NULL)
            root = p->left;
        //���ڵ������
        else if(p->parent->left == p)
            p->parent->left = p->left;
        else
            p->parent->right = p->left;
        free(p);
    }
    //�Һ���
    else if(p->right != NULL && p->left == NULL)
    {
        p->right->parent = p->parent;
        //���ɾ���Ǹ����
        if(p->parent == NULL)
            root = p->right;
        //�Ǹ��ڵ������
        else if(p->parent->left == p)
            p->parent->left=p->right;
        else
            p->parent->right=p->right;
        free(p);
    }
    //���Һ��Ӷ���
    //�ý��ĺ�̽��϶���������
    //ɾ����̽��,��̽���ֵ����ý��
    else
    {
        //�ҵ�Ҫɾ�����ĺ��
        q = SearchSuccessor(p);
        ElemType temp = q->key;    //�ݴ��̽���ֵ

        //ɾ����̽��
        DeleteNode(root, q->key);
        p->key = temp;
    }
    return 1;
}

//������
void Create(PNode& root, ElemType *keyArray, int length)
{
    for(int i = 0; i < length; i++)
        Insert(root, keyArray[i]);  //����
}

int main()
{
    PNode root = NULL;
    ElemType nodeArray[11] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};  //������
    Create(root, nodeArray, 11);  //��������������

    cout<<"�ýڵ��ֵ"<<Search(root,15)->key<<endl;
    cout<<"min = "<<SearchMin(root)->key<<endl;  //��Сֵ
    cout<<"max = "<<SearchMax(root)->key<<endl;  //���ֵ
    cout<<"ǰ��"<<SearchPredecessor(root->right->right)->key<<endl;  //ǰ��
    cout<<"���"<<SearchSuccessor(root->left->right->right)->key<<endl;  //���
    DeleteNode(root, 6);
    cout<<"�ýڵ��ֵ"<<Search(root,15)->key<<endl;
    cout<<"min = "<<SearchMin(root)->key<<endl;  //��Сֵ
    cout<<"max = "<<SearchMax(root)->key<<endl;  //���ֵ
    cout<<"ǰ��"<<SearchPredecessor(root->left)->key<<endl;  //ǰ��
    cout<<"���"<<SearchSuccessor(root->left->right->left)->key<<endl;  //���

    return 0;
}
