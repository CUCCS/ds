#include"Sort.h"
void Print(RecordType r[], int length)
{
	for (int i = 1; i <= length; i++)
	{
		printf("%d ", r[i]);
	}
	printf("\n");
}
void InsSort(RecordType r[], int length,int *CpNumber,int *MovNumber)
{
	*CpNumber = 0;//比较次数
	*MovNumber = 0;//移动次数
	int i, j;
	for ( i = 2; i <=length; i++) {
		r[0] = r[i]; /* 将待插入记录存放到临时变量中 */
		(*MovNumber)++;
		j = i - 1;     /* 最近一次排序结束的边界位置 */
		while ((++(*CpNumber))&&(r[0] < r[j])) {   /* 寻找插入位置 */
			r[j + 1] = r[j]; /* 从小到大排序，大元素右移 */
			(*MovNumber)++;
			j = j - 1; /* 待插入元素与已排序区下一个（左移一位）元素继续进行比较 */
		}
		r[j + 1] = r[0]; /* 将待插入记录插入到已排序的序列中 */
		(*MovNumber)++;
	}
	Print(r, length);
}
void ShellInsert(RecordType r[], int length, int delta,int *CpNumber, int *MovNumber) {
	int i,j;
	*CpNumber = 0;
	*MovNumber = 0;
	for (i = 1 + delta; i <= length; i++) { /* 1+delta为第一个子序列的第二个元素的下标 */
		if ((++(*CpNumber))&&(r[i] < r[i - delta])) {
			r[0] = r[i]; /* 备份r[i] (不做监视哨) */
			for (j = i - delta; j > 0 &&(++*(CpNumber))&& r[0] < r[j] ; j -= delta) {
				r[j + delta] = r[j];
				(*MovNumber)++;
			}
			r[j + delta] = r[0];
		}
	}
}

/* 对记录数组r做希尔排序， length为数组的长度*/
void ShellSort(RecordType r[], int length,int *CpNumber, int *MovNumber) {
	int d = length / 2;
	while (d >= 1) {
		ShellInsert(r, length, d,CpNumber,MovNumber);
		d = d / 2;
	}
	Print(r, length);
}

void Copy(RecordType a[], RecordType b[], int c)
{
	for (int i = 0; i <= c; i++)
	{
		a[i] = b[i];
	}
}

void BubbleSort(RecordType r[], int length,int *c,int *m) {
	*c = 0; *m = 0;
	int n = length,i,j,x;
	int change = 1;//TRUE
	for (i = 1; i <= n - 1 && change; ++i) {
		change = 0;//FALSE
		for (j = 1; j <= n - i; ++j) {
			if ((++(*c))&&r[j] > r[j + 1]) {
				x = r[j];
				r[j] = r[j + 1];
				r[j + 1] = x;
				(*m)++;
				change = 1;
			}
		}
	}
	Print(r, length);
}

int QKPass(RecordType r[], int left, int right, int *c, int *m) {
	int x = r[left];             /* 选择基准记录*/
	int low = left;
	int high = right;
	while (low < high) {
		while (low < high &&(++(*c))&& r[high] >= x) { /* high从右到左找小于x.key的记录 */
			high--;
		}
		r[low] = r[high]; /* 找到小于x.key的记录，则进行交换 */
		++(*m);
		while (low < high && (++(*c)) && r[low] < x) { /* low从左到右找不小于x.key的记录 */
			low++;
		}
		r[high] = r[low]; /* 找到不小于x.key的记录，则交换*/
		++(*m);
	}

	r[low] = x;  /* 将基准记录保存到low=high的位置 */
	++(*m);
	return low;  /*返回基准记录的位置*/
}

void QKSort(RecordType r[], int low, int high,int *c,int *m) {
	if (low < high) {
		int pivot = QKPass(r, low, high,c,m);
		QKSort(r, low, pivot - 1,c,m);
		QKSort(r, pivot + 1, high,c,m);
	}
}

void SelectSort(RecordType r[], int length, int *c, int *m)
{
	*c = 0; *m = 0;
	int n = length;
	int i,k,j;
	for (i = 1; i <= n-1; ++i) {
		k = i;
		for (j = i + 1; j <= n; ++j) {
			if ((++(*c))&&r[j] < r[k]) {
				k = j;
			}
		}

		if (k != i) {
			int x = r[i];
			r[i] = r[k];
			r[k] = x;
			(*m)++;
		}
	}
	Print(r, 10);
}




