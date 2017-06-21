#include "ded.h"
//��������
status  make(int *q,int l)
{
	int temp;
	int length;
	int i;
	length = l;
	for (i = 0; i <length; i++)
	{
		do
		{
			temp = rand() % 100 + 1;
		} while (temp <= 0);
		q[i] = temp;
	}
	return length;
}
//��ӡ���������������
void travel_(int *q, int l)
{
	for (int i = 0; i < l; i++)
	{
		printf("%d   ", q[i]);
	}
	printf("\n");
}
//����һ��δ�������ݵĿչ�ϣ��
status InitHashTable(HashTable *H)
{
	int i;
	(*H).count = 0; // ��ǰԪ�ظ���Ϊ0
	(*H).sizeindex = hashsize[hashsize_count]; // ��ʼ�洢����Ϊhashsize[0]
	m = (*H).sizeindex;
	H->elem = (ElemType*)malloc(m * sizeof(ElemType));
	if (!(*H).elem)
		exit(0);//return 0; // �洢����ʧ��
	for (i = 0; i < (*H).sizeindex; i++)
	{
	(*H).elem[i].key =-1; // δ���¼�ı�־
	(*H).elem[i].val = 0;
	}
	hashsize_count++;
	return 1;
}
//���в������
status InsertHash(HashTable *h, KeyType e, ValueType v)
{
	int c = 0;//���ڼ�����ͻ����
	int   p;//���ڷ��ز����λ��
	if (SearchHash(*h, e, v, &p, &c))
	{
		return DUPLICATE;//������и�Ԫ��  ����
	}
	else if (c < h->sizeindex / 2)//��ͻ�����ﵽ��������� c��ֵ�ɵ�
	{
		(*h).elem[p].val = v;
		(*h).elem[p].key = e;
		++(*h).count;
		return SUCCESS;//����ɹ�
	}
	else
	{//�����ϣ�����С
		printf("��ϣ������С  �ؽ���\n");
		RecreateHashTable(h);
		return UNSUCCESS;
	}
}
status SearchHash(HashTable  h, KeyType e, ValueType v, int* p, int *c)
{//������ҳɹ� pΪ���ڵ��±�  ����pΪ�������λ��
	*p = hash_(e, h.sizeindex);//�����±�
	while (h.elem[*p].key != -1 && v != h.elem[*p].val)
	{
		(*c)++;
		if ((*c) < h.sizeindex)
		{//�����ͻ�������ܼ�������
           collision(p, *c,e,h.sizeindex);
		}  
		else
		{
			break;
		}
	}
	if (v == h.elem[*p].val)
		return SUCCESS;
	else
		return UNSUCCESS;
}
int  hash_(KeyType e,int l)
{//��������������򵥵Ĺ�ϣ��
	int i = e%l;
	return i;
}
void collision(int *p,int c, KeyType k,int l)
{
	*p = (k + c) % l;//����̽����ɢ�У�di = 1,2,3,...,m-1 
}
//��ӡ��ϣ��
void TraverHash(HashTable  h)
{
	for (int i = 0; i < h.sizeindex; i++)
	{
		printf("{[%d] : ",i);
		printf("%d->%d}  ",h.elem[i].key, h.elem[i].val);
	}
	printf("\n");
}
//�ؽ���ϣ��
status RecreateHashTable(HashTable *H)
{
	int i, count = (*H).sizeindex;//H��ԭ�м�¼����  
	ElemType *p, *elem = (ElemType *)malloc(count * sizeof(ElemType));//��̬���ɴ�Ź�ϣ��Hԭ�����ݵĿռ� 
	p = elem;
	for (i = 0; i < (*H).sizeindex; ++i)
	{//��ԭ�е����м�¼�����浽elem��  	
			//*p++ = (*H).elem[i];//����¼���δ���elem  
			p[i].key = (*H).elem[i].key;
			p[i].val = (*H).elem[i].val;
	}
	(*H).count = 0;//��ԭ�м�¼����Ϊ0��Ϊ�������InserHash��׼��  
	(*H).sizeindex = hashsize[hashsize_count];
	(*H).elem = (ElemType *)realloc((*H).elem, (*H).sizeindex * sizeof(ElemType));//���µĴ洢�����������ɿչ�ϣ��H  
	for (i = 0; i <(*H).sizeindex; ++i)
	{//��ʼ���µĹ�ϣ��  
		(*H).elem[i].key = -1;//δ���¼  
		(*H).elem[i].val = 0;
	}
	for (i=0;i<count;i++)
	{//��ԭ���еļ�¼���´洢���µĹ�ϣ����
		if (p[i].key != -1)
		{
	      InsertHash(H, p[i].key, p[i].val);
		}
	}
	p = NULL;
	free(elem);//�ͷ�elem�Ĵ洢�ռ�  
	hashsize_count++;//���ӱ��±� Ϊ��һ���ؽ���׼��
	return 1;
}
int main()
{
	srand(time(0));
	int  list[init_num];
	int list_val[init_num];
	int search_list[search_num];
	int search_list_val[search_num] ;
	int search_list_length= search_num;
	int i;
	make(list, hashsize[0]-2);//������Ҫ��ӡ������ �����س�
	/*travel_(list, hashsize[0] - 2);*///��ӡ���������������
	make(list_val, hashsize[0] - 2);//������Ҫ��ӡ������ �����س���
	//travel_(list_val, hashsize[0] - 2);
    make(search_list, search_list_length/2);
	//travel_(search_list, search_list_length / 2);
	make(search_list_val, search_list_length / 2);
	//travel_(search_list_val, search_list_length / 2);
	for (i = search_list_length / 2; i < search_list_length; i++)
	{
		search_list[i] = list[i];
		search_list_val[i] = list_val[i];
	}
	/*travel_(search_list, search_list_length);
	travel_(search_list_val, search_list_length);*/
	HashTable H;
	if (InitHashTable(&H)==0)
	{
		printf("��ʼ��ʧ��");
		exit(0);
	}
	for (i=0; i < hashsize[0] - 2; i++)
	{
		printf("���� %d  �ؼ���Ϊ%d\n", list_val[i], list[i]);
		InsertHash(&H, list[i], list_val[i]);
		if (UNSUCCESS == InsertHash(&H, list[i], list_val[i]))
		{//���벻�ɹ�  
			InsertHash(&H, list[i], list_val[i]);
		}
	}
	printf("�״������Ĺ�ϣ��\n");
	TraverHash(H);
	for (i = 0; i < search_list_length; i++)
	{
		int p;
		int c=0;
		printf("���� %d    �ؼ���%d ", search_list_val[i], search_list[i]);
		if (SearchHash(H, search_list[i], search_list_val[i], &p, &c))
		{
			if (c != 0)
			{
				printf("        ������ͻ�Ĺؼ����� %d", search_list[i]);
				printf("      ������ͻ�Ĵ�����%d", c);
			}
			printf("    ���ҳɹ�,λ��%d       \n",p);
		}
		else
		{
			if (c != 0)
			{
				printf("        ������ͻ�Ĺؼ����� %d", search_list[i]);
				printf("     ������ͻ�Ĵ�����%d", c);
			}
			printf("    ����ʧ��\n");
		}
	}
   printf("�ؽ���ϣ��\n");
   RecreateHashTable(&H);
   TraverHash(H);
   free(H.elem);
   return 0;
}





