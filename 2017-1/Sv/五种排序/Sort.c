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
	*CpNumber = 0;//�Ƚϴ���
	*MovNumber = 0;//�ƶ�����
	int i, j;
	for ( i = 2; i <=length; i++) {
		r[0] = r[i]; /* ���������¼��ŵ���ʱ������ */
		(*MovNumber)++;
		j = i - 1;     /* ���һ����������ı߽�λ�� */
		while ((++(*CpNumber))&&(r[0] < r[j])) {   /* Ѱ�Ҳ���λ�� */
			r[j + 1] = r[j]; /* ��С�������򣬴�Ԫ������ */
			(*MovNumber)++;
			j = j - 1; /* ������Ԫ��������������һ��������һλ��Ԫ�ؼ������бȽ� */
		}
		r[j + 1] = r[0]; /* ���������¼���뵽������������� */
		(*MovNumber)++;
	}
	Print(r, length);
}
void ShellInsert(RecordType r[], int length, int delta,int *CpNumber, int *MovNumber) {
	int i,j;
	*CpNumber = 0;
	*MovNumber = 0;
	for (i = 1 + delta; i <= length; i++) { /* 1+deltaΪ��һ�������еĵڶ���Ԫ�ص��±� */
		if ((++(*CpNumber))&&(r[i] < r[i - delta])) {
			r[0] = r[i]; /* ����r[i] (����������) */
			for (j = i - delta; j > 0 &&(++*(CpNumber))&& r[0] < r[j] ; j -= delta) {
				r[j + delta] = r[j];
				(*MovNumber)++;
			}
			r[j + delta] = r[0];
		}
	}
}

/* �Լ�¼����r��ϣ������ lengthΪ����ĳ���*/
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
	int x = r[left];             /* ѡ���׼��¼*/
	int low = left;
	int high = right;
	while (low < high) {
		while (low < high &&(++(*c))&& r[high] >= x) { /* high���ҵ�����С��x.key�ļ�¼ */
			high--;
		}
		r[low] = r[high]; /* �ҵ�С��x.key�ļ�¼������н��� */
		++(*m);
		while (low < high && (++(*c)) && r[low] < x) { /* low�������Ҳ�С��x.key�ļ�¼ */
			low++;
		}
		r[high] = r[low]; /* �ҵ���С��x.key�ļ�¼���򽻻�*/
		++(*m);
	}

	r[low] = x;  /* ����׼��¼���浽low=high��λ�� */
	++(*m);
	return low;  /*���ػ�׼��¼��λ��*/
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




