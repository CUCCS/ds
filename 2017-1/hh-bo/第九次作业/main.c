//
//  main.c
//  hw9
//
//  Created by Huhongbo on 2017/6/7.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 25

//打印数组
void display(int *p, int n, int s1, int s2)
{
    int i;
    if (s1 != 0 && s2 != 0)
    {
        printf("\n总比较次数: %d\n", s1);
        printf("\n总移动记录次数: %d\n", s2);
        printf("\n二者次数之和: %d\n", s1 + s2);
        printf("\n排序结果: \n\n");
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}
//生成随机数组
int Create(int *p)
{
    int i,n,t;
    do
    {
        t= rand() % 20 + 1;
    }
    while (t <= 0);
    n = t;
    for (i = 0; i < n; i++)
    {
        do
        {
            t = rand() % 100 + 1;
        }
        while (t <= 0);
        p[i] = t;
    }
    return n;
}
//交换函数
void swap(int a,int b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
//起泡排序
void BubbleSort(int *p, int n)
{
    int i,j;
    int s1=0,s2=0;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1&&(++s1); j++)
            if (p[j] < p[j + 1])
            {
                swap(p[i],p[i+1]);
                s2+=3;
            }
    }
    printf("\n");
    printf("起泡排序\n");
    display(p, n, s1, s2);
    printf("\n");
}
//直接插入排序
void insertSort(int *p, int n)
{
    int i,j,t;
    int s1 = 0;//总比较次数
    int s2 = 0;//总移动次数
    for (i = 1; i < n; i++)
    {
        
        if ( p[i] > p[i - 1]&&(++s1) )
        {
            t= p[i];
            for (j = i - 1; (s1++), j >= 0; j--)
            {
                p[j + 1] = p[j];
                s2++;
            }
            p[j + 1] = t;
        }
    }
    printf("\n");
    printf("直接插入排序\n");
    display(p, n, s1, s2);
    printf("\n");
}
//希尔排序
void ShellSort(int *p, int n)
{
    int i;
    int s1 = 0;
    int s2 = 0;
    i = (n - 1) / 2;
    for (i = n / 2; i > 0; i = i / 2)
    {
        int x, y,t;
        for (x = i; x < n; x++)
        {
            if ((++(s1)) && p[x] >p[x - i])
            {
                t = p[x];
                (s1)++;
                for (y = x - i; (++(s1)) && t> p[y] && y >= 0; y -= i)
                {
                    p[y + i] = p[y];
                    (s2)++;
                }
                p[y + i] = t;
            }
        }
        
    }
    printf("\n");
    printf("希尔排序\n");
    display(p, n, s1, s2);
    printf("\n");
}

//快速排序--划分算法
int Partition(int *q, int n, int low, int high, int *s1, int *s2)
{
    int m;
    m = q[low];
    while (low < high)
    {
        while (low < high&&q[high] <= m&&++(*s1) )
        {
            --high;
            (*s2)++;
        }
        q[low] = q[high];
        while (  low < high && q[low] >= m&&++(*s1))
        {
            ++low;
            (*s2)++;
        }
        q[high] = q[low];
    }
    q[low] = m;
    return low;
}
//快速排序--递归
void QSort(int *q, int n, int low, int high, int *s1, int *s2)
{
    int p;
    if (low < high)
    {
        p = Partition(q, n, low, high, s1, s2);
        QSort(q, n, low, p - 1, s1, s2);//对左区间进行递归
        QSort(q, n, p + 1, high, s1, s2);//对右区间进行递归
    }
}
//快速排序
void QuickSort(int *q, int n)
{
    int sum1 = 0;
    int sum2 = 0;
    QSort(q, n, 0, n - 1, &sum1, &sum2);
    printf("\n");
    printf("快速排序\n");
    display(q, n, sum1, sum2);
    printf("\n");
}

//简单选择排序
void SelectSort(int *p, int n)
{
    int i, j;
    int s1 = 0;
    int s2 = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ( p[i] < p[j]&&(++s1))
            {
                swap(p[i],p[j]);
                s2+=3;
            }
        }
    }
    printf("\n");
    printf("简单选择排序\n");
    display(p, n, s1, s2);
    printf("\n");
}
int main()
{
    int i;
    srand(time(0));
    int list[Max];
    int copylist[Max];
    int length = Create(list);//制造需要打印的数组
    printf("打印初始数组\n\n");
    display(list, length, 0, 0);
    printf("\n");
    for(i=0;i<length;i++)
    {
        copylist[i] = list[i];
        
    }
    insertSort(copylist, length);//进行直接插入排序
    for(i=0;i<length;i++)
    {
        copylist[i] = list[i];
        
    }
    ShellSort(copylist, length);//进行希尔排序
    for(i=0;i<length;i++)
    {
        copylist[i] = list[i];
        
    }
    
    BubbleSort(copylist, length);//进行起泡排序
    for(i=0;i<length;i++)
    {
        copylist[i] = list[i];
        
    }
    
    QuickSort(copylist, length);//进行快速排序
    for(i=0;i<length;i++)
    {
        copylist[i] = list[i];
        
    }
    
    SelectSort(copylist, length);//进行简单选择排序
    return 0;
}
