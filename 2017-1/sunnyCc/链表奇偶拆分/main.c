//1.��������ֽ�Ϊ��������ͷ����ѭ������,
//2.������ѭ������ĳ��ȷֱ����ڸ���ͷ�����������С�
//3.���Ա������Ϊ������Ԫ�طֽ⵽��һ��ѭ��������, ���Ϊż����Ԫ�طֽ⵽�ڶ���ѭ��������
//4.Ҫ�������ٵ�ʱ������ٵĿռ�

//ʹ��ѭ����������ʾlist1��list2ʹ����Ѱ�����ͷβ�����ֱ�Ӳ��룬������ʱ�临�Ӷȵ�O(1)
//���ҷֽ����ֻ�漰һ��ѭ���������˿ռ临�Ӷȵ�O(n)
#include "split.h"
int main()
{
LinkList list, list1, list2;
int n;
srand((unsigned int)time(NULL));
n =  rand() % 10+10 ;//�������list������
CreateList(&list, n);//��������list��������ɲ������ݽ�������
list1 = (LNode *)malloc(sizeof(LNode));
list2 = (LNode *)malloc(sizeof(LNode));

Split(list, list1, list2);//��������в��

printf("����1:\nԪ�ظ���Ϊ%d\n", list1->data);
Traverse(list1);
printf("����2:\nԪ�ظ���Ϊ%d\n", list2->data);
Traverse(list2);
return 0;
}