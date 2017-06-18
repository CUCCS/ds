#include "Sort.h"

/* ��ӡ���� */
Status  PrintArray(ElemeyType *a, int l, int move_count, int compare_count) {
	int i;
	for (i = 0; i < l; i++) {
		printf("%d ", a[i + 1]);
	}
	if (a[0] == 1)
		printf("\n���㷨ִ�е� �ܱȽϴ���Ϊ��%d ���ƶ���¼����Ϊ:%d ���ߴ���֮��Ϊ:%d\n",
			compare_count, move_count, compare_count + move_count);
	else
		printf("\n");
	return OK;
}

/* ֱ�Ӳ������� */
Status InsSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	int i, j;
	for (i = 2; i <= length; i++) {
		*r = *(r + i);   /* ���������¼��ŵ���ʱ������ */
		j = i - 1;     /* ���һ����������ı߽�λ�� */
		(*compare_count)++;
		while (r[0] < r[j]) { 	/* Ѱ�Ҳ���λ�� */
			(*move_count)++;
			*(r + j + 1) = *(r + j);/* ��С�������򣬴�Ԫ������ */
			j = j - 1; /* ������Ԫ��������������һ��������һλ��Ԫ�ؼ������бȽ� */
		}
		*(r + j + 1) = r[0]; /* ���������¼���뵽������������� */
	}
	*r = 1;
	return OK;
}

/* һ��ϣ���������� */
void ShellInsert(ElemeyType *r, int length, int delta, int *move_count, int *compare_count) {
	//lengthΪ����ĳ���, delta Ϊ����
	int i, j;
	for (i = 1 + delta; i <= length; i++) { /* 1+deltaΪ��һ�������еĵڶ���Ԫ�ص��±� */
		(*compare_count)++;
		if (r[i] < r[i - delta]) {
			*r = r[i];     /* ����r[i] (����������) */
			for (j = i - delta; j > 0 && r[0] < r[j]; j -= delta) {
				(*compare_count)++;
				*(r + j + delta) = r[j];
				(*move_count)++;
			}
			*(r + j + delta) = r[0];
		}
	}
}

/* ϣ������ */
void ShellSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	//lengthΪ����ĳ���
	int d = length / 2;
	while (d >= 1) {
		ShellInsert(r, length, d, move_count, compare_count);
		d = d / 2;
	}
	*r = 1;
}

/* ð������ */
void BubbleSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	//lengthΪ����ĳ���
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

/* �������� */
void QKSort(ElemeyType *r, int low, int high, int *move_count, int *compare_count) {
	int pivot;
	if (low < high) {
		pivot = QKPass(r, low, high, move_count, compare_count);
		QKSort(r, low, pivot - 1, move_count, compare_count);
		QKSort(r, pivot + 1, high, move_count, compare_count);
	}
	*r = 1;
}

/* һ�˿������� */
int QKPass(ElemeyType *r, int left, int right, int *move_count, int *compare_count) {
	//�Լ�¼����r �е�r[left]��r[right]���ֽ���һ�����򣬲��õ���׼��λ�ã�ʹ�������Ľ��������֮��ǰ��
	//�ļ�¼�Ĺؼ��־���С�ڣ����ڣ��ڻ�׼��¼
	int x, low, high;
	x = r[left];             /* ѡ���׼��¼*/
	low = left;
	high = right;
	while (low < high) {
		while (low < high && r[high] >= x) { /* high���ҵ�����С��x�ļ�¼ */
			(*compare_count)++;
			high--;
		}
		*(r + low) = r[high]; /* �ҵ�С��x.key�ļ�¼������н��� */
		(*move_count)++;
		while (low < high && r[low] < x) { /* low�������Ҳ�С��x�ļ�¼ */
			*(compare_count)++;
			low++;
		}
		*(r + high) = r[low]; /* �ҵ���С��x�ļ�¼���򽻻�*/
		(*move_count)++;
	}

	*(r + low) = x;  /* ����׼��¼���浽low=high��λ�� */
	return low;  /*���ػ�׼��¼��λ��*/
}

/* ѡ������ */
void SelectSort(ElemeyType *r, int length, int *move_count, int *compare_count) {
	//lengthΪ����ĳ���
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