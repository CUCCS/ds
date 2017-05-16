#include "source.h"

//���ȼ��жϺ���
int Precede(SElemType c, SElemType ch)
 {
	int i, j;
	switch (c) {
		case '+':
			i = 0;
			if (ch == '+') {
				j = 0;
				
			}
			else if (ch == '-') {
				j = 1;
				
			}
			else if (ch == '*') {
				j = 2;
				
			}
			else if (ch == '/') {
				j = 3;
				
			}
			else if (ch == '(') {
				j = 4;
				
			}
			else if (ch == ')') {
				j = 5;
				
			}
			else {
				j = 6;
				
			}
			break;
			case '-':
				i = 1;
				if (ch == '+') {
					j = 0;
					
				}
				else if (ch == '-') {
					j = 1;
					
				}
				else if (ch == '*') {
					j = 2;
					
				}
				else if (ch == '/') {
					j = 3;
					
				}
				else if (ch == '(') {
					j = 4;
					
				}
				else if (ch == ')') {
					j = 5;
					
				}
				else {
					j = 6;
					
				}
				break;
				case '*':
					i = 2;
					if (ch == '+') {
						j = 0;
						
					}
					else if (ch == '-') {
						j = 1;
						
					}
					else if (ch == '*') {
						j = 2;
						
					}
					else if (ch == '/') {
						j = 3;
						
					}
					else if (ch == '(') {
						j = 4;
						
					}
					else if (ch == ')') {
						j = 5;
						
					}
					else {
						j = 6;
						
					}
					break;
					case '/':
						i = 3;
						if (ch == '+') {
							j = 0;
							
						}
						else if (ch == '-') {
							j = 1;
							
						}
						else if (ch == '*') {
							j = 2;
							
						}
						else if (ch == '/') {
							j = 3;
							
						}
						else if (ch == '(') {
							j = 4;
							
						}
						else if (ch == ')') {
							j = 5;
							
						}
						else {
							j = 6;
							
						}
						break;
						case '(':
							i = 4;
							if (ch == '+') {
								j = 0;
								
							}
							else if (ch == '-') {
								j = 1;
								
							}
							else if (ch == '*') {
								j = 2;
								
							}
							else if (ch == '/') {
								j = 3;
								
							}
							else if (ch == '(') {
								j = 4;
								
							}
							else if (ch == ')') {
								j = 5;
								
							}
							else {
								j = 6;
								
							}
							break;
							case ')':
								i = 5;
								if (ch == '+') {
									j = 0;
									
								}
								else if (ch == '-') {
									j = 1;
									
								}
								else if (ch == '*') {
									j = 2;
									
								}
								else if (ch == '/') {
									j = 3;
									
								}
								else if (ch == '(') {
									j = 4;
									
								}
								else if (ch == ')') {
									j = 5;
									
								}
								else {
									j = 6;
									
								}
								break;
								case '#':
									i = 6;
									if (ch == '+') {
										j = 0;
										
									}
									else if (ch == '-') {
										j = 1;
										
									}
									else if (ch == '*') {
										j = 2;
										
									}
									else if (ch == '/') {
										j = 3;
										
									}
									else if (ch == '(') {
										j = 4;
										
									}
									else if (ch == ')') {
										j = 5;
										
									}
									else {
										j = 6;
										
									}
									break;
									
	}
	return PT[i][j];
	}//end of Precede

//���ʽ��ֵ
Status Evaluation(Number *SN, char s[100], int length)
 {
	nInitStack(SN);//�������ڵ�ջ
	int e1, e2;
	int result = 0;
	int count = 1;//loop counter
	nPush(SN, s[count - 1] - '0');
	while (count<length - 1)
		 {
		if (!IN(s[count]))
			 {
			nPush(SN, s[count] - '0');//��s�ж�ӦԪ��Ϊ���֣���������ջ
			}
		else {
			switch (s[count]) {
				case '*':
					nPop(SN, &e1);
					nPop(SN, &e2);
					result = e1 *  e2;
					nPush(SN, result);
					break;
					case '/':
						nPop(SN, &e1);
						nPop(SN, &e2);
						result = e2 / e1;
						nPush(SN, result);
						break;
						case '+':
							nPop(SN, &e1);
							nPop(SN, &e2);
							result = e1 + e2;
							nPush(SN, result);
							break;
							case '-':
							    nPop(SN, &e1);
								nPop(SN, &e2);
								result = e2 - e1;
								nPush(SN, result);
								break;
								
			}
			
		}
		count++;
		}
	nGetTop(SN, &e1);
	printf("%d", e1);
	nPop(SN, &e1);
	return OK;
	}

//What Is Pass
Status Pass(char suffix[100], SElemType ch)
 {
	Number SN;
	static char s2[100] = { NULL };
	static int i = 0;
	suffix[i] = ch;
	if (suffix[i] != '\0') {
		printf("%c", suffix[i]);
		s2[i] = suffix[i];
		if (suffix[i] == '#') {
			printf("\n");
			Evaluation(&SN, s2, strlen(s2));
			printf("\n");
			
		}
		
	}
	i++;
	return OK;
	}//end of Pass

//ת��Ϊ��׺���ʽ
//suffix:��������Ԫ��
//exp:��׺���ʽ
Status transform(SqStack *S, char suffix[100], char exp[100]) {
	InitStack(S);
	suffix[100] = '\0';
	Push(S, '#');//'#'���ַ�ջ����Ϊջ��Ԫ��
	char *p;
	SElemType c;
	SElemType ch;//��ջ���ݱ��ʽ�е�Ԫ��
	p = exp;//ָ����ʽ�е�һ��Ԫ��
	ch = *p;
	while (!StackEmpty(S)) {
		if (!IN(ch))//IN:�жϲ�����, �����ǣ��򴫸�suffix; OP:����Ϊ�����ַ����飬�洢�����
			 {
			Pass(suffix, ch);//�����ִ���suffix
			}
		else {
			switch (ch) {
				case '(':
					Push(S, ch);//�����Ž�ջ 
					break;
					case ')':
					Pop(S, &c);//ɾ��ջ��Ԫ��
						Pass(suffix, c);//��cֵ����suffix
						Pop(S, &c);
						break;
						default:
							                    // Precede�������ж��������ջ������������������֮�����ȹ�ϵ�ĺ���
								while (GetTop(S, &c) && (Precede(c, ch)))//ch>c:false
								 {
								if (c != '(') {
									Pass(suffix, c);
									
								}
								Pop(S, &c);
								}
							if (ch != '#') {
								Push(S, ch);
								
							}
							break;
							
			} // switch
			
		}
		if (ch != '#') {
			p++;
			ch = *p;
			
		}
		else {
			Pop(S, &ch);//ɾ��'#'
			Pass(suffix, ch);//'#'����suffix
			break;
			
		}
		
	}//while
	return OK;
	
} // transform

int main()
 {
	SqStack S;
	char suf[101] = { NULL };
	char ex[100] = { NULL };
	gets(ex);
	transform(&S, suf, ex);
	return 0;
	}