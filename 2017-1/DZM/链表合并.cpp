#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;   //����ָ��ָ����һ�ڵ�
    int data;   //���������ֵ
	int listsize;   //����������
}Node,*List;

void Merge(List &La,List &Lb,List &Lc)  //�ϲ�����
{
	Node *pa,*pb,*pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La; //��La��ͷ�����ΪLc��ͷ���
	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;  //ʹLc��һ�ڵ����La�е�pa�ڵ��ֵ
			pc = pa;    //��pa�ĵ�ַ��pc��ʵ��pc�ڵ����
			pa = pa->next;  //pa�ڵ�ĺ���
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;  //��paΪ�ǿ�ָ��Ͱ�pa�ĸ�ֵ��pc->next�������pb��ֵ����pc->next
	                          //����ʣ���
	free(Lb);
}

List getList(int a[], int len)  //��ʼ������
{
    Node *head = (Node*)malloc(sizeof(Node));   //ͷ����ʼ��
    Node *p = head;  //����pΪͷ���
    head->next = NULL; 
    for(int i=0; i<len; i++)  //�������е�����д������
    {
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = a[i];
        p->next = n;
        p = n;
    }
    p->next = NULL;
    return head;
}

void print(List a) //��ӡ����
{
    if(!a) return;
    Node *p = a->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

void main()
{
    int a[] = {1, 2, 3, 4};  //��������a,b�е�����
    int b[] = {0, 1, 9};
	
    List la = getList(a, 4);  //��ʼ������
    List lb = getList(b, 3);
	List lc = NULL;

	printf("����La�е����ݣ�\n");
    print(la);
	printf("����Lb�е����ݣ�\n");
    print(lb);
    Merge(la, lb, lc);
	printf("����ϲ�������ݣ�\n");
	print(lc);
	system("pause");
}