
#include <time.h>
#include "OpenHash.h"

#define CAPACITY 10
#define SIZE 6
ElemType* genTestInputs(int size) {
	ElemType* arr = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; ++i) {
		arr[i] = newElemType(rand() % 100, rand() % 100);
	}
	return arr;
}
int main() {
	srand(time(0));
	printf("【OpenHash】\n");
	OpenHash oh = newOpenHash(CAPACITY);
	/*生成测试用例*/
	ElemType* testInputs = genTestInputs(SIZE);
	/*建表*/
	for (int i = 0; i < SIZE; ++i) {
		Insert(oh,testInputs[i]);
	}
	ShowOpenHash(oh);
	/*查找*/
	for (int i = 0; i < SIZE/2; ++i) {
		Find(oh, testInputs[rand()%SIZE].key);
	}
	for (int i = 0; i < SIZE/2; ++i) {
		Find(oh,rand()%100);
	}
	/*扩建*/
	oh = Rebuild(oh);
	ShowOpenHash(oh);

}