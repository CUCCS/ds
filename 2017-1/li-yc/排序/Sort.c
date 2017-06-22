#include "Sort.h"

Status InsertSort(SqList *a, int *ctime, int *mtime) {
	int temp;
	int i;
	int j;
	for (i = 1; i < a->length; ++i) {
		if (a->r[i] < a->r[i - 1] && ++(*ctime)) {
			temp = a->r[i];
			a->r[i] = a->r[i - 1];
			++(*mtime);
			for (j = i - 1; temp < a->r[j]; --j) {
				a->r[j + 1] = a->r[j];
				++(*mtime);
			}
			a->r[j + 1] = temp;
			++(*ctime);
		}
	}
	return OK;
}

Status ShellInsert(SqList *a, int dk, int *ctime, int *mtime) {
	int temp;
	int i;
	int j;
	for (i = dk; i < a->length; ++i) {
		if (a->r[i] < a->r[i - dk] && ++(*ctime)) {
			temp = a->r[i];
			a->r[i] = a->r[i - dk];
			(*mtime)++;
			for (j = i - dk; j > 0 && temp < a->r[j]; --j) {
				a->r[j + dk] = a->r[j];
				++(*mtime);
			}
			a->r[j + dk] = temp;
			++(*ctime);
		}
	}
	return OK;
}

Status BubbleSort(SqList *a, int *ctime, int *mtime) {
	int i;
	int j;
	int temp;
	for (i = 0; i < a->length; ++i) {
		for (j = i + 1; j < a->length; ++j) {
			if (a->r[i] > a->r[j] && ++(*ctime)) {
				temp = a->r[i];
				a->r[i] = a->r[j];
				a->r[j] = temp;
				(*mtime) += 3;
			}
		}
	}
	return OK;
}

Status QKSort(SqList *a, int low, int high, int *ctime, int *mtime) {
	int pivotlo;
	if (low < high) {
		pivotlo = QKPass(a, low, high, ctime, mtime);
		QKSort(a, low, pivotlo - 1, ctime, mtime);
		QKSort(a, pivotlo + 1, high, ctime, mtime);
	}
	return OK;
}

int QKPass(SqList *a, int left, int right, int *ctime, int *mtime) {
	int key = a->r[left];
	int low = left;
	int high = right;
	while (low < high) {
		while (low < high&&a->r[high] >= key&&++(*ctime)) {
			high--;
		}
		a->r[low] = a->r[high];
		++(*mtime);
		while (low < high&&a->r[low] < key&&++(*ctime)) {
			low++;
		}
		a->r[high] = a->r[low];
		++(*mtime);
	}
	a->r[low] = key;
	++(*mtime);
	return low;
}

Status SelectSort(SqList *a, int *ctime, int *mtime) {
	int i;
	int j;
	int key;
	int temp;
	for (i = 0; i < a->length; ++i) {
		key = i;
		for (j = i + 1; j < a->length; ++j) {
			if (a->r[j] < a->r[key] && ++(*ctime)) {
				key = j;
			}
		}
		if (key != i) {
			temp = a->r[i];
			a->r[i] = a->r[key];
			a->r[key] = temp;
			(*mtime) += 3;
		}
	}
	return OK;
}

Status Traverse(SqList a) {
	int i;
	for (i = 0; i < a.length; ++i) {
		printf("%d ", a.r[i]);
	}
	printf("\n");
	return OK;
}

Status InitTestArrary(SqList *a, SqList *a1, int *ctime, int *mtime) {
	int i;
	for (i = 0; i < a->length; ++i) {
		a1->r[i] = a->r[i];
	}
	*ctime = 0;
	*mtime = 0;
	printf("\n将排序完成的数组恢复成原来顺序\n\n");
	return OK;
}