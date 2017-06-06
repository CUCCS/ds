//ʵ�ֵھŴ���ҵ ��������(��ѡ+�鲢����) ���в�������ϣ������ð�����򡢼�ѡ�������δ�ı�ԭ��������˳��
//�ڿ�������͹鲢������ʹ���˵ݹ飬ֱ�Ӷ�ԭ�����������������
#include<stdio.h>
#include<time.h>
#include<malloc.h>

void Print(int *t, int len,int comp,int move);
void swap(int *a, int *b);
int c1 = 0, m1 = 0;//��¼��������ıȽ����ƶ�����
int c2 = 0, m2 = 0;//��¼�鲢����ıȽ����ƶ�����

//ֱ�Ӳ�������
void InsertSort(int s[], int len) 
{
	int *r;//copyԭ����
	r = (int *)malloc(len * sizeof(int));
	for (int m = 0; m < len; m++)
		r[m] = s[m];
	int insertVal = 0;
	int i = 0, j = 0;
	int comp = 0, move = 0;
	for (i = 1; i < len; ++i) 
	{
		insertVal = r[i];
		//����i-1��Ԫ�ش��ڵ�i��Ԫ�أ����ƶ�����룻  
		//���������κβ���  
		if (r[i - 1] > insertVal) 
		{
			j = i - 1;
			//Ѱ�Ҳ���λ�ã�һ��Ѱ��һ�ߺ���  
			while (j >= 0 && r[j] > insertVal) 
			{
				r[j + 1] = r[j];
				--j;
				comp++;
			}
			r[j + 1] = insertVal;
			move++;
		}

	}
	Print(r, len,comp,move);

}

//ϣ������
void ShellSort(int s[], int len)
{
	int *r;//copyԭ����
	r = (int *)malloc(len * sizeof(int));
	for (int m = 0; m < len; m++)
		r[m] = s[m];
	int i, j, k;
	int comp = 0, move = 0;
	int gap;    //gap�Ƿ���ĳ���  
	int temp;   //��Ϊϣ����������ֱ�Ӳ�������Ļ�����ʵ�ֵ�,������Ȼ��Ҫ������ 
	for (gap = len / 2; gap>0; gap = gap / 2) 
	{
		for (i = 0; i<gap; i++) 
		{
			for (j = i + gap; j<len; j = j + gap) 
			{ //����һ�εĲ�������  
				if (r[j] < r[j - gap]) 
				{
					temp = r[j];    //������
					k = j - gap;
					while (k >= 0 && r[k]>temp) 
					{
						r[k + gap] = r[k];
						k = k - gap;
					}
					r[k + gap] = temp;
					
				}
				comp++;
			}move++;
		}
	}
	Print(r, len, comp, move);
}


//ð������
void BubbleSort(int s[], int len)
{
	int *r;//copyԭ����
	r = (int *)malloc(len * sizeof(int));
	for (int m = 0; m < len; m++)
		r[m] = s[m];
	int i, j,t;
	int comp = 0, move = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (r[i] > r[j])
			{
				swap(&r[i], &r[j]);
			}
			comp++;
		}
		move++;
	}
	Print(r, len, comp, move);
}

//����
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

//��ѡ������
void SelectSort(int s[], int len)//nΪ����a��Ԫ�ظ��� 
{
	int comp = 0, move = 0;
	int *r;//copyԭ����
	r = (int *)malloc(len * sizeof(int));
	for (int m = 0; m < len; m++)
		r[m] = s[m];
	//����N-1��ѡ�� 
	for (int i = 1 - 1; i<len ; i++)
	{
		int min = i;
		//�ҳ���iС�������ڵ�λ�� 
		for (int j = len - 1 ; j >= i; j--)
		{
			if (r[j] < r[min])
			{
				min = j;
			}
			move++;
		}
		//����iС���������ڵ�i��λ�ã�����պã��Ͳ��ý��� 
		if (i != min)
		{
			swap(&r[i], &r[min]);
		}
		comp++;
	}
	Print(r, len, comp, move);
}

