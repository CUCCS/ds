#include "tree.h"
int main() {
	/*方法一测试用例*/
	char* rootLR = "ABDG###EH##I#K##C#F##";
	/*方法二测试用例*/
	char* _pre =  "ABDFCE";
	char* _in =  "DFBAEC";

	Tree t1,t2;
	/*方法一*/
	t1 = newBinaryTree(rootLR);
	TraverseTree(t1, all);
	/*方法二*/
	t2 = newBinaryTree2(_pre, _in);
	TraverseTree(t2, all);
	return 0;
}