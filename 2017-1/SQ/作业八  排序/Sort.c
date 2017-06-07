#include "Sort.h"

/* 对记录数组r做直接插入排序，length为数组的长度 */
Status InsSort(RecordType **r, int length, int *compare, int *move) {
	int i, j;
	RecordType temp;
	if (Empty(r)) {
		return ERROR;
	}
	for (i = 1; i < length; i++) {
		temp = (*r)[i];   /* 将待插入记录存放到临时变量中 */
		(*move)++;
		j = i - 1;     /* 最近一次排序结束的边界位置 */
		while (++(*compare) && temp.key < (*r)[j].key) {   /* 寻找插入位置 */
			(*r)[j + 1] = (*r)[j]; /* 从小到大排序，大元素右移 */
			(*move)++;
			j = j - 1; /* 待插入元素与已排序区下一个（左移一位）元素继续进行比较 */
		}
		(*r)[j + 1] = temp; /* 将待插入记录插入到已排序的序列中 */
		(*move)++;
	}
	return OK;
}

/* 对记录数组r做一趟希尔插入排序，length为数组的长度, delta 为增量 */
Status ShellInsert(RecordType **r, int length, int delta, int *compare, int *move) {
	int i, j;
	RecordType temp;
	if (Empty(r)) {
		return ERROR;
	}
	for (i = delta; i < length; i++) { /* 1+delta为第一个子序列的第二个元素的下标 */
		if ((*r)[i].key < (*r)[i - delta].key && ++(*compare)) {
			temp = (*r)[i]; /* 备份r[i] (不做监视哨) */
			(*move)++;
			for (j = i - delta; (j >= i % delta) && temp.key < (*r)[j].key; j -= delta) {
				(*r)[j + delta] = (*r)[j];
				(*move)++;
			}
			(*r)[j + delta] = temp;
			(*move)++;
		}
	}
	return OK;
}

/* 对记录数组r做希尔排序， length为数组的长度*/
Status ShellSort(RecordType **r, int length, int *compare, int *move) {
	int d;
	d = length / 2;
	if (Empty(r)) {
		return ERROR;
	}
	while (d >= 1) {
		ShellInsert(r, length, d, compare, move);
		d = d / 2;
	}
	return OK;
}

/* 对记录数组r做冒泡排序，length为数组的长度 */
Status BubbleSort(RecordType **r, int length, int *compare, int *move) {
	int i, j, n;
	RecordType temp;
	bool change;
	n = length;
	change = TRUE;
	if (Empty(r)) {
		return ERROR;
	}
	for (i = 0; i < n && change; ++i) {
		change = FALSE;
		for (j = 0; j < n - i - 1; ++j) {
			if ((*r)[j].key > (*r)[j + 1].key && ++(*compare)) {
				temp = (*r)[j];
				(*r)[j] = (*r)[j + 1];
				(*r)[j + 1] = temp;
				*move += 3;
				change = TRUE;
			}
		}
		if (!change) {
			break;
		}
	}
	return OK;
}

/* 对记录数组r[low...high]用快速排序算法进行排序 */
Status QKSort(RecordType *r, int low, int high, int *compare, int *move) {
	int pivot;
	if (low < high) {
		pivot = QKPass(r, low, high, compare, move);
		QKSort(r, low, pivot - 1, compare, move);
		QKSort(r, pivot + 1, high, compare, move);
	}
	return OK;
}

/* 对记录数组r 中的r[left]至r[right]部分进行一趟排序，并得到基准的位置，使得排序后的结果满足其之后（前）的记录的关键字均不小于（大于）于基准记录 */
int QKPass(RecordType **r, int left, int right, int *compare, int *move) {
	int low, high;
	RecordType temp;
	temp = (*r)[left];             /* 选择基准记录*/
	(*move)++;
	low = left;
	high = right;
	while (low < high) {
		while (low < high && (*r)[high].key >= temp.key && ++(*compare)) { /* high从右到左找小于x.key的记录 */
			high--;
		}
		(*r)[low] = (*r)[high]; /* 找到小于x.key的记录，则进行交换 */
		(*move)++;
		while (low < high && (*r)[low].key <= temp.key && ++(*compare)) { /* low从左到右找不小于x.key的记录 */
			low++;
		}
		(*r)[high] = (*r)[low]; /* 找到不小于x.key的记录，则交换*/
		(*move)++;
	}
	(*r)[low] = temp;  /* 将基准记录保存到low=high的位置 */
	*move++;
	return low;  /*返回基准记录的位置*/
}

