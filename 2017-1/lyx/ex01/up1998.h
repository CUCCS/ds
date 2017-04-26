#include<stdio.h> //头文件 
#include<stdlib.h> //头文件

typedef int ElemType; //自定义一个类型名ElemType

typedef struct LNode{ 
   ElemType data; //int 型数据data
   struct LNode* next; 
}LNode,*LinkList; //自定义一个类型名结构体 
//struct Lnode是一个整体，表明Lnode是一个结构体类型，把struct Lnode重定义为Lnode，以后就可以不用写struct了，直接使用Lnode定义结构体变量或指针等等。

void scan(ElemType *p)//自定义函数 输入
{ 
   scanf("%d",p);//输入list 
}  
void print(const ElemType n)//自定义函数 输出
{ 
   printf("%2d ",n); //两个字节大小 输出list
} 

void CreateList_L(LinkList , int , void(*)(ElemType*)); 
//算法2.11	新建单链表 

void TraverseList_L(const LinkList,void(*)(ElemType)); 
//依次对Linklist的每个数据元素调用函数void(*)(ElemType)
void MergeList_L(LinkList, LinkList, LinkList); 
//算法2.12	归并两个单链表  

int test1_iter(int k)//创建test1
{ 
   static int b = 20; 
	return b -= k; 
} 
void test1(ElemType *p)//初始化test1，用随机数
{ 
	*p = test1_iter(rand() % 5+1); 
} 
 
int test2_iter(int k)//创建test2
{ 
	static int b = 20; 
	return b -= k;  
} 
void test2(ElemType *p)//初始化test2，用随机数
{ 
	*p = test2_iter(rand() % 5+1); 
}
//以上4个函数用于产生有序测试数据 


 
void CreateList_L(LinkList L, int n, void(*func)(ElemType*))//新建链表
{
	LNode* p; //指针
	L->next = NULL; //链表中的指向下一个节点。->是表示指向结构体中的成员
	for (int i = 0; i < n; ++i)
	{ 
		p = (LinkList)malloc(sizeof(LNode));//malloc() 返回的类型是void * 型, 不相同的类型不能进行赋值运算, 所以要进行强制类型转换
        func(&p->data); 
	 	p->next = L->next;  
		L->next = p; //生成一个新的节点，并将其插入到数据链中
     } 
};//CraeteList_L 
//新建长度为n的单链表L，对其中每个数据使用func函数来创建 

 
void TraverseList_L(const LinkList L,void(*func)(ElemType))//依次对Linklist的每个数据元素调用函数void(*)(ElemType)
{
	LNode *p = L->next; 
	while (p)//成功时
	{ 
		func(p->data); //执行func操作
		p = p->next;  //指针指向下一个数据元素
	} 
} 
//遍历单链表L，对其中每个数据执行func函数 


void MergerList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{ 	//已知单链线性表La和Lb的元素按值非递减排列 	
	//归并La和Lb得到新的单链线性表Lc，Lc的元素也按照值非递减排列 	
/*	pa = La->next; 
	pb = Lb->next; 
	Lc = pc = La;*/	
	LNode *pa = La->next, *pb = Lb->next, *pc;  //pa指向La表中当前比较插入的结点 pb指向Lb表中当前比较插入的结点
	(*Lc) = pc = La;// 用La的头结点作为Lc的头结点，pc始终指向Lc当前最后一个结点 	
	while(pa && pb)//LaLb为非空表
	{ 		if(pa->data <= pb->data)//pa指的元素小于pb指的元素
	         {pc->next = pa;//pc变成pa所指的元素的下一个 			
	          pc = pa;//pc变成pa所指的元素 	
			  // 等价于 pc = pc->next 	
			  pa = pa->next;//pa变成pa所指的元素的下一个 		
	          } 		
	       else{ pc->next = pb;//pa指的元素大于pb指的元素
		         pc = pb; //pc变成pb所指的元素 	
				 // 等价于 pc = pc->next 
				 pb = pb->next; //pb变成pb所指的元素的下一个
		   }
	 } 	
	pc->next = pa?pa:pb;	
	// 插入剩余段，?：是三目运算符 	
	free(Lb);		// 释放Lb的头结点 
}// MergeList L


