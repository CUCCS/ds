#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 1000
#define N 8
typedef struct
{
    int r[MAX];
    int length;
}SqList;

void print(SqList L)
{
    int i;
    for(i=1;i<L.length;i++)
        printf("%d,",L.r[i]);
    printf("%d",L.r[i]);
    printf("\n");
}

void swap(SqList *L,int i,int j)
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}

void SelectSort(SqList *L)
{
    int i,j,min;
    for(i=1;i<L->length;i++)
    {
        min=i;
        for(j=i+1;j<=L->length;j++)
        {
            if(L->r[min]>L->r[j])
            {
                min=j;
            }
        }
        if(i!=min)
        {
            swap(L,i,min);
        }
    }
}

int main()
{
    int i;
    int d[N]={1,9,2,5,8,11,6,3};
    SqList L0;
    for(i=0;i<N;i++)
    {
        L0.r[i+1]=d[i];
    }
    L0.length=N;

    printf("ÅÅÐòÇ°:\t\t\t");
    print(L0);
    printf("¼òµ¥Ñ¡ÔñÅÅÐò:\t\t");
    SelectSort(&L0);
    print(L0);

    return 0;
}
