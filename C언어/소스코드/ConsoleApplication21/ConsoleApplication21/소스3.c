//#include <stdio.h> 
//#include <stdlib.h> 
//#include <string.h> 
//
//typedef struct stackNode
//{
//	char data;
//	struct stackNode *link;
//}stackNode;
//
//stackNode* top;
//
//void push(char item)
//{
//	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
//	temp->data = item;
//	temp->link = top;
//	top = temp;
//}
//
//char pop()
//{
//	char item;
//	stackNode* temp = top;
//
//	if (top == NULL)
//	{
//		printf("\n\n Stack is empty !\n");
//		return 0;
//	}
//	else
//	{
//		item = temp->data;
//		top = temp->link;
//		free(temp);
//		return item;
//	}
//}
//char peek()
//{
//	if (top == NULL)
//	{
//		printf("\n\n Stack is empty !\n");
//		return 0;
//	}
//	else
//	{
//		return top->data;
//	}
//}
//void postfix_case_bloack()
//{
//	char temp;
//
//	while (1)
//	{
//		temp = (char)peek(); // ���ÿ��� �ϳ��� ����
//
//		if ((temp != '(') && (temp != '{') && (temp != '[')) // ���� ��ȣ�� �ƴ϶��
//		{
//			printf("%c",pop());
//		}
//		else
//		{
//			pop();
//			break;
//		}
//	}
//}
//
//void postfix_case_operator_1(char symbol)
//{
//	char temp;
//	while (1) {
//		if (top == NULL)
//		{
//			break;
//		}
//			temp = (char)peek(); // ���ÿ��� �ϳ��� ����
//
//			if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
//			{
//				printf("%c", pop());		
//			}
//			else {
//				break;
//			}
//	}
//	push(symbol);
//}
//	
//void postfix_case_operator_2(char symbol)
//{
//	char temp;
//
//	while (1) {
//		if (top == NULL)
//		{
//			break;
//		}
//			temp = (char)peek(); // ���ÿ��� �ϳ��� ����
//
//			if (temp == '*' || temp == '/') // �켱������ ���� ���� ��ȣ���
//			{
//				printf("%c", pop());
//			}
//			else {
//				break;
//			}
//	}
//	push(symbol);
//}
//
//
//void postfix_case_default(char symbol)
//{
//	printf("%c", symbol);
//}
//
//// ���� ǥ�⸦ ���� ǥ��� ��ȯ
//void infix_to_postfix(char* exp)
//{
//	int i = 0, p = 0;
//	int length = strlen(exp);
//	char symbol;
//	
//	for (i = 0; i<length; i++)
//	{
//		symbol = exp[i];
//
//		switch (symbol)
//		{
//		case '(':
//		case '{':
//		case '[':
//			push(symbol); // ���� ��ȣ�� ���ÿ� ����
//			break;
//
//		case ')':
//		case '}':
//		case ']':
//			postfix_case_bloack();
//			break;
//
//		case '+':
//		case '-':
//			postfix_case_operator_1(symbol);
//			break;
//
//		case '*':
//		case '/':
//			postfix_case_operator_2(symbol);
//			break;
//
//		default:
//			postfix_case_default(symbol);
//			break;
//		}
//	}
//
//	while (top) // ���ÿ� ���� �ִ� ����
//	{
//		printf("%c",pop());
//	}
//	printf("\n");
//}
//
//// ���� �˻�
//int syntaxsearch(char *exp)
//{
//	int length = strlen(exp);
//	int i = 0;
//	int ncount = 0;
//	char symbol, opr;
//
//	for (i = 0; i<length; i++)
//	{
//		symbol = exp[i];
//
//		switch (symbol)
//		{
//		case '+':
//		case '-':
//		case '*':
//		case '/':
//			opr = exp[i + 1];
//			if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
//			{
//				printf("Operator error");
//				return -1;
//			}
//			break;
//
//		case '(':
//		case '{':
//		case '[':
//			push(symbol);
//			break;
//
//		case ')':
//			if (top == NULL)
//			{
//				printf("' ) ' Syntax error!!\n");
//				return -1;
//			}
//			else
//			{
//				if (pop() != '(')
//				{
//					printf("' ( ' Syntax error!!\n");
//					return -1;
//				}
//			}
//			break;
//
//		case '}':
//			if (top == NULL)
//			{
//				printf("' } ' Syntax error!!\n");
//				return -1;
//			}
//			else
//			{
//				if (pop() != '{')
//				{
//					printf("' { ' Syntax error!!\n");
//					return -1;
//				}
//			}
//			break;
//
//		case ']':
//			if (top == NULL)
//			{
//				printf("' ] ' Syntax error!!\n");
//				return -1;
//			}
//			else
//			{
//				if (pop() != '[')
//				{
//					printf("' [ ' Syntax error!!\n");
//					return -1;
//				}
//			}
//			break;
//
//		default:
//			if (symbol < 'A' || symbol > 'z')
//			{
//				printf("All not number!!\n");
//				return -1;
//			}
//			else
//			{
//				ncount++;
//			}
//			break;
//		}
//	}
//	if (!ncount || ncount == 1)
//	{
//		printf("Nmber is empty or unavailable!!");
//		return -1;
//	}
//	while (top)
//	{
//		opr = (char)pop();
//		if (opr == '(' || opr == '{' || opr == '[' ||
//			opr == '+' || opr == '-' || opr == '*' || opr == '/')
//		{
//			printf("` %c ' syntax error!!\n", opr);
//			return -1;
//		}
//	}
//	return 0;
//}
//
//void main(void)
//{
//	char buf[100 + 1];
//
//		printf("�� ���� ǥ����� �Է��ϼ��� [ ����: exit ]\n");
//		printf("[�Է�]: ");
//		scanf("%s", buf);
//		fflush(stdin);
//
//		if (syntaxsearch(buf) != -1)
//		{
//			printf("\n���� ǥ��� : %s\n", buf);
//			infix_to_postfix(buf);
//		}
//}
