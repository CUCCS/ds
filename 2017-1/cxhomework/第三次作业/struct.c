#include "source.h"

//优先级判断函数
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

//表达式求值
Status Evaluation(Number *SN, char s[100], int length)
 {
	nInitStack(SN);//数字所在的栈
	int e1, e2;
	int result = 0;
	int count = 1;//loop counter
	nPush(SN, s[count - 1] - '0');
	while (count<length - 1)
		 {
		if (!IN(s[count]))
			 {
			nPush(SN, s[count] - '0');//若s中对应元素为数字，则入数字栈
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

//转换为后缀表达式
//suffix:接收数字元素
//exp:中缀表达式
Status transform(SqStack *S, char suffix[100], char exp[100]) {
	InitStack(S);
	suffix[100] = '\0';
	Push(S, '#');//'#'入字符栈，成为栈底元素
	char *p;
	SElemType c;
	SElemType ch;//向栈传递表达式中的元素
	p = exp;//指向表达式中第一个元素
	ch = *p;
	while (!StackEmpty(S)) {
		if (!IN(ch))//IN:判断操作符, 若不是，则传给suffix; OP:定义为常量字符数组，存储运算符
			 {
			Pass(suffix, ch);//将数字传给suffix
			}
		else {
			switch (ch) {
				case '(':
					Push(S, ch);//左括号进栈 
					break;
					case ')':
					Pop(S, &c);//删除栈顶元素
						Pass(suffix, c);//把c值传给suffix
						Pop(S, &c);
						break;
						default:
							                    // Precede函数是判定运算符的栈顶运算符与读入的运算符之间优先关系的函数
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
			Pop(S, &ch);//删除'#'
			Pass(suffix, ch);//'#'进入suffix
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