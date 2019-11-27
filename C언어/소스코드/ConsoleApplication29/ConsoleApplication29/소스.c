#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef char element;
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;

typedef struct {
	TreeNode * stack[MAX_SIZE];
	int top;
}TreeNodeStackType;

typedef struct {
	TreeNode * queue[MAX_SIZE];
	int front;
	int rear;
}TreeNodeQueueType;

typedef struct {
	element stack[MAX_SIZE];
	int top;
}StackType;

void inorder(TreeNode *root);
void preorder(TreeNode *root);
void postorder(TreeNode *root);
void levelorder(TreeNode *root);

int evaluate(TreeNode *root);
int prec(char op);
element* infix_to_postfix(element exp[]);
TreeNode* generate_exp_tree(element* postfix_arr);
TreeNode* create_tree_node(element data, TreeNode * llink, TreeNode * rlink);

void init_stack(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);
int search(StackType *s, element item);

void init_treestack(TreeNodeStackType *s);
int treestack_is_empty(TreeNodeStackType *s);
int treestack_is_full(TreeNodeStackType *s);
void push_treestack(TreeNodeStackType *s, TreeNode * item);
TreeNode* pop_treestack(TreeNodeStackType *s);
TreeNode* peek_treestack(TreeNodeStackType *s);

void init_treequeue(TreeNodeQueueType *q);
int treequeue_is_empty(TreeNodeQueueType *q);
int treequeue_is_full(TreeNodeQueueType *q);
void enqueue(TreeNodeQueueType *q, TreeNode * item);
TreeNode* dequeue(TreeNodeQueueType *q);
TreeNode* peek_queue(TreeNodeQueueType *q);
// 
void main()
{
	char  exp[100];
	printf("�Է��ϼ��� : ");
	scanf("%s", exp);
	char * post_exp = infix_to_postfix(exp);
	TreeNode* root = generate_exp_tree(post_exp);
	fflush(stdin);
	printf("�Է� : %s", exp);
	printf("\n���� ��ȸ : ");
	preorder(root);
	printf("\n���� ��ȸ : ");
	inorder(root);
	printf("\n���� ��ȸ : ");
	postorder(root);
	printf("\n���� ��ȸ : ");
	levelorder(root);
	printf("\n");
}

void inorder(TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%c", root->data);
	inorder(root->right);

}
void preorder(TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	printf("%c", root->data);
	preorder(root->left);
	preorder(root->right);

}
void postorder(TreeNode* root)
{
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->data);
}
void levelorder(TreeNode* root)
{
	TreeNodeQueueType s;
	TreeNode* temp;

	init_treequeue(&s);
	enqueue(&s, root);

	while (!treequeue_is_empty(&s))
	{
		temp = dequeue(&s);
		printf("%c", temp->data);

		if (temp->left)
			enqueue(&s, temp->left);
		if (temp->right)
			enqueue(&s, temp->right);
	}
}

