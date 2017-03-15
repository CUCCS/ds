#include <stdio.h>
#include <stdlib.h>

static int steps = 0;

void print_step(char src, char dst)
{
    steps++;
    printf("Move top from %c to %c\n",src, dst);
}

void hanoi(int n, char src, char mid, char dst)
{
    if(n == 1){
        print_step(src, dst);
    }else{
        hanoi(n-1, src, dst, mid);
        print_step(src, dst);
        hanoi(n-1, mid, src, dst);
    }
}

int main(int argc, char** argv)
{
    if(argc != 2){
        printf("Usage: %s n\n",argv[0]);
        exit(1);
    }

    hanoi(atoi(argv[1]), 'A', 'B', 'C');
    printf("%d steps\n",steps);
    return 0;
}
