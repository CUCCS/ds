#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

void swap(ElemType a, ElemType b){
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
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
		A[i] = rand() % 90 + 10;
	}
}

void Insertion_Sort(ElemType *A, int size){
	int i;
	for (i = 0; i < size; i++){
		ElemType tmp;
		tmp = A[i];//a datum waited for insertion
		int j;
		for (j = i; j > 0 && A[j - 1]>tmp; j--)
			A[j] = A[j - 1];//move to spare a space for that datum to insert
		A[j] = tmp;
	}
}

void Bubble_Sort(ElemType *A,int size){
	int i, j,flag;
	for (i = size - 1; i >= 0; i--){
		flag = 0;//mark whether data are already sorted
		for (j = 0; j < i; j++){
			if (A[j] > A[j + 1]){
				swap(A[j], A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void Shell_Sort(ElemType *A, int size){
	int m,n,i;
	for (m = size / 2; m > 0; m /= 2){
		for (n = m; n < size; n++){//similar to Insertion_Sort
			ElemType tmp = A[n];
			for (i = n; i >= m && A[i - m]>tmp; i -= m)
				A[i] = A[i - m];
			A[i] = tmp;
		}
	}
}

int main()
{
	int size;
	size = rand() % 90 + 10;
	ElemType *A=(ElemType*)malloc(sizeof(ElemType)*size);
    GetTestInputs(A, size); 
	Show(A, size);
	Insertion_Sort(A, size);
	printf("after Insertion_Sort:\n");
	Show(A, size);
	free(A);

	size = rand() % 90 + 10;
	ElemType *B = (ElemType*)malloc(sizeof(ElemType)*size);
	GetTestInputs(B, size);
	Show(B, size);
	Bubble_Sort(B, size);
	printf("after Bubble_Sort:\n");
	Show(B, size);
	free(B);

	size = rand() % 90 + 10;
	ElemType *C = (ElemType*)malloc(sizeof(ElemType)*size);
	GetTestInputs(C, size);
	Show(C, size);
	Shell_Sort(C, size);
	printf("after Shell_Sort:\n");
	Show(C, size);
	free(C);
}