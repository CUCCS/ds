#include "tree.h"
int main() {
	/*����һ��������*/
	char* rootLR = "ABDG###EH##I#K##C#F##";
	/*��������������*/
	char* _pre =  "ABDFCE";
	char* _in =  "DFBAEC";

	Tree t1,t2;
	/*����һ*/
	t1 = newBinaryTree(rootLR);
	TraverseTree(t1, all);
	/*������*/
	t2 = newBinaryTree2(_pre, _in);
	TraverseTree(t2, all);
	return 0;
}