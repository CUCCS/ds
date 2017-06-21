#include <iostream>

using namespace std;

void print(int a[], int n )
{  
	cout<<n <<":";  
	for(int j= 0; j<n; j++)
      {  
		cout<<a[j] <<" ";  
	}  
	cout<<endl;  
}  

void InsertSort(int a[], int len)  
{  
	for (int i=0; i<len-1; i++)  
	{  
		int k = i;  
		int key = a[i];  
		for (int j=i+1; j<len; j++)  //找出剩余数据中最小的数
		{  
			if (a[j]< key)  
			{  
				k = j;  
				key = a[j];  
			}  
		}  
		if (k!=i)  
		swap(a[i], a[k]);  
	}  
}  

int main(){  
	int a[9] = {3,1,5,7,2,4,9,6,6};  
	InsertSort(a,9);  
	print(a,9);  
}  