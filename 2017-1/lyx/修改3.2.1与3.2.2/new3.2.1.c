  //main 3.2.1.cpp 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <time.h> 
 #include <math.h>//数学头函数，取绝对值
 #include"new3.2.1.h" 
 int main(int argc, char* argv[]) 
 { 
 	SqStack S; 
 	int input; 
 	int d; 
 	srand((unsigned)time(NULL));//用时间做种 
 	input= (int)rand() % 5000;//随机生成测试数据 
 	d= (int)rand() % 9;//随机生成转换数制 
	if(d <0){
		printf("ERROR");
	    d = abs(d);
	}//添加对d的判断，若d为负数，则取d的绝对值
	printf("%d\n%d\n", input, d); 
 	conversion(&S, input, d); 
 	return 0; 
 } 