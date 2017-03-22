#include<stdio.h> //ͷ�ļ� 
#include<stdlib.h> //ͷ�ļ�

typedef int ElemType; //�Զ���һ��������ElemType

typedef struct LNode{ 
   ElemType data; //int ������data
   struct LNode* next; 
}LNode,*LinkList; //�Զ���һ���������ṹ�� 
//struct Lnode��һ�����壬����Lnode��һ���ṹ�����ͣ���struct Lnode�ض���ΪLnode���Ժ�Ϳ��Բ���дstruct�ˣ�ֱ��ʹ��Lnode����ṹ�������ָ��ȵȡ�

void scan(ElemType *p)//�Զ��庯�� ����
{ 
   scanf("%d",p);//����list 
}  
void print(const ElemType n)//�Զ��庯�� ���
{ 
   printf("%2d ",n); //�����ֽڴ�С ���list
} 

void CreateList_L(LinkList , int , void(*)(ElemType*)); 
//�㷨2.11	�½������� 

void TraverseList_L(const LinkList,void(*)(ElemType)); 
//���ζ�Linklist��ÿ������Ԫ�ص��ú���void(*)(ElemType)
void MergeList_L(LinkList, LinkList, LinkList); 
//�㷨2.12	�鲢����������  

int test1_iter(int k)//����test1
{ 
   static int b = 20; 
	return b -= k; 
} 
void test1(ElemType *p)//��ʼ��test1���������
{ 
	*p = test1_iter(rand() % 5+1); 
} 
 
int test2_iter(int k)//����test2
{ 
	static int b = 20; 
	return b -= k;  
} 
void test2(ElemType *p)//��ʼ��test2���������
{ 
	*p = test2_iter(rand() % 5+1); 
}
//����4���������ڲ�������������� 


 
void CreateList_L(LinkList L, int n, void(*func)(ElemType*))//�½�����
{
	LNode* p; //ָ��
	L->next = NULL; //�����е�ָ����һ���ڵ㡣->�Ǳ�ʾָ��ṹ���еĳ�Ա
	for (int i = 0; i < n; ++i)
	{ 
		p = (LinkList)malloc(sizeof(LNode));//malloc() ���ص�������void * ��, ����ͬ�����Ͳ��ܽ��и�ֵ����, ����Ҫ����ǿ������ת��
        func(&p->data); 
	 	p->next = L->next;  
		L->next = p; //����һ���µĽڵ㣬��������뵽��������
     } 
};//CraeteList_L 
//�½�����Ϊn�ĵ�����L��������ÿ������ʹ��func���������� 

 
void TraverseList_L(const LinkList L,void(*func)(ElemType))//���ζ�Linklist��ÿ������Ԫ�ص��ú���void(*)(ElemType)
{
	LNode *p = L->next; 
	while (p)//�ɹ�ʱ
	{ 
		func(p->data); //ִ��func����
		p = p->next;  //ָ��ָ����һ������Ԫ��
	} 
} 
//����������L��������ÿ������ִ��func���� 


void MergerList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{ 	//��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����� 	
	//�鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ����ֵ�ǵݼ����� 	
/*	pa = La->next; 
	pb = Lb->next; 
	Lc = pc = La;*/	
	LNode *pa = La->next, *pb = Lb->next, *pc;  //paָ��La���е�ǰ�Ƚϲ���Ľ�� pbָ��Lb���е�ǰ�Ƚϲ���Ľ��
	(*Lc) = pc = La;// ��La��ͷ�����ΪLc��ͷ��㣬pcʼ��ָ��Lc��ǰ���һ����� 	
	while(pa && pb)//LaLbΪ�ǿձ�
	{ 		if(pa->data <= pb->data)//paָ��Ԫ��С��pbָ��Ԫ��
	         {pc->next = pa;//pc���pa��ָ��Ԫ�ص���һ�� 			
	          pc = pa;//pc���pa��ָ��Ԫ�� 	
			  // �ȼ��� pc = pc->next 	
			  pa = pa->next;//pa���pa��ָ��Ԫ�ص���һ�� 		
	          } 		
	       else{ pc->next = pb;//paָ��Ԫ�ش���pbָ��Ԫ��
		         pc = pb; //pc���pb��ָ��Ԫ�� 	
				 // �ȼ��� pc = pc->next 
				 pb = pb->next; //pb���pb��ָ��Ԫ�ص���һ��
		   }
	 } 	
	pc->next = pa?pa:pb;	
	// ����ʣ��Σ�?������Ŀ����� 	
	free(Lb);		// �ͷ�Lb��ͷ��� 
}// MergeList L


