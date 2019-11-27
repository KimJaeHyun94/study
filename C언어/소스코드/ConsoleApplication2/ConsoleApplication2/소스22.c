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
//	printf("이름 :");
//	gets(tmp->name);
//	printf("주소 :");
//	gets(tmp->addr);
//	printf("나이 :");
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
//		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다\n");
//		exit(1);
//	}
//	fwrite(p, sizeof(ST), 3, fp);
//	fclose(fp);
//	if ((fp = fopen("student.txt", "rb")) == NULL) {
//		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다\n");
//		exit(1);
//	}
//			fread(&s, sizeof(ST), 1, fp);
//			printf("이름 =%s, 주소 =%s, 나이=%d\n", s.name, s.addr, s.age);
//	fclose(fp);
//	free(p);
//	return 0;
//}
