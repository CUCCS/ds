#include"sort.h"
int main() {
    int array[100];
    int barry[100];
    int i = 0, m = 2, t = 1;
    srand(time(NULL));
    int movecount = 0, comparecount = 0;
    int length = rand() % 6 + 6;
    for (; i < length; i = i + 1) {
        barry[i] = array[i] = rand() % 7 + m;
        barry[i + 1] = array[i + 1] = rand() % 5 + t;
        m = m + 1;
        t = t + 2;
    }
    printf("随机正整数序列:\n");
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n------------------------------------------\n");
    insert_sort(array, length);
    copyarray(array, barry, length);
    printf("\n------------------------------------------\n");
    shell_sort(array, length);
    copyarray(array, barry, length);
    printf("\n------------------------------------------\n");
    bubble_sort(array, length);
    copyarray(array, barry, length);
    printf("\n------------------------------------------\n");
    quick_sort(array, 0, length - 1, &movecount, &comparecount);
    printf("\n快速排序后:\n");
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n总比较次数:%d,总移动记录次数:%d,二者次数之和:%d", movecount, comparecount, movecount + comparecount);
    copyarray(array, barry, length);
    printf("\n------------------------------------------\n");
    select_sort(array, length);
    printf("\n------------------------------------------\n");
    return 0;
}
