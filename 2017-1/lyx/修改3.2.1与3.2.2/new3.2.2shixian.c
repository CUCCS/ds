 #include "new3.2.2.h" 
 Status Push(SqStack *s,SElemType e) 
 {//����Ԫ��eΪ�µ�ջ��Ԫ�� 
 	if(s->top - s->base > s->stacksize){//ջ����׷�Ӵ洢�ռ� 
 		s->base = (SElemType*)realloc(s->base,(s->stacksize + 2*STACK_INIT_SIZE)*sizeof(SElemType));//׷�Ӵ洢�ռ� 
 		if(!s->base){//����� 
 			return OVERFLOW; 
 		} 
 		s->top = s->base + s->stacksize;//����ջ��Ԫ�� 
 		s->stacksize += 2 * STACK_INIT_SIZE;//׷�Ӵ洢�ռ� 
 	} 
 	*s->top = e;//����Ԫ��eΪ�µ�ջ��Ԫ�� 
 	s->top++;//s���£�ָ��topԪ�� 
 	return OK; 
 }//Push 
 Status InitStack(SqStack *s) 
 {//����һ����ջ 
 	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));//����洢�ռ� 
 	if(!s->base){//����� 
 		return OVERFLOW; 
	} 
 	s->top = s->base;//ʹջ��ָ�����ջ��ָ�� 
 	s->stacksize = STACK_INIT_SIZE;//�м������������ջ�Ĵ�С 
 	return OK; 
 }//InitStack 
 Status brackets(SqStack *s,char*test) 
 {//����ƥ�亯�� 
 	int i;
	int j=0;//��������i��j��ʹj��ֵ����0 
 	SElemType e;
	SElemType m;
	SElemType n;//�����ַ���emn //�����ʽ��
     for(i=0;test[i] != '\0';i++){//��test�л����ַ���ʱ 
 		switch(test[i])//switchѡ����� 
		{ 
 		case'{': 
 		case'[': 
 		case'(': 
 			{//������ջ���ַ�Ϊ{[�� 
 				Push(s,test[i]);//����ջ��Ϊ�µ�ջ��Ԫ�� 
 				SElemType*l = s->base;//�м��ָ��ָ��ջ��ָ�� 
 				while(l != s->top)//��l����ջ��ָ��ʱ 
 				{ 
 					printf("%c",*l);//���l 
 				    l++;//l�Լ� 
 				} 
 				printf("\n");//���� 
 				break;//�����˴�switch��� 
 			} 
		case'}'://������ջ���ַ�Ϊ} 
 			{ 
 				GetTop(s,&e);//�õ�ջ��Ԫ�� 
 				if(e == '{')//���ջ��Ԫ��Ϊ{ 
 				{ 
 					if(StackEmpty == false)//ջ�л���Ԫ�أ������ǿ�ջ 
 					{ 
 						Pop(s,&m);//ɾ��ջ��Ԫ�� 
 						SElemType*l = s->base;//����ջ��Ԫ�� 
 						while(l != s->top)//��l����ջ��ָ��ʱ 
 						{ 
 					       printf("%c",*l);//���l 
 				           l++;//l�Լ� 
 				         } 
 				        printf("\n");//���� 
 					} 
 				} 
 				else//����õ���ջ��Ԫ�ز���{ 
				{ 
 					Push(s,test[i]);//����õ���Ԫ��Ϊ�µ�ջ��Ԫ�� 
 					Pop(s,&m);//ɾ��ԭ����ջ��Ԫ������ 
					SElemType*l = s->base;//����ջ��Ԫ�� 
 						while(l != s->top)//��l����ջ��ָ��ʱ 
 						{ 
 					       printf("%c",*l);//���l 
 				           l++;//l�Լ� 
				         } 
				        printf("\n");//���� 
 					} 
 				break;//�����˴�switch��� 
 				} 
 		case']'://������ջ���ַ�Ϊ] 
 			{ 
 				GetTop(s,&e);//�õ�ջ��Ԫ�� 
 				if(e == '[')//���ջ��Ԫ��Ϊ[ 
 				{ 
 					if(StackEmpty == false)//ջ�л���Ԫ�أ������ǿ�ջ 
 					{ 
 						Pop(s,&m);//ɾ��ջ��Ԫ�� 
 						SElemType*l = s->base;//����ջ��Ԫ�� 
 						while(l != s->top)//��l����ջ��ָ��ʱ 
 						{ 
 					       printf("%c",*l);//���l 
 				           l++;//l�Լ� 
				         } 
				        printf("\n");//���� 
 					} 
				} 
 				else//����õ���ջ��Ԫ�ز���[ 
 				{ 
 					Push(s,test[i]);//����õ���Ԫ��Ϊ�µ�ջ��Ԫ�� 
 					Pop(s,&m);//ɾ��ԭ����ջ��Ԫ������ 
 						SElemType*l = s->base;//����ջ��Ԫ�� 
 						while(l != s->top)//��l����ջ��ָ��ʱ 
 						{ 
 					       printf("%c",*l);//���l 
 				           l++;//l�Լ� 
 				         } 
 				        printf("\n");//���� 
 					} 
 				break;//�����˴�switch��� 
 				} 
 		case')'://������ջ���ַ�Ϊ) 
 			{ 
 				GetTop(s,&e);//�õ�ջ��Ԫ�� 
 				if(e == '(')//���ջ��Ԫ��Ϊ( 
				{ 
					if(StackEmpty == false)//ջ�л���Ԫ�أ������ǿ�ջ 
 					{ 
 						Pop(s,&m);//ɾ��ջ��Ԫ�� 
 						SElemType*l = s->base;//����ջ��Ԫ�� 
 						while(l != s->top)//��l����ջ��ָ��ʱ 
 						{ 
 					       printf("%c",*l);//���l 
 				           l++;//l�Լ� 
 				         } 
 				        printf("\n");//���� 
 					} 
 				} 
 				else//����õ���ջ��Ԫ�ز���( 
 				{ 
 					Push(s,test[i]);//����õ���Ԫ��Ϊ�µ�ջ��Ԫ�� 
 					Pop(s,&m);//ɾ��ԭ����ջ��Ԫ������ 
 						SElemType*l = s->base;//����ջ��Ԫ�� 
 						while(l != s->top)//��l����ջ��ָ��ʱ 
 						{ 
 					       printf("%c",*l);//���l 
 				           l++;//l�Լ� 
				         } 
 				        printf("\n");//���� 
 				}//end else 
 				break;//�����˴�switch��� 
 				}//end case 
 			}//end switch 
 			}//end for 
      if(StackEmpty(s) == true){//���ջΪ�� 
 		 return OK;//����OK��ƥ��ɹ� 
 	 } 
	  else{
		  return ERROR;
	  }//����ƥ�䲻�ɹ����
 }//brackets 
 bool StackEmpty(SqStack *s) 
 {//��ջsΪ��ջ���򷵻�TRUE�����򷵻�FALSE 
	if(s->base == s->top){//��ջ��ָ�����ջ��ָ�� 
 		return true;//��ջsΪ��ջ 
 	} 
 	else{//��ջ��ָ�벻����ջ��ָ�� 
 		return false;//��ջs���ǿ�ջ 
 	} 
 }//StackEmpty 
 Status Pop(SqStack *s,SElemType *e) 
 {//��ջ���գ���ɾ��s��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR 
 	if(s->top == s->base){//ջΪ��ջ 
		return ERROR;//����ERROR 
 	} 
 	else{ 
 		*e = * --s->top;//ջ��ָ���Լ���ָ����һ��Ԫ�� 
	} 
 }//Pop 
 Status GetTop(SqStack *s,SElemType *e) 
 {//��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR 
 	if(s->top == s->base){//ջΪ��ջ 
         return ERROR;//����ERROR 
 	} 
 	*e = *(s->top -1);//eָ��ջ��Ԫ�� 
 	return OK;//����OK 
 }//GetTop  
