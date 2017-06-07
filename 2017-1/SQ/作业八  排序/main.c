#include "Sort.h"

int main()
{
	int compare, move, length;
	RecordType *test; // 待开辟的数组

	srand(time(NULL)); // 随机种子

	if (!(length = CreateTest(&test))) {
		return 1; // 开辟空间失败
	}

	compare = move = 0; // 初始化比较次数、移动次数
	Sort(&test, length, &compare, &move); // 调用各种排序方法

	return 0;
}