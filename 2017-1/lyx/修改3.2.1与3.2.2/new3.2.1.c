  //main 3.2.1.cpp 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <time.h> 
 #include <math.h>//��ѧͷ������ȡ����ֵ
 #include"new3.2.1.h" 
 int main(int argc, char* argv[]) 
 { 
 	SqStack S; 
 	int input; 
 	int d; 
 	srand((unsigned)time(NULL));//��ʱ������ 
 	input= (int)rand() % 5000;//������ɲ������� 
 	d= (int)rand() % 9;//�������ת������ 
	if(d <0){
		printf("ERROR");
	    d = abs(d);
	}//��Ӷ�d���жϣ���dΪ��������ȡd�ľ���ֵ
	printf("%d\n%d\n", input, d); 
 	conversion(&S, input, d); 
 	return 0; 
 } 