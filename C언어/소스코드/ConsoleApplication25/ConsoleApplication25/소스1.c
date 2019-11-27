#include<stdio.h> 
#include<malloc.h> 
#include<string.h>
#define MAX_EELEMENT       100    //다항식의 최대 항의 개수 
typedef struct __Element Element;
struct __Element
{
	int degree; //항의 차수 
	int value;  //값 
};
typedef struct __Polynomial Polynomial;
struct __Polynomial
{
	Element base[MAX_EELEMENT]; //다항식을 구성하는 요소 항을 보관하는 배열 
	int n;   //항의 개수 
};
void InitPolynomial(Polynomial *polynomial); //다항식을 초기화 
int AddElement(Polynomial *polynomial, int value, int degree); //다항식에 항을 추가(높은 차수 순으로 보관함) 
int InsertAt(Polynomial *polynomial, int index, Element *element); //다항식 특정 위치에 항을 추가 
void AddPolynomials(Polynomial *poly1, Polynomial *poly2, Polynomial *result);//poly1 + poly2 = result 
void PrintPolynomial(Polynomial *polynomial); //다항식 출력 
void PrintElement(Element *element); //항을 출력 
int main()
{

	Polynomial poly1, poly2, poly3;
	char str[50];
	char str2[50];
	printf("첫 번째 다항식을 입력하세요 : ");
	gets(str);
	printf("두 번째 다항식을 입력하세요 : ");
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
	InitPolynomial(&poly2); //다항식 초기화 

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


	InitPolynomial(&poly3); //다항식 초기화
	AddPolynomials(&poly1, &poly2, &poly3); //두 개의 다항식을 더하여 결과를 poly3에 설정 
											//결과 출력 부분 
	PrintPolynomial(&poly1); //다항식 출력 
	printf("   +   "); //+연산 기호를 출력 
	PrintPolynomial(&poly2); //다항식 출력 
	printf(" = "); //= 연산 기호를 출력 
	PrintPolynomial(&poly3); //다항식 출력 
	printf("\n"); //개행 문자 출력 
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
		diff_degree = polynomial->base[i].degree - degree; //i 번째 항의 차수와 추가할 항의 차수를 비교 
		if (diff_degree < 0) // i번째 항의 차수가 추가할 항의 차수보다 작으면 
		{
			return InsertAt(polynomial, i, &element); //i 번째 위치에 항을 추가 
		}
		else if (diff_degree == 0) //i번째 항의 차수와 추가할 항의 차수가 같을때 
		{
			polynomial->base[i].value += value; //i번째 항의 값에 추가할 항의 값을 더함 
			return 1; //더하기 연산성 공 
		}
	}
	return InsertAt(polynomial, i, &element); //i 번째 위치에 항을 추가 
}
int InsertAt(Polynomial *polynomial, int index, Element *element)
{
	int i = 0;
	if (polynomial->n == MAX_EELEMENT) //이미 최대항이 있으면 추가 못함 
	{
		return 0;  //항 추가 실패 반환 
	}
	//i번째 요소부터 마지막 요소들을 모두 한 칸씩 뒤로 이동 
	//맨 뒤에 요소부터 이동해야 사라지지 않음 
	for (i = polynomial->n; i>index; i--)
	{
		polynomial->base[i] = polynomial->base[i - 1]; //뒤로 한 칸 이동 
	}
	polynomial->base[index] = *element; //index 위치에 인자로 들어온 항을 추가 
	polynomial->n++; //다항식의 현재 항의 개수를 1 늘림 
	return 1; //항 추가 성공 반환 
}
void AddPolynomials(Polynomial *poly1, Polynomial *poly2, Polynomial *result)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < poly1->n; i++)
	{
		//결과 다항식에 poly1의 요소 항을 추가 
		AddElement(result, poly1->base[i].value, poly1->base[i].degree);
	}
	for (j = 0; j < poly2->n; j++)
	{
		//결과 다항식에 poly2의 요소 항을 추가 
		AddElement(result, poly2->base[j].value, poly2->base[j].degree);
	}
}
void PrintPolynomial(Polynomial *polynomial)
{
	int i = 0;
	if (polynomial->n == 0) //다항식의 항의 개수가 0이면 
	{
		printf("0"); //0을 출력 
		return;
	}
	PrintElement(polynomial->base + 0); //첫 번째 항을 출력 
	for (i = 1; i< polynomial->n; i++)
	{
		printf(" + "); //+ 연산 기호를 출력 
		PrintElement(polynomial->base + i); //i번째 항을 출력 
	}
}
void PrintElement(Element *element)
{
	printf("%d", element->value); //값을 출력 
	if (element->degree>1) //차수가 1보다 크면 
	{
		printf("x^%d", element->degree); //x^차수를 출력 
	}
	else if (element->degree == 1) //차수가 1이면 
	{
		printf("x"); //x를 출력 
	}
}