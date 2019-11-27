#include<stdio.h> 
#include<malloc.h> 
#include<string.h>
#define MAX_EELEMENT       100    //���׽��� �ִ� ���� ���� 
typedef struct __Element Element;
struct __Element
{
	int degree; //���� ���� 
	int value;  //�� 
};
typedef struct __Polynomial Polynomial;
struct __Polynomial
{
	Element base[MAX_EELEMENT]; //���׽��� �����ϴ� ��� ���� �����ϴ� �迭 
	int n;   //���� ���� 
};
void InitPolynomial(Polynomial *polynomial); //���׽��� �ʱ�ȭ 
int AddElement(Polynomial *polynomial, int value, int degree); //���׽Ŀ� ���� �߰�(���� ���� ������ ������) 
int InsertAt(Polynomial *polynomial, int index, Element *element); //���׽� Ư�� ��ġ�� ���� �߰� 
void AddPolynomials(Polynomial *poly1, Polynomial *poly2, Polynomial *result);//poly1 + poly2 = result 
void PrintPolynomial(Polynomial *polynomial); //���׽� ��� 
void PrintElement(Element *element); //���� ��� 
int main()
{

	Polynomial poly1, poly2, poly3;
	char str[50];
	char str2[50];
	printf("ù ��° ���׽��� �Է��ϼ��� : ");
	gets(str);
	printf("�� ��° ���׽��� �Է��ϼ��� : ");
	scanf("%s", str2);

	int i = 0; int j;
	int sum = 0;
	InitPolynomial(&poly1);

	for (i = 0; i<strlen(str); i++) {
		if (str[i] == '^') {
			j = i - 3;
			sum = (int)str[i - 2] - 48;
			if (str[j] != 'x' &&str[j] != '^'&&str[j] != '+') {
				sum = (int)str[i - 2] - 48;
				while (1) {
					if (str[j] != 'x'&&str[j] != '^'&&j >= 0 && str[j] != '+'&&str[j] != '-')
					{
						sum = ((int)str[j] - 48) * 10 + sum;
						j--;
					}
					else
						break;
				}
				if (str[j] == '-') {
					sum *= (-1);
				}
				AddElement(&poly1, sum, (int)str[i + 1] - 48);
			}
			else {
				if (str[j] == '-') {
					sum *= -1;
				}
				AddElement(&poly1, sum, (int)str[i + 1] - 48);
			}
		}
	}
	if (str[i - 2] != 'x' &&str[i - 2] != '^') {
		sum = (int)str[i - 1] - 48; j = i - 2;
		while (1) {
			if (str[j] != 'x'&&str[j] != '^'&&j >= 0 && str[j] != '+'&&str[j] != '-')
			{
				sum = ((int)str[j] - 48) * 10 + sum;
				j--;
			}
			else
				break;
		}
		if (str[j] == '-') {
			sum *= (-1);
		}
		AddElement(&poly1, sum, 0);
	}
	InitPolynomial(&poly2); //���׽� �ʱ�ȭ 

	for (i = 0; i<strlen(str2); i++) {
		if (str2[i] == '^') {
			j = i - 3;
			sum = (int)str2[i - 2] - 48;
			if (str2[j] != 'x' &&str2[j] != '^'&&str2[j] != '+') {
				sum = (int)str2[i - 2] - 48;
				while (1) {
					if (str2[j] != 'x'&&str2[j] != '^'&&j >= 0 && str2[j] != '+'&&str2[j] != '-')
					{
						sum = ((int)str2[j] - 48) * 10 + sum;
						j--;
					}
					else
						break;
				}
				if (str2[j] == '-') {
					sum *= (-1);
				}
				AddElement(&poly2, sum, (int)str2[i + 1] - 48);
			}
			else {
				if (str2[j] == '-') {
					sum *= -1;
				}
				AddElement(&poly2, sum, (int)str2[i + 1] - 48);
			}
		}
	}
	if (str2[i - 2] != 'x' &&str2[i - 2] != '^') {
		sum = (int)str2[i - 1] - 48; j = i - 2;
		while (1) {
			if (str2[j] != 'x'&&str2[j] != '^'&&j >= 0 && str[j] != '+'&&str2[j] != '-')
			{
				sum = ((int)str2[j] - 48) * 10 + sum;
				j--;
			}
			else
				break;
		}
		if (str2[j] == '-') {
			sum *= (-1);
		}
		AddElement(&poly2, sum, 0);
	}


	InitPolynomial(&poly3); //���׽� �ʱ�ȭ
	AddPolynomials(&poly1, &poly2, &poly3); //�� ���� ���׽��� ���Ͽ� ����� poly3�� ���� 
											//��� ��� �κ� 
	PrintPolynomial(&poly1); //���׽� ��� 
	printf("   +   "); //+���� ��ȣ�� ��� 
	PrintPolynomial(&poly2); //���׽� ��� 
	printf(" = "); //= ���� ��ȣ�� ��� 
	PrintPolynomial(&poly3); //���׽� ��� 
	printf("\n"); //���� ���� ��� 
	return 0;
}
void InitPolynomial(Polynomial *polynomial)
{
	polynomial->n = 0;
}
int AddElement(Polynomial *polynomial, int value, int degree)
{
	int i = 0;
	int diff_degree;
	Element element = { degree,value };
	for (i = 0; i<polynomial->n; i++)
	{
		diff_degree = polynomial->base[i].degree - degree; //i ��° ���� ������ �߰��� ���� ������ �� 
		if (diff_degree < 0) // i��° ���� ������ �߰��� ���� �������� ������ 
		{
			return InsertAt(polynomial, i, &element); //i ��° ��ġ�� ���� �߰� 
		}
		else if (diff_degree == 0) //i��° ���� ������ �߰��� ���� ������ ������ 
		{
			polynomial->base[i].value += value; //i��° ���� ���� �߰��� ���� ���� ���� 
			return 1; //���ϱ� ���꼺 �� 
		}
	}
	return InsertAt(polynomial, i, &element); //i ��° ��ġ�� ���� �߰� 
}
int InsertAt(Polynomial *polynomial, int index, Element *element)
{
	int i = 0;
	if (polynomial->n == MAX_EELEMENT) //�̹� �ִ����� ������ �߰� ���� 
	{
		return 0;  //�� �߰� ���� ��ȯ 
	}
	//i��° ��Һ��� ������ ��ҵ��� ��� �� ĭ�� �ڷ� �̵� 
	//�� �ڿ� ��Һ��� �̵��ؾ� ������� ���� 
	for (i = polynomial->n; i>index; i--)
	{
		polynomial->base[i] = polynomial->base[i - 1]; //�ڷ� �� ĭ �̵� 
	}
	polynomial->base[index] = *element; //index ��ġ�� ���ڷ� ���� ���� �߰� 
	polynomial->n++; //���׽��� ���� ���� ������ 1 �ø� 
	return 1; //�� �߰� ���� ��ȯ 
}
void AddPolynomials(Polynomial *poly1, Polynomial *poly2, Polynomial *result)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < poly1->n; i++)
	{
		//��� ���׽Ŀ� poly1�� ��� ���� �߰� 
		AddElement(result, poly1->base[i].value, poly1->base[i].degree);
	}
	for (j = 0; j < poly2->n; j++)
	{
		//��� ���׽Ŀ� poly2�� ��� ���� �߰� 
		AddElement(result, poly2->base[j].value, poly2->base[j].degree);
	}
}
void PrintPolynomial(Polynomial *polynomial)
{
	int i = 0;
	if (polynomial->n == 0) //���׽��� ���� ������ 0�̸� 
	{
		printf("0"); //0�� ��� 
		return;
	}
	PrintElement(polynomial->base + 0); //ù ��° ���� ��� 
	for (i = 1; i< polynomial->n; i++)
	{
		printf(" + "); //+ ���� ��ȣ�� ��� 
		PrintElement(polynomial->base + i); //i��° ���� ��� 
	}
}
void PrintElement(Element *element)
{
	printf("%d", element->value); //���� ��� 
	if (element->degree>1) //������ 1���� ũ�� 
	{
		printf("x^%d", element->degree); //x^������ ��� 
	}
	else if (element->degree == 1) //������ 1�̸� 
	{
		printf("x"); //x�� ��� 
	}
}