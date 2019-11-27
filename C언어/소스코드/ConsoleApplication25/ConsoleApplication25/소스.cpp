#include <stdio.h>
#include <malloc.h>

// 구조체 정의 (노드)
typedef struct _node node;
typedef node* pnode;

struct _node {
	double coef;
	int exp;
	pnode next;
};

// 노드 주소 반환
pnode creNode(double coef, int exp)
{
	pnode p = (pnode)malloc(sizeof(node));
	p->coef = coef;
	p->exp = exp;
	p->next = NULL;
	return p;
}

// 노드 메모리 해제
void deNode(pnode* root)
{
	pnode p = *root;
	pnode next;

	while (p)
	{
		next = p->next;
		free(p);
		p = next;
	}
	*root = NULL;
}

// 다항식 출력
void printPoly(pnode poly)
{
	pnode p = poly;

	if (p->exp > 1)
	{
		if (p->coef == 1)
			printf("x%d", p->exp);
		else if (p->coef != 0)
			printf("%gx%d", p->coef, p->exp);
	}

	else if (p->exp == 1)
	{
		if (p->coef == 1)
			printf("x");
		else
			printf("%gx", p->coef);
	}
	else
		printf("%g", p->coef);

	p = p->next;

	while (p)
	{
		while (p->coef == 0)
		{
			p = p->next;
		}
		if (p->coef > 0)
			printf("+");
		if (p->exp > 1)
		{
			if (p->coef == 1)
				printf("x%d", p->exp);
			else if (p->coef != 0)
				printf("%gx%d", p->coef, p->exp);
		}

		else if (p->exp == 1)
		{
			if (p->coef == 1)
				printf("x");
			else
				printf("%gx", p->coef);
		}
		else
			printf("%g", p->coef);
		p = p->next;
	}
	printf("\n");
}

// 노드 계수 비교
void addNode(pnode *root, double coef, int exp)
{
	pnode p = *root;
	pnode pre = NULL;

	if (*root == NULL)
	{
		*root = creNode(coef, exp);
		return;
	}
	while (p)
	{
		if (p->exp == exp)
		{
			p->coef += coef;

			if (p->coef == 0)
			{

			}
			break;
		}
		else if (p->exp < exp)
		{
			// 큰 계수를 노드 앞에 삽입
			pnode nnode = creNode(coef, exp);

			nnode->next = p;

			if (pre)
				pre->next = nnode;
			else
				*root = nnode;
			break;
		}
		if (p->next == NULL)
		{
			pnode nnode = creNode(coef, exp);
			p->next = nnode;
			break;
		}
		pre = p;
		p = p->next;
	}
}

//두 개의 다항식을 더한 다항식을 반환

pnode addPoly(pnode po1, pnode po2)
{
	pnode p = NULL;
	pnode p1 = po1;
	pnode p2 = po2;

	while (p1)
	{
		addNode(&p, p1->coef, p1->exp);
		p1 = p1->next;
	}
	while (p2)
	{
		addNode(&p, p2->coef, p2->exp);
		p2 = p2->next;
	}
	return p;
}

//키보드로부터 다항식 입력 후 반환

pnode crePoly()
{
	pnode p = NULL;
	double coef;
	int i;
	int n;
	int exp;

	printf("다항식 항 갯수: ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		//  상수 입력시 지수 0으로
		printf("계수, 지수: ");
		scanf_s("%lf %d", &coef, &exp);
		addNode(&p, coef, exp);
	}
	return p;
}

int main()
{
	pnode p1 = NULL;
	pnode p2 = NULL;
	pnode p3 = NULL;
	pnode p4 = NULL;
	pnode p5 = NULL;
	pnode p6 = NULL;

	printf("다항식 1 입력\n");
	p1 = crePoly();
	printf("p1(x) = ");
	printPoly(p1);

	printf("다항식 2 입력\n");
	p2 = crePoly();
	printf("p2(x) = ");
	printPoly(p2);

	p5 = addPoly(p1, p2);
	printf("p1(x) + p2(x) = ");
	printPoly(p5);


	// 메모리 해제
	deNode(&p1);
	deNode(&p2);
	deNode(&p5);

	return 0;
}
