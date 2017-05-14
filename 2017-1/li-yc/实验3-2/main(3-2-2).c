#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "3-2-2.h"

int main(){
	char test[10]={'\0'};
	char ch[6]={'(',')','{','}','[',']'};
	srand(time(0));
	for(int i=0;i<6;i++){
		test[i]=ch[rand()%6];
	}
	printf("the character string is :\n");
	Traverse(test);
	matching(test);
	return 0;
}