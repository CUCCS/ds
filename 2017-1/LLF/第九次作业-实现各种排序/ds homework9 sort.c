//ʵ�ֵھŴ���ҵ ��������(��ѡ+�鲢����) ���в�������ϣ������ð�����򡢼�ѡ�������δ�ı�ԭ��������˳��
//�ڿ�������͹鲢������ʹ���˵ݹ飬ֱ�Ӷ�ԭ�����������������
#include<stdio.h>
#include<time.h>
#include<malloc.h>

void Print(int *t, int len,int c,int m);
void swap(int *a, int *b);
int c = 0; 
int m = 0;//��¼����ıȽ����ƶ�����

//copy����
int * Copy(int s[],int len)
{
	int *r;//copyԭ����
	r = (int *)malloc(len * sizeof(int));
	for (int m = 0; m < len; m++)
		r[m] = s[m];
	return r;
}

//ֱ�Ӳ�������
void InsertSort(int s[], int len) 
{
	int insertVal = 0;
	int i = 0, j = 0;
	 c = 0; 
	 m = 0;
	for (i = 1; i < len; ++i) 
	{
		insertVal = s[i];
		//����i-1��Ԫ�ش��ڵ�i��Ԫ�أ����ƶ�����룻  
		//���������κβ���  
		if (s[i - 1] > insertVal) 
		{
			j = i - 1;
			//Ѱ�Ҳ���λ�ã�һ��Ѱ��һ�ߺ���  
			while (j >= 0 && s[j] > insertVal) 
			{
				s[j + 1] = s[j];
				--j;
				c++;
			}
			s[j + 1] = insertVal;
			m++;
		}

	}

}

//ϣ������
void ShellSort(int s[], int len)
{
	int i, j, k;
	 c = 0;
	 m = 0;
	int gap;    //gap�Ƿ���ĳ���  
	int temp;   //��Ϊϣ����������ֱ�Ӳ�������Ļ�����ʵ�ֵ�,������Ȼ��Ҫ������ 
	for (gap = len / 2; gap>0; gap = gap / 2) 
	{
		for (i = 0; i<gap; i++) 
		{
			for (j = i + gap; j<len; j = j + gap) 
			{ //����һ�εĲ�������  
				if (s[j] < s[j - gap]) 
				{
					temp = s[j];    //������
					k = j - gap;
					while (k >= 0 && s[k]>temp) 
					{
						s[k + gap] = s[k];
						k = k - gap;
					}
					s[k + gap] = temp;
					
				}
				c++;
			}m++;
		}
	}
}


//ð������
void BubbleSort(int s[], int len)
{
	int i, j,t;
	 c = 0; 
	 m = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (s[i] > s[j])
			{
				swap(&s[i], &s[j]);
			}
			c++;
		}
		m++;
	}
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
	 c = 0;
	 m = 0;
	//����N-1��ѡ�� 
	for (int i = 1 - 1; i<len ; i++)
	{
		int min = i;
		//�ҳ���iС�������ڵ�λ�� 
		for (int j = len - 1 ; j >= i; j--)
		{
			if (s[j] < s[min])
			{
				min = j;
			}
			m++;
		}
		//����iС���������ڵ�i��λ�ã�����պã��Ͳ��ý��� 
		if (i != min)
		{
			swap(&s[i], &s[min]);
		}
		c++;
	}
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
				c++;
			}
			else
			{
				i++;  // �����������һλ���������׼���Ƚϡ�  
				m++;
			}
			
		}

		/* ����whileѭ����i = j��
		* ��ʱ���鱻�ָ����������  -->  s[low+1] ~ s[i-1] < s[low]
		*                           -->  s[i+1] ~ s[high] > s[low]
		* ���ʱ������s�ֳ��������֣��ٽ�s[i]��s[low]���бȽϣ�����s[i]��λ�á�
		* ���s[i]��s[low]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
		*/

		if (s[i] >= s[low])  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���  
		{
			i--;
			m++;
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
			m++;
		}
		else 
		{
			tmp[k] = s[right_low++];
			m++;
		}
		c++;
	}
	if (left_low <= left_high) 
	{  
								
		for (i = left_low; i <= left_high; i++)
		{
			tmp[k++] = s[i];
			m++;
		}
	}
	if (right_low <= right_high)
	{
	
		for (i = right_low; i <= right_high; i++)
		{
			tmp[k++] = s[i];
			m++;
		}
	}
	for (i = 0; i < high - low + 1; i++)
	{
		s[low + i] = tmp[i];
		m++;
	}
	free(tmp);
	return;
}

void MergeSort(int s[], int first, int last)
{
	int mid = 0;
	if (first<last) 
	{
		mid = (first + last) / 2; //ע���ֹ��� 
								  //mid = first/2 + last/2;
								  //mid = (first & last) + ((first ^ last) >> 1);
		MergeSort(s, first, mid);
		MergeSort(s, mid + 1, last);
		merge(s, first, mid, last);
	}
	return;
}

void Print(int *t,int len,int c,int m)
{

	for (int j = 0; j < len; j++)
		printf("%d  ", t[j]);
	printf("care: %d   m: %d   total: %d\n", c, m, c + m);
	
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

	//copy��������
	int *a,*b,*d,*e,*h;
	a = Copy(t,n);
	b = Copy(t, n);
	e = Copy(t, n);
	d = Copy(t, n);
	h = Copy(t, n);

	printf("Example: ");
	for (int j = 0; j < n; j++)
		printf("%d  ", t[j]);
	printf("\n\n");

	//ֱ�Ӳ�������
	printf("InsertSort: ");
	InsertSort(a, n);
	Print(a, n, c, m);

	//ϣ������
	printf("ShellSort:  ");
	ShellSort(b, n);
	Print(b, n, c, m);

	//ð������
	printf("BubbleSort: ");
	BubbleSort(d, n);
	Print(d, n, c, m);


	//��ѡ������
	printf("SelectSort: ");
	SelectSort(e, n);
	Print(e, n, c, m);

	//��������
	c = 0; 
	m = 0;
	printf("QuickSort:  ");
	QuickSort(h,n,0,n-1);
	Print(h, n, c, m);
	
	//�鲢����
	c = 0;
	m = 0;
	printf("MergeSort:  ");
	MergeSort(t, 0, n - 1);
	Print(t, n, c, m);

	free(t);
	free(a);
	free(b);
	free(d);
	free(e);
	free(h);
	return 0;
}