/* 对记录数组r做简单选择排序，length为数组的长度 */
Status SelectSort(RecordType **r, int length, int *compare, int *move) {
	int i, j, k, n;
	RecordType temp;
	n = length;
	for (i = 0; i < n; ++i) {
		k = i;
		for (j = i + 1; j < n; ++j) {
			if ((*r)[j].key < (*r)[k].key && ++(*compare)) {
				temp = (*r)[i];
				(*r)[i] = (*r)[j];
				(*r)[j] = temp;
				*move += 3;
			}
		}
	}
	return OK;
}

/* 已知r[s..m]中记录的关键字除了r[s].key之外均满足堆的定义，本函数调整r[s]的关键字，使r[s..m]成为一个大顶堆(对其中记录的关键字而言) */
Status HeapAdjust(RecordType **r, int s, int m, int *compare, int *move) {
	RecordType rc;
	int j;
	if (Empty(r)) {
		return ERROR;
	}
	for (; 2 * s + 1 < m; s = j) {
		j = 2 * s + 1;
		if (j < m - 1 && (*r)[j].key < (*r)[j + 1].key && ++(*compare)) {
			++j;
		}
		if ((*r)[s].key >= (*r)[j].key && ++(*compare)) {
			break;
		}
		rc = (*r)[s];
		(*r)[s] = (*r)[j];
		
		(*r)[j] = rc;
		(*move) += 3;
	}
	return OK;
}

/* 对记录数组r进行堆排序，length为数组的长度 */
Status HeapSort(RecordType **r, int length, int *compare, int *move) {
	int i;
	RecordType temp;
	if (Empty(r)) {
		return ERROR;
	}
	for (i = length / 2; i >= 0; --i) {
		HeapAdjust(r, i, length, compare, move);
	}
	for (i = length - 1; i > 0; --i) {
		temp = (*r)[0];
		(*r)[0] = (*r)[i];
		(*r)[i] = temp;
		(*move) += 3;
		HeapAdjust(r, 0, i, compare, move);
	}
}

/* 将有序的r[i..m]和r[m+1..n]归并为有序的r1[i..n]中 */
Status Merge(RecordType **r, RecordType **r1, int i, int m, int n, int *compare, int *move) {
	int j, k;
	int low, mid, high;
	low = i, mid = m, high = n;
	if (Empty(r)) {
		return ERROR;
	}
	for (j = mid + 1, k = low; low <= mid && j <= high; ++k) { // 将r中记录由小到大地并入r1
		if ((*r)[low].key <= (*r)[j].key && ++(*compare)) {
			(*r1)[k] = (*r)[low++];
			(*move)++;
		}
		else {
			(*r1)[k] = (*r)[j++];
			(*move)++;
		}
	}
	while (low <= mid) { // 将剩余的r[i..m]复制到r1
		(*r1)[k++] = (*r)[low++];
		(*move)++;
	}
	while (j <= high) { // 将剩余的r[j..n]复制到r1
		(*r1)[k++] = (*r)[j++];
		(*move)++;
	}
	return OK;
}

/* 将有序的r[s..t]归并排序为r1[s..t] */
Status MSort(RecordType **r, RecordType **r1, int s, int t, int *compare, int *move) {
	int low, mid, high;
	low = s, high = t;
	RecordType *temp;
	if (Empty(r)) {
		return ERROR;
	}
	if (low == high) {
		(*r1)[low] = (*r)[low];
		(*move)++;
	}
	else {
		mid = (low + high) / 2; // 将r[low..high]平分为r1[low..mid]和r1[mid+1,high]
		temp = (RecordType *)malloc(sizeof(RecordType) * (high + 1)); // 辅助空间， 测试发现大小要为high+1，否则溢出
		MSort(r, &temp, low, mid, compare, move); // 递归地将r[low..mid]归并为有序的temp[low,mid]
		MSort(r, &temp, mid + 1, high, compare, move); // 递归地将r[mid+1..high]归并为有序的temp[mid+1,high]
		Merge(&temp, r1, low, mid, high, compare, move); // 将temp[low..mid]和temp[mid+1,high]归并到r1[low,high]
		free(temp);
	}
	return OK;
}

/* 对记录数组r做归并排序，length为数组的长度 */
Status MergeSort(RecordType **r, int length, int *compare, int *move) {
	if (!MSort(r, r, 0, length - 1, compare, move)) {
		return OK;
	}
	return ERROR;
}

