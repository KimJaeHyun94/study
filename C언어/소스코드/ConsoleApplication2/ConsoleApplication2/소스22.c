//#include<stdio.h>
//#include<stdlib.h>
//typedef struct st {
//	char name[20];
//	char addr[50];
//	int age;
//}ST;
//ST*func(ST*p) {
//	ST*tmp = p;
//	tmp = (ST*)malloc(sizeof(ST));
//	printf("�̸� :");
//	gets(tmp->name);
//	printf("�ּ� :");
//	gets(tmp->addr);
//	printf("���� :");
//	scanf("%d", &(tmp->age));
//	return tmp;
//}
//int main() {
//	ST*p=NULL;
//	p = func(p);
//	ST s;
//	FILE*fp;
//	if ((fp = fopen("student.txt", "wb")) == NULL)
//	{
//		fprintf(stderr, "����� ���� ������ �� �� �����ϴ�\n");
//		exit(1);
//	}
//	fwrite(p, sizeof(ST), 3, fp);
//	fclose(fp);
//	if ((fp = fopen("student.txt", "rb")) == NULL) {
//		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�\n");
//		exit(1);
//	}
//			fread(&s, sizeof(ST), 1, fp);
//			printf("�̸� =%s, �ּ� =%s, ����=%d\n", s.name, s.addr, s.age);
//	fclose(fp);
//	free(p);
//	return 0;
//}
