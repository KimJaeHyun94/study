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
	printf("입력하세요 : ");
	scanf("%s", exp);
	char * post_exp = infix_to_postfix(exp);
	TreeNode* root = generate_exp_tree(post_exp);
	fflush(stdin);
	printf("입력 : %s", exp);
	printf("\n전위 순회 : ");
	preorder(root);
	printf("\n중위 순회 : ");
	inorder(root);
	printf("\n후위 순회 : ");
	postorder(root);
	printf("\n레벨 순회 : ");
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
	int i = 0; // for문을 위한 i의 선언
	char ch, top_op; // 값들을 처리하기위한 정수형 변수 ch, top_op의 선언
	int len = strlen(exp); // len : exp의 문자열의 길이를 나타냄, length의 선언
	int pointer = 0; // Array들의 순서를 지칭해주기 위한 pointer의 선언
	StackType s; // 변경과정에 사용될 스택의 선언 
	char *postfix_arr = (char*)malloc(MAX_SIZE); // postfix_arr = 후위표기식으로 변환된 값들을 순서대로 가지고 있는 Array를 선언

	init_stack(&s);
	for (i = 0; i<len; i++)
	{
		ch = exp[i];
		if (is_empty(&s) == 1)
		{
			switch (ch)
			{
			case ')': // ")" 기호가 들어왔을 경우, 수식이 잘못된 것이므로 종료한다
				printf("괄호의 짝이 잘못되었습니다 \n");
				break;
			case '+': case '-': case '*': case '/': case '(': // 나머지 연산자인 경우에는 그대로 스택에 저장해주면 된다
				push(&s, ch);
				break;
			default:
				if (ch<'10')
				{ // 들어온 것의 절대값이 10보다 크거나 같을경우, 즉 두자리 수 이상의 수일 경우
					postfix_arr[pointer++] = ch; // 오류를 출력해준다
					break;
				}
				else
				{
					printf("두자리 수 이상의 숫자 연산은 불가능합니다 \n");
					break;
				}
			}
		}
		else
		{
			switch (ch)
			{
			case '+': case '-': case '*': case '/': // 들어온 것이 괄호가 아닐경우, 들어온 연산자가 스택 내 연산자와 비교하여  
				while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				{ // 우선순위가 높을 경우 스택에 저장하여 주고,
					postfix_arr[pointer++] = pop(&s); // 스택 내 데이터보다 우선순위가 낮을경우, 스택 내 Top부터 시작하여 들어온 것과 비교하여 우선순위가 낮은
				} // 연산자가 나올때까지, 모두 pop연산을 진행하여 준다.
				push(&s, ch); // 그 이후 들어온 연산자를 스택에 저장하여 준다.
				break;
			case '(': // 들어온 것이 "("일 경우, 그대로 스택에 저장해준다
				push(&s, ch);
				break;
			case ')':
				if (search(&s, '(') == 0)
				{ // 기호 ")"가 들어온 케이스에서, 스택 내 "("가 존재하지 않을경우
					printf("괄호의 짝이 잘못되었습니다 \n");
					break;
				}
				else
				{ // 기호 ")"가 들어온 케이스에서, 스택 내 "("가 존재할경우
					top_op = pop(&s); // 스택 내 "("가 저장된 윗부분까지의 모든 스택 내 저장된 값들을 출력해준다
					while (top_op != '(')
					{
						postfix_arr[pointer++] = top_op;
						top_op = pop(&s);
					}
					break;
				}
			default:
				if (ch<'10')
				{ // 들어온 것의 절대값이 10보다 크거나 같을경우, 즉 두자리 수 이상의 수일 경우
					postfix_arr[pointer++] = ch; // 오류를 출력해준다
					break;
				}
				else
				{
					printf("두자리 수 이상의 숫자 연산은 불가능합니다 \n");
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


// 수식트리생성함수
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
		case '+': case '-': case '*': case '/': // 연산자가 입력됬을 경우, 스택의 Top과 Top-1을 자식노드로 가지는
			b = pop_treestack(&s); // 서브 트리를 만든 후, 스택에 삽입하여 준다
			a = pop_treestack(&s);
			push_treestack(&s, create_tree_node(ch, a, b));
			break;
		default:
			push_treestack(&s, create_tree_node(ch, NULL, NULL)); // 피연산자가 입력되었을 경우, 단말노드를 생성하여
			break; // 그대로 스택으로 삽입하여 준다.
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

//-------------------------------------------- 스택 관련 함수시작 --------------------------------------------
//스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_SIZE - 1));
}

//삽입 함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//삭제 함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//peek 함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)];
}
//search 함수
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
//-------------------------------------------- 스택 관련 함수끝 --------------------------------------------

//-------------------------------------------- 트리 노드 스택 관련 함수시작 --------------------------------------------
//스택 초기화 함수
void init_treestack(TreeNodeStackType *s)
{
	s->top = -1;
}

//공백 상태 검출 함수
int treestack_is_empty(TreeNodeStackType *s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int treestack_is_full(TreeNodeStackType *s)
{
	return (s->top == (MAX_SIZE - 1));
}

//삽입 함수
void push_treestack(TreeNodeStackType *s, TreeNode * item)
{
	if (treestack_is_full(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//삭제 함수
TreeNode* pop_treestack(TreeNodeStackType *s)
{
	if (treestack_is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//peek 함수
TreeNode* peek_treestack(TreeNodeStackType *s)
{
	if (treestack_is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)];
}
//-------------------------------------------- 트리 노드 스택 관련 함수끝 --------------------------------------------

//-------------------------------------------- 트리 노드 큐 관련 함수시작 --------------------------------------------
//스택 초기화 함수
void init_treequeue(TreeNodeQueueType *q)
{
	q->front = -1;
	q->rear = 0;
}

//공백 상태 검출 함수
int treequeue_is_empty(TreeNodeQueueType *q)
{
	return (q->front + 1 == q->rear);
}

//포화 상태 검출 함수
int treequeue_is_full(TreeNodeQueueType *q)
{
	return (q->rear + 1 == MAX_SIZE);
}

//삽입 함수
void enqueue(TreeNodeQueueType *q, TreeNode * item)
{
	if (treequeue_is_full(q)) {
		printf("큐 포화 에러\n");
		return;
	}
	else q->queue[(q->rear)++] = item;
}

//삭제 함수
TreeNode* dequeue(TreeNodeQueueType *q)
{
	if (treequeue_is_empty(q)) {
		printf("큐 공백 에러\n");
		exit(1);
	}
	else return q->queue[++(q->front)];
}

//peek 함수
TreeNode* peek_queue(TreeNodeQueueType *q)
{
	if (treequeue_is_empty(q)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return q->queue[(q->front) + 1];
}