/* 判断记录数组r是否为空 */
bool Empty(RecordType **r) {
	if (!r || !(*r)) {
		return TRUE;
	}
	return FALSE;
}

/* 为记录数组r开辟空间，并用随机数填充数组，返回数组大小 */
int CreateTest(RecordType **r) {
	int n;
	n = (int)rand() % 9 + 10; // 生成数组大小，范围在10~18之间
	*r = (RecordType *)malloc(sizeof(RecordType) * n);
	if (Empty(r)) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		(*r)[i].key = (int)rand() % 100 + 1; // 产生1~100的随机数
	}
	return n;
}

/* 输出记录数组r中的元素 */
Status PrintCase(RecordType **r, int n) {
	if (Empty(r)) {
		return ERROR;
	}
	for (int i = 0; i < n; i++) {
		printf("%4d", (*r)[i]);
	}
	printf("\n");
	return OK;
}

/* 输出记录数组r经过排序的总比较次数、总移动次数以及两者之和 */
Status PrintNum(int *compare, int *move) {
	// 输出比较次数、交换次数、总次数
	if (*compare == 0 || *move == 0) {
		return ERROR;
	}
	printf("Compare times:%d\n", *compare);
	printf("Move times:%d\n", *move);
	printf("Total times:%d\n", *compare + *move);
	return OK;
}

/* 输出记录数组r中的元素，以及经过排序的总比较次数、总移动次数、两者之和 */
Status Print(RecordType **r, int n, int *compare, int *move) {
	if (PrintCase(r, n) && PrintNum(compare, move)) {
		printf("\n");
		return OK;
	}
	return ERROR;
}

/* 将记录数组p还原为原始的记录数组r，并将总比较次数、总移动次数清零 */
Status Fresh(RecordType **r, int n, RecordType **p, int *compare, int *move) {
	if (Empty(r)) {
		return ERROR;
	}
	*p = (RecordType *)malloc(sizeof(RecordType) * n);
	*compare = *move = 0;
	for (int i = 0; i < n; i++) {
		(*p)[i] = (*r)[i];
	}
	return OK;
}

/* 对记录数组r使用各种排序方法，并将结果输出 */
Status Sort(RecordType **r, int n, int *compare, int *move) {
	RecordType *temp; // 暂存数组

	printf("==================== InsertSort ====================\n");
	Fresh(r, n, &temp, compare, move);
	printf("Original order:"); PrintCase(&temp, n);
	InsSort(&temp, n, compare, move);
	printf("Sorted order:"); Print(&temp, n, compare, move);

	printf("==================== ShellSort ====================\n");
	free(temp); Fresh(r, n, &temp, compare, move);
	printf("Original order:"); PrintCase(&temp, n);
	ShellSort(&temp, n, compare, move);
	printf("Sorted order:"); Print(&temp, n, compare, move);

	printf("==================== BubbleSort ====================\n");
	free(temp); Fresh(r, n, &temp, compare, move);
	printf("Original order:"); PrintCase(&temp, n);
	BubbleSort(&temp, n, compare, move);
	printf("Sorted order:"); Print(&temp, n, compare, move);

	printf("==================== QuickSort ====================\n");
	free(temp); Fresh(r, n, &temp, compare, move);
	printf("Original order:"); PrintCase(&temp, n);
	QKSort(&temp, 0, n - 1, compare, move);
	printf("Sorted order:"); Print(&temp, n, compare, move);

	printf("==================== SelectSort ====================\n");
	free(temp); Fresh(r, n, &temp, compare, move);
	printf("Original order:"); PrintCase(&temp, n);
	SelectSort(&temp, n, compare, move);
	printf("Sorted order:"); Print(&temp, n, compare, move);

	printf("==================== HeapSort ====================\n");
	free(temp); Fresh(r, n, &temp, compare, move);
	printf("Original order:"); PrintCase(&temp, n);
	HeapSort(&temp, n, compare, move);
	printf("Sorted order:"); Print(&temp, n, compare, move);

	printf("==================== MergeSort ====================\n");
	RecordType *r_temp;
	r_temp = (RecordType *)malloc(sizeof(RecordType) * n);
	free(temp); Fresh(r, n, &temp, compare, move);
	printf("Original order:"); PrintCase(&temp, n);
	MergeSort(&temp, n, compare, move);
	printf("Sorted order:"); Print(&temp, n, compare, move);
}