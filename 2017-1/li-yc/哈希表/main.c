#include "Hashtable.h"

int main() {
	Hashtable H;
	int arr[ArrayLenth][2];
	int i;

	srand(time(0));

	//创建哈希表
	H = CreatHash(HashLength);
	CreatArray(arr);

	//初始化哈希表
	for (i = 0; i < ArrayLenth; ++i) {
		Insert(H, arr[i][0], arr[i][1]);
	}
	printf("哈希表建立完毕\n");
	TraverseHash(H);
	
	//关键字查找
	for (i = 0; i < HashLength / 2; ++i) {
		Find(H, arr[rand() % ArrayLenth][0]);
	}
	for (i = 0; i < HashLength / 2; ++i) {
		Find(H, rand() % 100 + 1);
	}

	//重建哈希表
	RebulidHash(&H);
	TraverseHash(H);

	return 0;
}