#include "Sort.h"

/* �Լ�¼����r��ֱ�Ӳ�������lengthΪ����ĳ��� */
Status InsSort(RecordType **r, int length, int *compare, int *move) {
	int i, j;
	RecordType temp;
	if (Empty(r)) {
		return ERROR;
	}
	for (i = 1; i < length; i++) {
		temp = (*r)[i];   /* ���������¼��ŵ���ʱ������ */
		(*move)++;
		j = i - 1;     /* ���һ����������ı߽�λ�� */
		while (++(*compare) && temp.key < (*r)[j].key) {   /* Ѱ�Ҳ���λ�� */
			(*r)[j + 1] = (*r)[j]; /* ��С�������򣬴�Ԫ������ */
			(*move)++;
			j = j - 1; /* ������Ԫ��������������һ��������һλ��Ԫ�ؼ������бȽ� */
		}
		(*r)[j + 1] = temp; /* ���������¼���뵽������������� */
		(*move)++;
	}
	return OK;
}

/* �Լ�¼����r��һ��ϣ����������lengthΪ����ĳ���, delta Ϊ���� */
Status ShellInsert(RecordType **r, int length, int delta, int *compare, int *move) {
	int i, j;
	RecordType temp;
	if (Empty(r)) {
		return ERROR;
	}
	for (i = delta; i < length; i++) { /* 1+deltaΪ��һ�������еĵڶ���Ԫ�ص��±� */
		if ((*r)[i].key < (*r)[i - delta].key && ++(*compare)) {
			temp = (*r)[i]; /* ����r[i] (����������) */
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

/* �Լ�¼����r��ϣ������ lengthΪ����ĳ���*/
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

/* �Լ�¼����r��ð������lengthΪ����ĳ��� */
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
			if ((*r)[j].key >(*r)[j + 1].key && ++(*compare)) {
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

/* �Լ�¼����r[low...high]�ÿ��������㷨�������� */
Status QKSort(RecordType *r, int low, int high, int *compare, int *move) {
	int pivot;
	if (low < high) {
		pivot = QKPass(r, low, high, compare, move);
		QKSort(r, low, pivot - 1, compare, move);
		QKSort(r, pivot + 1, high, compare, move);
	}
	return OK;
}

/* �Լ�¼����r �е�r[left]��r[right]���ֽ���һ�����򣬲��õ���׼��λ�ã�ʹ�������Ľ��������֮��ǰ���ļ�¼�Ĺؼ��־���С�ڣ����ڣ��ڻ�׼��¼ */
int QKPass(RecordType **r, int left, int right, int *compare, int *move) {
	int low, high;
	RecordType temp;
	temp = (*r)[left];             /* ѡ���׼��¼*/
	(*move)++;
	low = left;
	high = right;
	while (low < high) {
		while (low < high && (*r)[high].key >= temp.key && ++(*compare)) { /* high���ҵ�����С��x.key�ļ�¼ */
			high--;
		}
		(*r)[low] = (*r)[high]; /* �ҵ�С��x.key�ļ�¼������н��� */
		(*move)++;
		while (low < high && (*r)[low].key <= temp.key && ++(*compare)) { /* low�������Ҳ�С��x.key�ļ�¼ */
			low++;
		}
		(*r)[high] = (*r)[low]; /* �ҵ���С��x.key�ļ�¼���򽻻�*/
		(*move)++;
	}
	(*r)[low] = temp;  /* ����׼��¼���浽low=high��λ�� */
	*move++;
	return low;  /*���ػ�׼��¼��λ��*/
}

/* �Լ�¼����r����ѡ������lengthΪ����ĳ��� */
Status SelectSort(RecordType **r, int length, int *compare, int *move) {
	int i, j, k, n;
	RecordType temp;
	n = length;
	for (i = 0; i < n; ++i) {
		k = i;
		for (j = i + 1; j < n; ++j) {
			if ((*r)[j].key < (*r)[k].key && ++(*compare)) {
				k = j;
			}
		}
		if (k != i) {
			temp = (*r)[i];
			(*r)[i] = (*r)[k];
			(*r)[k] = temp;
			*move += 3;
		}
	}
	return OK;
}

/* ��֪r[s..m]�м�¼�Ĺؼ��ֳ���r[s].key֮�������ѵĶ��壬����������r[s]�Ĺؼ��֣�ʹr[s..m]��Ϊһ���󶥶�(�����м�¼�Ĺؼ��ֶ���) */
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

/* �Լ�¼����r���ж�����lengthΪ����ĳ��� */
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

/* �������r[i..m]��r[m+1..n]�鲢Ϊ�����r1[i..n]�� */
Status Merge(RecordType **r, RecordType **r1, int i, int m, int n, int *compare, int *move) {
	int j, k;
	int low, mid, high;
	low = i, mid = m, high = n;
	if (Empty(r)) {
		return ERROR;
	}
	for (j = mid + 1, k = low; low <= mid && j <= high; ++k) { // ��r�м�¼��С����ز���r1
		if ((*r)[low].key <= (*r)[j].key && ++(*compare)) {
			(*r1)[k] = (*r)[low++];
			(*move)++;
		}
		else {
			(*r1)[k] = (*r)[j++];
			(*move)++;
		}
	}
	while (low <= mid) { // ��ʣ���r[i..m]���Ƶ�r1
		(*r1)[k++] = (*r)[low++];
		(*move)++;
	}
	while (j <= high) { // ��ʣ���r[j..n]���Ƶ�r1
		(*r1)[k++] = (*r)[j++];
		(*move)++;
	}
	return OK;
}

/* �������r[s..t]�鲢����Ϊr1[s..t] */
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
		mid = (low + high) / 2; // ��r[low..high]ƽ��Ϊr1[low..mid]��r1[mid+1,high]
		temp = (RecordType *)malloc(sizeof(RecordType) * (high + 1)); // �����ռ䣬 ���Է��ִ�СҪΪhigh+1���������
		MSort(r, &temp, low, mid, compare, move); // �ݹ�ؽ�r[low..mid]�鲢Ϊ�����temp[low,mid]
		MSort(r, &temp, mid + 1, high, compare, move); // �ݹ�ؽ�r[mid+1..high]�鲢Ϊ�����temp[mid+1,high]
		Merge(&temp, r1, low, mid, high, compare, move); // ��temp[low..mid]��temp[mid+1,high]�鲢��r1[low,high]
		free(temp);
	}
	return OK;
}

/* �Լ�¼����r���鲢����lengthΪ����ĳ��� */
Status MergeSort(RecordType **r, int length, int *compare, int *move) {
	if (!MSort(r, r, 0, length - 1, compare, move)) {
		return OK;
	}
	return ERROR;
}

/* �жϼ�¼����r�Ƿ�Ϊ�� */
bool Empty(RecordType **r) {
	if (!r || !(*r)) {
		return TRUE;
	}
	return FALSE;
}

/* Ϊ��¼����r���ٿռ䣬���������������飬���������С */
int CreateTest(RecordType **r) {
	int n;
	n = (int)rand() % 9 + 10; // ���������С����Χ��10~18֮��
	*r = (RecordType *)malloc(sizeof(RecordType) * n);
	if (Empty(r)) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		(*r)[i].key = (int)rand() % 100 + 1; // ����1~100�������
	}
	return n;
}

/* �����¼����r�е�Ԫ�� */
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

/* �����¼����r����������ܱȽϴ��������ƶ������Լ�����֮�� */
Status PrintNum(int *compare, int *move) {
	// ����Ƚϴ����������������ܴ���
	if (*compare == 0 || *move == 0) {
		return ERROR;
	}
	printf("Compare times:%d\n", *compare);
	printf("Move times:%d\n", *move);
	printf("Total times:%d\n", *compare + *move);
	return OK;
}

/* �����¼����r�е�Ԫ�أ��Լ�����������ܱȽϴ��������ƶ�����������֮�� */
Status Print(RecordType **r, int n, int *compare, int *move) {
	if (PrintCase(r, n) && PrintNum(compare, move)) {
		printf("\n");
		return OK;
	}
	return ERROR;
}

/* ����¼����p��ԭΪԭʼ�ļ�¼����r�������ܱȽϴ��������ƶ��������� */
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

/* �Լ�¼����rʹ�ø������򷽷������������� */
Status Sort(RecordType **r, int n, int *compare, int *move) {
	RecordType *temp; // �ݴ�����

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