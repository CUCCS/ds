#include "tree.h"
Tree t1, t2, t3, t4;
void testNewBinaryTree() {
	/*����һ��������*/
	char* rootLR = "ABDG###EH##I#K##C#F##";
	/*��������������*/
	char* _pre = "ABDFCE";
	char* _in = "DFBAEC";
	/*����һ*/
	t1 = newBinaryTree(rootLR);
	Show(t1, all);
	/*������*/
	t2 = newBinaryTree2(_pre, _in);
	Show(t2, all);
	debug_print("\n");
}
void testCalculateDepthAndWidth() {
	/*���������������*/
	int depth, width;
	CalculateDepthAndWidth(t1, &depth, &width);
	CalculateDepthAndWidth(t2, &depth, &width);
	debug_print("\n");
}
void testCountLeavesAndBranches() {
	/*ͳ�ƶ�������Ҷ���Ҷ�ڵ�ĸ���*/
	int leaf, branch;
	CountLeaves(t1, &leaf);
	CountBranches(t1, &branch);
	CountLeaves(t2, &leaf);
	CountBranches(t2, &branch);
	debug_print("\n");
}
void testIsCompleteBinaryTree() {
	/*�ж��Ƿ�Ϊ��ȫ������*/
	t3 = newBinaryTree("ABD##E##C##");/*��ȫ������*/
	t4 = newBinaryTree("A#C##");/*����ȫ������*/
	debug_print("��0x%p%s����ȫ������ \n", t1, isCompleteBinaryTree(t1) ? "" : "��");
	debug_print("��0x%p%s����ȫ������ \n", t2, isCompleteBinaryTree(t2) ? "" : "��");
	debug_print("��0x%p%s����ȫ������ \n", t3, isCompleteBinaryTree(t3) ? "" : "��");
	debug_print("��0x%p%s����ȫ������ \n", t4, isCompleteBinaryTree(t4) ? "" : "��");
}
int main() {
	testNewBinaryTree();
	testCalculateDepthAndWidth();
	testCountLeavesAndBranches();
	testIsCompleteBinaryTree();
	return 0;
}