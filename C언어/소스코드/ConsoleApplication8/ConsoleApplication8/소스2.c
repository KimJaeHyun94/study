#include <stdlib.h>
#include <stdio.h>
typedef struct st {
	char name[20];
	char addr[50];
	int age;
}ST;
ST*func() {
	ST*p = NULL;
	p = (ST*)malloc(sizeof(ST));
	printf("이름을 입력하세요 :");
	scanf("%s", p->name);
	printf("주소를 입력하세요 :");
	scanf("%s", p->addr);
	printf("나이를 입력하세요 :");
	scanf("%d", &p->age);
	return p;
}
int main(int argc, char* argv[])
{
	ST*p = NULL;
	char *ch;
	char *c= "c:\\test\\data.txt";
	p = func();
	FILE*fp = fopen(c, "w");
	if (fp == NULL)
	{
		printf("File open error...\n");
		return 0;
	}
	fwrite(p->name, 1, strlen(p->name), fp);
	fprintf(fp, "%\n");
	fwrite(p->addr, 1, strlen(p->addr), fp);
	fprintf(fp, "%\n");
	fprintf(fp, "%d\n", p->age);
	free(p);
	fclose(fp);

	fp = fopen("c:\\test\\data.txt", "r");
	if (fp == NULL)
	{
		printf("File open error...\n");
		return 0;
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	ch = (char*)malloc(size);
	fread(ch, 1, size, fp);
	printf("%d\n", size);
	printf("%s", ch);
	free(ch);
	fclose(fp);
	return 0;
}

