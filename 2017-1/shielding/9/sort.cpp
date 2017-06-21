#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

void swap(ElemType *a, ElemType *b){
	ElemType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Show(ElemType* A, int size){
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n\n");
}


void GetTestInputs(ElemType *A, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		A[i] = rand() % 900 + 10;
	}
}

void SameTestInputs(ElemType *A, ElemType *B,int size) {
	int i;
	for (i = 0; i < size; ++i) {
		B[i]=A[i];
	}
}

void Insertion_Sort(ElemType *A, int size){
	int i,cmp=0,move=0;
	for (i = 0; i < size; i++){
		ElemType tmp;
		tmp = A[i];//����������
		int j;
		for (j = i; j > 0; j--){
			if (A[j - 1] <= tmp && cmp++) break;
			else{
				A[j] = A[j - 1];//�ƶ��Կճ�һ����ȷλ�ø�����������
				move++;
			}
		}
		A[j] = tmp;
	}
	printf("�Ƚ�%d��,�ƶ�%d��,��%d��\n", cmp, move, cmp + move);
}

void Bubble_Sort(ElemType *A, int size){
	int i, j, flag,cmp = 0, move = 0;
	for (i = size-1 ; i >= 0; i--){
		flag = 0;//��������Ƿ�������
		for (j = 0; j < i; j++){	
			cmp++;
			if (A[j] > A[j + 1]){
				swap(&A[j], &A[j + 1]);
				move++;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
	printf("�Ƚ�%d��,�ƶ�%d��,��%d��\n", cmp, move,cmp+move);
}

void Shell_Sort(ElemType *A, int size){
	int m, n, i,cmp=0,move=0;
	for (m = size / 2; m > 0; m /= 2){
		for (n = m; n < size; n++){//�Ͳ�����������
			ElemType tmp = A[n];
			for (i = n; i >= m; i -= m){
				if (A[i - m] <= tmp && cmp++) break;
				else{
					A[i] = A[i - m];
					move++;
				}
			}
			A[i] = tmp;
		}
	}
	printf("�Ƚ�%d��,�ƶ�%d��,��%d��\n", cmp, move, cmp + move);
}

void Quick_Sort(ElemType *A, int l, int r,int *cmp, int *move){
	int i, j, x;
	if (l < r && ++(*cmp)){
		i = l;
		j = r;
		x = A[i];
		while (i < j && (*cmp)++){
			while (i < j && A[j] > x  && (*cmp)++){
				j--;
			}// ���������ҵ�һ��С��x���� 
			if (i < j && (*cmp)++){
				A[i++] = A[j];
				(*move) += 2;
			}
			while (i < j && A[i] < x  && (*cmp)++){
				i++;
			}// ���������ҵ�һ������x����
			if (i < j && (*cmp)++){
				A[j--] = A[i];
				(*move)++;
			}
		}
		A[i] = x;
		Quick_Sort(A, l, i - 1, cmp, move); // �ݹ�
		Quick_Sort(A, i + 1, r, cmp, move);
	}
}

void Selection_Sort(ElemType *A, int n){
	int i = 0, j = 0, min = 0, tmp = 0, cmp=0, move=0;
	for (i = 0; i < n - 1; i++){
		min = i;
		for (j = i; j < n; j++){
			if (A[min]>A[j] && cmp++){
				min = j;
			}
		}//����СԪ�� 
		if (min != i && cmp++){
			tmp=A[min];
			A[min] = A[i];
			A[i] = tmp;
			move += 3;
		}//����СԪ�ز������򲿷ֵ���ǰ�棬������ǰ��Ԫ�ؽ���λ��   
	}
	printf("�Ƚ�%d��,�ƶ�%d��,��%d��\n", cmp, move, cmp + move);
}


int main()
{
	int size;
	size = rand() % 50 + 10;
	ElemType *A = (ElemType*)malloc(sizeof(ElemType)*size);
	ElemType *B = (ElemType*)malloc(sizeof(ElemType)*size);
	ElemType *C = (ElemType*)malloc(sizeof(ElemType)*size);
	ElemType *D = (ElemType*)malloc(sizeof(ElemType)*size);
	ElemType *E = (ElemType*)malloc(sizeof(ElemType)*size);
	GetTestInputs(A, size);
	SameTestInputs(A, B, size);
	SameTestInputs(A, C, size);
	SameTestInputs(A, D, size);
	SameTestInputs(A, E, size);

	Show(A, size);//���δ����ǰ����

	printf("after Insertion_Sort:\n");
	Insertion_Sort(A, size);
	Show(A, size);
	free(A);

	printf("after Bubble_Sort:\n");
	Bubble_Sort(B, size);
	Show(B, size);
	free(B);

	printf("after Shell_Sort:\n");
	Shell_Sort(C, size);
	Show(C, size);
	free(C);

	printf("after Quick_Sort:\n");
	int cmp=0,move=0;
	Quick_Sort(D, 0, size - 1,&cmp,&move);
	printf("�Ƚ�%d��,�ƶ�%d��,��%d��\n", cmp, move, cmp + move);
	Show(D, size);
	free(D);

	printf("after Selection_Sort:\n");
	Selection_Sort(E, size);
	Show(E, size);
	free(E);


}