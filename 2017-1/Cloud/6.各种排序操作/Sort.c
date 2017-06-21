#include "Sort.h"

/* 打印数组 */
Status  PrintArray(ElemeyType *a, int l, int move_count, int compare_count) {
	int i;
	for (i = 0; i < l; i++) {
		printf("%d ", a[i + 1]);
	}
	if (a[0] == 1)
		printf("\n该算法执行的 总比较次数为：%d 总移动记录次数为:%d 二者次数之和为:%d\n",
			compare_count, move_count, compare_count + move_count);
	else
		printf("\n");
	return OK;
}

/* 直接插入排序 */
Status InsSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	int i, j;
	for (i = 2; i <= length; i++) {
		*r = *(r + i);   /* 将待插入记录存放到临时变量中 */
		j = i - 1;     /* 最近一次排序结束的边界位置 */
		(*compare_count)++;
		while (r[0] < r[j]) { 	/* 寻找插入位置 */
			(*move_count)++;
			*(r + j + 1) = *(r + j);/* 从小到大排序，大元素右移 */
			j = j - 1; /* 待插入元素与已排序区下一个（左移一位）元素继续进行比较 */
		}
		*(r + j + 1) = r[0]; /* 将待插入记录插入到已排序的序列中 */
	}
	*r = 1;
	return OK;
}

/* 一趟希尔插入排序 */
void ShellInsert(ElemeyType *r, int length, int delta, int *move_count, int *compare_count) {
	//length为数组的长度, delta 为增量
	int i, j;
	for (i = 1 + delta; i <= length; i++) { /* 1+delta为第一个子序列的第二个元素的下标 */
		(*compare_count)++;
		if (r[i] < r[i - delta]) {
			*r = r[i];     /* 备份r[i] (不做监视哨) */
			for (j = i - delta; j > 0 && r[0] < r[j]; j -= delta) {
				(*compare_count)++;
				*(r + j + delta) = r[j];
				(*move_count)++;
			}
			*(r + j + delta) = r[0];
		}
	}
}

/* 希尔排序 */
void ShellSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	//length为数组的长度
	int d = length / 2;
	while (d >= 1) {
		ShellInsert(r, length, d, move_count, compare_count);
		d = d / 2;
	}
	*r = 1;
}

/* 冒泡排序 */
void BubbleSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	//length为数组的长度
	int n = length, i, j, x;
	bool change = TRUE;
	for (i = 1; i <= n - 1 && change; ++i) {
		change = FALSE;
		for (j = 1; j <= n - i; ++j) {
			(*compare_count)++;
			if (r[j] > r[j + 1]) {
				(*move_count)++;
				x = r[j];
				*(r + j) = r[j + 1];
				*(r + j + 1) = x;
				change = TRUE;
			}
		}
	}
	*r = 1;
}

/* 快速排序 */
void QKSort(ElemeyType *r, int low, int high, int *move_count, int *compare_count) {
	int pivot;
	if (low < high) {
		pivot = QKPass(r, low, high, move_count, compare_count);
		QKSort(r, low, pivot - 1, move_count, compare_count);
		QKSort(r, pivot + 1, high, move_count, compare_count);
	}
	*r = 1;
}

/* 一趟快速排序 */
int QKPass(ElemeyType *r, int left, int right, int *move_count, int *compare_count) {
	//对记录数组r 中的r[left]至r[right]部分进行一趟排序，并得到基准的位置，使得排序后的结果满足其之后（前）
	//的记录的关键字均不小于（大于）于基准记录
	int x, low, high;
	x = r[left];             /* 选择基准记录*/
	low = left;
	high = right;
	while (low < high) {
		while (low < high && r[high] >= x) { /* high从右到左找小于x的记录 */
			(*compare_count)++;
			high--;
		}
		*(r + low) = r[high]; /* 找到小于x.key的记录，则进行交换 */
		(*move_count)++;
		while (low < high && r[low] < x) { /* low从左到右找不小于x的记录 */
			*(compare_count)++;
			low++;
		}
		*(r + high) = r[low]; /* 找到不小于x的记录，则交换*/
		(*move_count)++;
	}

	*(r + low) = x;  /* 将基准记录保存到low=high的位置 */
	return low;  /*返回基准记录的位置*/
}

/* 选择排序 */
void SelectSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	//length为数组的长度
	int n = length, i, k, j, x;
	for (i = 1; i <= n - 1; ++i) {
		k = i;
		for (j = i + 1; j <= n; ++j) {
			(*compare_count)++;
			if (r[j] < r[k]) {
				k = j;
			}
		}
		if (k != i) {
			(*move_count)++;
			x = r[i];
			*(r + i) = r[k];
			*(r + k) = x;
		}
	}
}