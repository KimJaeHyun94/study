#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define EMPTY 0
#define MAX_SIZE 100
typedef struct stackNode
{
	char data;
	struct stackNode *link;
}stackNode;

typedef struct node {
	char data;
	struct node*llink, *rlink;
}TreeNode;
typedef struct {
	TreeNode * stack[MAX_SIZE];
	int top;
}TreeNodeStackType;

stackNode* top;
TreeNode *root;
int treestack_is_empty(TreeNodeStackType *s)
{
	return (s->top == -1);
}
//��ȭ ���� ���� �Լ�
int treestack_is_full(TreeNodeStackType *s)
{
	return (s->top == (MAX_SIZE - 1));
}
TreeNode* create_tree_node(char data, TreeNode * llink, TreeNode * rlink)
{
	TreeNode* dst = (TreeNode*)malloc(sizeof(TreeNode));
	dst->data = data;
	dst->llink = llink;
	dst->rlink = rlink;
	return dst;
}
TreeNode* pop_treestack(TreeNodeStackType *s)
{
	if (treestack_is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

void init_treestack(TreeNodeStackType *s)
{
	s->top = -1;
}

void push_treestack(TreeNodeStackType *s, TreeNode * item)
{
	if (treestack_is_full(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

TreeNode* generate_exp_tree(char* postfix_arr)
{
	TreeNode *a;
	TreeNode *b;
	TreeNodeStackType s;
	int i = 0;
	int len = strlen(postfix_arr);
	char ch;

	init_treestack(&s);
	for (i = 0; i<len; i++) {
		ch = postfix_arr[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // �����ڰ� �Է��� ���, ������ Top�� Top-1�� �ڽĳ��� ������
			b = pop_treestack(&s); // ���� Ʈ���� ���� ��, ���ÿ� �����Ͽ� �ش�
			a = pop_treestack(&s);
			push_treestack(&s, create_tree_node(ch, a, b));
			break;
		default:
			push_treestack(&s, create_tree_node(ch, NULL, NULL)); // �ǿ����ڰ� �ԷµǾ��� ���, �ܸ���带 �����Ͽ�
			break; // �״�� �������� �����Ͽ� �ش�.
		}
	}
	return pop_treestack(&s);
}

void PreOrder(TreeNode**root) {
	printf("%c ", (*root)->data);
	if ((*root)->llink != EMPTY) {
		PreOrder(&(*root)->llink);
	}
	if ((*root)->rlink != EMPTY) {
		PreOrder(&(*root)->rlink);
	}
}
void InOrder(TreeNode**root) {
	if ((*root)->llink != EMPTY) {
		InOrder(&(*root)->llink);
	}
	printf("%c ", (*root)->data);
	if ((*root)->rlink != EMPTY) {
		InOrder(&(*root)->rlink);
	}
}
void PostOrder(TreeNode**root) {
	if ((*root)->llink != EMPTY) {
		PostOrder(&(*root)->llink);
	}
	if ((*root)->rlink != EMPTY) {
		PostOrder(&(*root)->rlink);
	}
	printf("%c ", (*root)->data);
}

void LevelOrder(TreeNode**root) {
	TreeNode* Queue[100];
	int front = 0, rear = 0;
	if (*root) {
		Queue[rear++] = *root;
	}
	while (*root != NULL && front != rear)
	{
		*root = Queue[front++];
		printf("%c ", (*root)->data);
		if ((*root)->llink) {
			Queue[rear++] = (*root)->llink;
		}
		if ((*root)->rlink) {
			Queue[rear++] = (*root)->rlink;
		}
	}
}
void push(char item)
{
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

char pop()
{
	char item;
	stackNode* temp = top;

	if (top == NULL)
	{
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else
	{
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

void postfix_case_bloack(char* stack, int *p)
{
	char temp;

	while (1)
	{
		temp = (char)pop(); // ���ÿ��� �ϳ��� ����

		if ((temp != '(') && (temp != '{') && (temp != '[')) // ���� ��ȣ�� �ƴ϶��
		{
			stack[(*p)++]= temp;
		}
		else
		{
			break;
		}
	}
}

void postfix_case_operator_1(char* stack, char symbol,int *p)
{
	char temp;

	while (1) {
		if (top == NULL)
		{
			break;
		}
		temp = (char)pop(); // ���ÿ��� �ϳ��� ����

		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
		{
			stack[(*p)++]= temp;
		}
		else {
			push(temp);
			break;
		}
	}
	push(symbol);
}

void postfix_case_operator_2(char* stack, char symbol,int *p)
{
	char temp;

	while (1) {
		if (top == NULL)
		{
			break;
		}
		temp = (char)pop(); // ���ÿ��� �ϳ��� ����

		if (temp == '*' || temp == '/') // �켱������ ���� ���� ��ȣ���
		{
			stack[(*p)++] = temp;
		}
		else {
			push(temp);
			break;
		}
	}
	push(symbol);
}

void postfix_case_default(char*stack, char symbol, char*exp, int*p, int i)
{
	stack[(*p)++] = symbol;
}

// ���� ǥ�⸦ ���� ǥ��� ��ȯ
char* infix_to_postfix(char* exp)
{
	int i = 0, p = 0;
	int length = strlen(exp);
	char symbol;
	char* stack=(char*)malloc(length*2);

	for (i = 0; i<length; i++)
	{
		symbol = exp[i];

		switch (symbol)
		{
		case '(':
		case '{':
		case '[':
			push(symbol); // ���� ��ȣ�� ���ÿ� ����
			break;

		case ')':
		case '}':
		case ']':
			postfix_case_bloack(stack,&p);
			break;

		case '+':
		case '-':
			postfix_case_operator_1(stack,symbol,&p);
			break;

		case '*':
		case '/':
			postfix_case_operator_2(stack,symbol,&p);
			break;

		default:
			postfix_case_default(stack, symbol,exp, &p, i);
			break;
		}
	}

	while (top) // ���ÿ� ���� �ִ� ����
	{
		stack[p++] = (char)pop();
	}
	stack[p]='\0';
	root = generate_exp_tree(stack);
	printf("Inorder : ");
	InOrder(&root);
	printf("\n");
	printf("Postorder : ");
	PostOrder(&root);
	printf("\n");
	printf("Preorder : ");
	PreOrder(&root);
	printf("\n");
	printf("Levelorder : ");
	LevelOrder(&root);
	printf("\n");

	return stack;
}

// ���� �˻�
int syntaxsearch(char *exp)
{
	int length = strlen(exp);
	int i = 0;
	int ncount = 0;
	char symbol, opr;

	for (i = 0; i<length; i++)
	{
		symbol = exp[i];

		switch (symbol)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			opr = exp[i + 1];
			if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
			{
				printf("Operator error");
				return -1;
			}
			break;

		case '(':
		case '{':
		case '[':
			push(symbol);
			break;

		case ')':
			if (top == NULL)
			{
				printf("' ) ' Syntax error!!\n");
				return -1;
			}
			else
			{
				if (pop() != '(')
				{
					printf("' ( ' Syntax error!!\n");
					return -1;
				}
			}
			break;

		case '}':
			if (top == NULL)
			{
				printf("' } ' Syntax error!!\n");
				return -1;
			}
			else
			{
				if (pop() != '{')
				{
					printf("' { ' Syntax error!!\n");
					return -1;
				}
			}
			break;

		case ']':
			if (top == NULL)
			{
				printf("' ] ' Syntax error!!\n");
				return -1;
			}
			else
			{
				if (pop() != '[')
				{
					printf("' [ ' Syntax error!!\n");
					return -1;
				}
			}
			break;

		default:
			if (symbol < 'A' || symbol > 'z')
			{
				printf("All not number!!\n");
				return -1;
			}
			else
			{
				ncount++;
			}
			break;
		}
	}
	if (!ncount || ncount == 1)
	{
		printf("Nmber is empty or unavailable!!");
		return -1;
	}
	while (top)
	{
		opr = (char)pop();
		if (opr == '(' || opr == '{' || opr == '[' ||
			opr == '+' || opr == '-' || opr == '*' || opr == '/')
		{
			printf("` %c ' syntax error!!\n", opr);
			return -1;
		}
	}
	return 0;
}


void main(void)
{
	char buf[100 + 1];

	printf("������ �Է��ϼ��� \n");
	printf("[�Է�]: ");
	scanf("%s", buf);
	fflush(stdin);
	if (syntaxsearch(buf) != -1)
	{
		printf("%s\n", infix_to_postfix(buf));
	}
}