int prec(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

element* infix_to_postfix(element exp[])
{
	int i = 0; // for���� ���� i�� ����
	char ch, top_op; // ������ ó���ϱ����� ������ ���� ch, top_op�� ����
	int len = strlen(exp); // len : exp�� ���ڿ��� ���̸� ��Ÿ��, length�� ����
	int pointer = 0; // Array���� ������ ��Ī���ֱ� ���� pointer�� ����
	StackType s; // ��������� ���� ������ ���� 
	char *postfix_arr = (char*)malloc(MAX_SIZE); // postfix_arr = ����ǥ������� ��ȯ�� ������ ������� ������ �ִ� Array�� ����

	init_stack(&s);
	for (i = 0; i<len; i++)
	{
		ch = exp[i];
		if (is_empty(&s) == 1)
		{
			switch (ch)
			{
			case ')': // ")" ��ȣ�� ������ ���, ������ �߸��� ���̹Ƿ� �����Ѵ�
				printf("��ȣ�� ¦�� �߸��Ǿ����ϴ� \n");
				break;
			case '+': case '-': case '*': case '/': case '(': // ������ �������� ��쿡�� �״�� ���ÿ� �������ָ� �ȴ�
				push(&s, ch);
				break;
			default:
				if (ch<'10')
				{ // ���� ���� ���밪�� 10���� ũ�ų� �������, �� ���ڸ� �� �̻��� ���� ���
					postfix_arr[pointer++] = ch; // ������ ������ش�
					break;
				}
				else
				{
					printf("���ڸ� �� �̻��� ���� ������ �Ұ����մϴ� \n");
					break;
				}
			}
		}
		else
		{
			switch (ch)
			{
			case '+': case '-': case '*': case '/': // ���� ���� ��ȣ�� �ƴҰ��, ���� �����ڰ� ���� �� �����ڿ� ���Ͽ�  
				while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				{ // �켱������ ���� ��� ���ÿ� �����Ͽ� �ְ�,
					postfix_arr[pointer++] = pop(&s); // ���� �� �����ͺ��� �켱������ �������, ���� �� Top���� �����Ͽ� ���� �Ͱ� ���Ͽ� �켱������ ����
				} // �����ڰ� ���ö�����, ��� pop������ �����Ͽ� �ش�.
				push(&s, ch); // �� ���� ���� �����ڸ� ���ÿ� �����Ͽ� �ش�.
				break;
			case '(': // ���� ���� "("�� ���, �״�� ���ÿ� �������ش�
				push(&s, ch);
				break;
			case ')':
				if (search(&s, '(') == 0)
				{ // ��ȣ ")"�� ���� ���̽�����, ���� �� "("�� �������� �������
					printf("��ȣ�� ¦�� �߸��Ǿ����ϴ� \n");
					break;
				}
				else
				{ // ��ȣ ")"�� ���� ���̽�����, ���� �� "("�� �����Ұ��
					top_op = pop(&s); // ���� �� "("�� ����� ���κб����� ��� ���� �� ����� ������ ������ش�
					while (top_op != '(')
					{
						postfix_arr[pointer++] = top_op;
						top_op = pop(&s);
					}
					break;
				}
			default:
				if (ch<'10')
				{ // ���� ���� ���밪�� 10���� ũ�ų� �������, �� ���ڸ� �� �̻��� ���� ���
					postfix_arr[pointer++] = ch; // ������ ������ش�
					break;
				}
				else
				{
					printf("���ڸ� �� �̻��� ���� ������ �Ұ����մϴ� \n");
					break;
				}
			}
		}
	}
	while (!is_empty(&s))
	{
		postfix_arr[pointer++] = pop(&s);
	}
	postfix_arr[pointer++] = 0;
	return postfix_arr;
}


// ����Ʈ�������Լ�
TreeNode* generate_exp_tree(element* postfix_arr)
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


TreeNode* create_tree_node(element data, TreeNode * llink, TreeNode * rlink)
{
	TreeNode* dst = (TreeNode*)malloc(sizeof(TreeNode));
	dst->data = data;
	dst->left = llink;
	dst->right = rlink;
	return dst;
}

//-------------------------------------------- ���� ���� �Լ����� --------------------------------------------
//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (MAX_SIZE - 1));
}

//���� �Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//���� �Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//peek �Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)];
}
//search �Լ�
int search(StackType *s, element item)
{
	int i;

	for (i = 0; i<MAX_SIZE; i++)
	{
		if (item == s->stack[i])
		{
			return 1;
		}
	}
	return 0;
}
//-------------------------------------------- ���� ���� �Լ��� --------------------------------------------

//-------------------------------------------- Ʈ�� ��� ���� ���� �Լ����� --------------------------------------------
//���� �ʱ�ȭ �Լ�
void init_treestack(TreeNodeStackType *s)
{
	s->top = -1;
}

//���� ���� ���� �Լ�
int treestack_is_empty(TreeNodeStackType *s)
{
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int treestack_is_full(TreeNodeStackType *s)
{
	return (s->top == (MAX_SIZE - 1));
}

//���� �Լ�
void push_treestack(TreeNodeStackType *s, TreeNode * item)
{
	if (treestack_is_full(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//���� �Լ�
TreeNode* pop_treestack(TreeNodeStackType *s)
{
	if (treestack_is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//peek �Լ�
TreeNode* peek_treestack(TreeNodeStackType *s)
{
	if (treestack_is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)];
}
//-------------------------------------------- Ʈ�� ��� ���� ���� �Լ��� --------------------------------------------

//-------------------------------------------- Ʈ�� ��� ť ���� �Լ����� --------------------------------------------
//���� �ʱ�ȭ �Լ�
void init_treequeue(TreeNodeQueueType *q)
{
	q->front = -1;
	q->rear = 0;
}

//���� ���� ���� �Լ�
int treequeue_is_empty(TreeNodeQueueType *q)
{
	return (q->front + 1 == q->rear);
}

//��ȭ ���� ���� �Լ�
int treequeue_is_full(TreeNodeQueueType *q)
{
	return (q->rear + 1 == MAX_SIZE);
}

//���� �Լ�
void enqueue(TreeNodeQueueType *q, TreeNode * item)
{
	if (treequeue_is_full(q)) {
		printf("ť ��ȭ ����\n");
		return;
	}
	else q->queue[(q->rear)++] = item;
}

//���� �Լ�
TreeNode* dequeue(TreeNodeQueueType *q)
{
	if (treequeue_is_empty(q)) {
		printf("ť ���� ����\n");
		exit(1);
	}
	else return q->queue[++(q->front)];
}

//peek �Լ�
TreeNode* peek_queue(TreeNodeQueueType *q)
{
	if (treequeue_is_empty(q)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return q->queue[(q->front) + 1];
}