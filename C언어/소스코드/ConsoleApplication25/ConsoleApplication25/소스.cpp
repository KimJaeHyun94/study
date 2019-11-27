#include <stdio.h>
#include <malloc.h>

// ����ü ���� (���)
typedef struct _node node;
typedef node* pnode;

struct _node {
	double coef;
	int exp;
	pnode next;
};

// ��� �ּ� ��ȯ
pnode creNode(double coef, int exp)
{
	pnode p = (pnode)malloc(sizeof(node));
	p->coef = coef;
	p->exp = exp;
	p->next = NULL;
	return p;
}

// ��� �޸� ����
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

// ���׽� ���
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

// ��� ��� ��
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
			// ū ����� ��� �տ� ����
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

//�� ���� ���׽��� ���� ���׽��� ��ȯ

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

//Ű����κ��� ���׽� �Է� �� ��ȯ

pnode crePoly()
{
	pnode p = NULL;
	double coef;
	int i;
	int n;
	int exp;

	printf("���׽� �� ����: ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		//  ��� �Է½� ���� 0����
		printf("���, ����: ");
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

	printf("���׽� 1 �Է�\n");
	p1 = crePoly();
	printf("p1(x) = ");
	printPoly(p1);

	printf("���׽� 2 �Է�\n");
	p2 = crePoly();
	printf("p2(x) = ");
	printPoly(p2);

	p5 = addPoly(p1, p2);
	printf("p1(x) + p2(x) = ");
	printPoly(p5);


	// �޸� ����
	deNode(&p1);
	deNode(&p2);
	deNode(&p5);

	return 0;
}