//��������
void QuickSort(int s[], int len, int low, int high)
{
	int i, j;

	if (low < high)
	{
		i = low + 1;  // ��s[low]��Ϊ��׼������˴�s[low+1]��ʼ���׼���Ƚϣ�  
		j = high;        // s[high]����������һλ  

		while (i < j)
		{
			if (s[i] > s[low])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�  
			{
				swap(&s[i], &s[j]);  // ����������  
				j--;
				c1++;
			}
			else
			{
				i++;  // �����������һλ���������׼���Ƚϡ�  
				m1++;
			}
			
		}

		/* ����whileѭ����i = j��
		* ��ʱ���鱻�ָ����������  -->  s[low+1] ~ s[i-1] < s[low]
		*                           -->  s[i+1] ~ s[high] > s[low]
		* ���ʱ������s�ֳ��������֣��ٽ�s[i]��s[low]���бȽϣ�����s[i]��λ�á�
		* ���s[i]��s[low]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
		*/

		if (s[i] >= s[low])  // ��������Ԫ������ͬ��ֵʱ�������  
		{
			i--;
			m1++;
		}

		swap(&s[low], &s[i]);  // ����s[i]��s[low]  

		QuickSort(s, len, low, i);
		QuickSort(s, len, j, high);
	}
}

//�鲢����
void merge(int s[], int low, int mid, int high) 
{
	int i, k;
	int *tmp = (int *)malloc((high - low + 1) * sizeof(int));
	//����ռ䣬ʹ���СΪ����
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++)
	{  // �Ƚ�����ָ����ָ���Ԫ��
		if (s[left_low] <= s[right_low]) 
		{
			tmp[k] = s[left_low++];
			m2++;
		}
		else 
		{
			tmp[k] = s[right_low++];
			m2++;
		}
		c2++;
	}
	if (left_low <= left_high) 
	{  
								
		for (i = left_low; i <= left_high; i++)
		{
			tmp[k++] = s[i];
			m2++;
		}
	}
	if (right_low <= right_high)
	{
	
		for (i = right_low; i <= right_high; i++)
		{
			tmp[k++] = s[i];
			m2++;
		}
	}
	for (i = 0; i < high - low + 1; i++)
	{
		s[low + i] = tmp[i];
		m2++;
	}
	free(tmp);
	return;
}

void MergeSort(int s[], int first, int last)
{
	int mid = 0;
	if (first<last) 
	{
		mid = (first + last) / 2; //��ֹ��� 
								  //mid = first/2 + last/2;
								  //mid = (first & last) + ((first ^ last) >> 1);
		MergeSort(s, first, mid);
		MergeSort(s, mid + 1, last);
		merge(s, first, mid, last);
	}
	return;
}

void Print(int *t,int len,int comp,int move)
{

	for (int j = 0; j < len; j++)
		printf("%d  ", t[j]);
	printf("compare: %d   move: %d   total: %d\n", comp, move, comp + move);
	
}

int main()
{
	int n;
	srand((int)time(NULL)); /*����������Բ�����ͬ�������*/
	n = rand() %5+10;
	printf("%d\n", n);
	int *t;
	t = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		t[i] = rand() % 200;
	}

	//copy����������鲢����ʹ��
	int *r;
	r = (int *)malloc(n * sizeof(int));
	for (int m = 0; m < n; m++)
		r[m] = t[m];

	printf("Example: ");
	for (int j = 0; j < n; j++)
		printf("%d  ", t[j]);
	printf("\n\n");

	//ֱ�Ӳ�������
	printf("InsertSort: ");
	InsertSort(t, n);

	//ϣ������
	printf("ShellSort:  ");
	ShellSort(t, n);

	//ð������
	printf("BubbleSort: ");
	BubbleSort(t, n);

	//��ѡ������
	printf("SelectSort: ");
	SelectSort(t, n);

	//��������
	printf("QuickSort:  ");
	QuickSort(t,n,0,n-1);
	Print(t, n, c1, m1);
	
	//�鲢����
	printf("MergeSort:  ");
	MergeSort(r, 0, n - 1);
	Print(r, n, c2, m2);

	free(t);
	return 0;
}