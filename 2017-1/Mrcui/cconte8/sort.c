#include"sort.h"

void insert_sort(int a[], int n)//直接插入排序
{
    int temp;
    int i, j;
    int acount = 0, bcount = 0, ccount;
    for (i = 1; i < n; i++)//控制元素的插入
    {
        temp = a[i];//设置监视哨元素
        
        j = i - 1;
        while (bcount++ && temp < a[j]) {
            a[j + 1] = a[j];//将比temp大的元素依次后移
            acount++;
            j--;
            if (j < 0) {
                break;
            }
        }
        a[j + 1] = temp;//插入元素
        acount++;
    }
    printf("\n直接插入排序后:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    ccount = acount + bcount;
    printf("\n总比较次数:%d,总移动记录次数:%d,二者次数之和:%d", bcount, acount, ccount);
}

void shell_sort(int a[], int n)//希尔排序
{
    int di = n / 2;
    int i, j;
    int temp;
    int acount = 0, bcount = 0, ccount = 0;
    while (di >= 1) {
        for (i = di; i <= n; i++) {
            temp = a[i];
            j = i - di;
            while (bcount++ && temp < a[j]) {
                a[i] = a[j];
                a[j] = temp;
                acount++;
                j -= di;
                if (j <= 0) {
                    break;
                }
            }
            
        }
        di = di / 2;
    }
    printf("\n希尔排序后:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    ccount = acount + bcount;
    printf("\n总比较次数:%d,总移动记录次数:%d,二者次数之和:%d", bcount, acount, ccount);
    
}

void bubble_sort(int a[], int n)//起泡排序
{
    int i, j;
    int temp;
    int acount = 0, bcount = 0, ccount = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (bcount++ && a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                acount = acount + 3;
            }
        }
    }
    ccount = acount + bcount;
    printf("\n冒泡排序后:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n总比较次数:%d,总移动记录次数:%d,二者次数之和:%d", bcount, acount, ccount);
}

void quick_sort(int a[], int left, int right, int *movecount, int *comcount)//快速排序
{
    int i, j, temp;
    i = left;
    j = right;
    temp = a[left];
    if (left > right)
        return;
    while (i != j) {
        while ((*comcount)++, a[j] >= temp && j > i) {
            j--;
        }
        if (j > i) {
            a[i++] = a[j];
            (*movecount)++;
        }
        while ((*comcount)++, a[i] <= temp && j > i) { i++; }
        if (j > i) {
            a[j--] = a[i];
            (*movecount)++;
        }
        
    }
    a[i] = temp;
    quick_sort(a, left, i - 1, movecount, comcount);
    quick_sort(a, i + 1, right, movecount, comcount);
}

void select_sort(int a[], int n)//简单选择排序
{
    int min;
    int acount = 0, bcount = 0, ccount = 0;
    int temp;
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        min = i;
        for (j = i; j < n; ++j) {
            if (bcount++ && a[j] < a[min])  //使得min总是指向最小元素
                min = j;
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            acount++;
        }
    }
    ccount = acount + bcount;
    printf("\n简单选择排序后:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n总比较次数:%d,总移动记录次数:%d,二者次数之和:%d", bcount, acount, ccount);
    
}

void copyarray(int a[], int b[], int n)//恢复随机序列
{
    int i;
    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }
}
