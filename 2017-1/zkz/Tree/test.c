#include "tree.h"
Tree t1, t2, t3, t4;
void testNewBinaryTree() {
	/*方法一测试用例*/
	char* rootLR = "ABDG###EH##I#K##C#F##";
	/*方法二测试用例*/
	char* _pre = "ABDFCE";
	char* _in = "DFBAEC";
	/*方法一*/
	t1 = newBinaryTree(rootLR);
	Show(t1, all);
	/*方法二*/
	t2 = newBinaryTree2(_pre, _in);
	Show(t2, all);
	debug_print("\n");
}
void testCalculateDepthAndWidth() {
	/*计算树的深度与宽度*/
	int depth, width;
	CalculateDepthAndWidth(t1, &depth, &width);
	CalculateDepthAndWidth(t2, &depth, &width);
	debug_print("\n");
}
void testCountLeavesAndBranches() {
	/*统计二叉树中叶与非叶节点的个数*/
	int leaf, branch;
	CountLeaves(t1, &leaf);
	CountBranches(t1, &branch);
	CountLeaves(t2, &leaf);
	CountBranches(t2, &branch);
	debug_print("\n");
}
void testIsCompleteBinaryTree() {
	/*判断是否为完全二叉树*/
	t3 = newBinaryTree("ABD##E##C##");/*完全二叉树*/
	t4 = newBinaryTree("A#C##");/*非完全二叉树*/
	debug_print("树0x%p%s是完全二叉树 \n", t1, isCompleteBinaryTree(t1) ? "" : "不");
	debug_print("树0x%p%s是完全二叉树 \n", t2, isCompleteBinaryTree(t2) ? "" : "不");
	debug_print("树0x%p%s是完全二叉树 \n", t3, isCompleteBinaryTree(t3) ? "" : "不");
	debug_print("树0x%p%s是完全二叉树 \n", t4, isCompleteBinaryTree(t4) ? "" : "不");
}
int main() {
	testNewBinaryTree();
	testCalculateDepthAndWidth();
	testCountLeavesAndBranches();
	testIsCompleteBinaryTree();
	return 0;
}