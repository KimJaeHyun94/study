//#include<stdio.h>
//#include<stdlib.h>
//
//int main() {
//
//	FILE*fp1, *fp2;
//	char file1[100], file2[100];
//	char buffer[1024];
//	int count;
//	printf("첫 번째 파일 이름 :");
//	scanf("%s", file1);
//
//	printf("두 번째 파일 이름 :");
//	scanf("%s", file2);
//
//	if ((fp1 = fopen(file1, "rb")) == NULL)
//	{
//		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다\n");
//		exit(1);
//	}
//	if ((fp2 = fopen(file2, "ab")) == NULL)
//	{
//		fprintf(stderr, "추가을 위한 파일을 열 수 없습니다\n");
//		exit(1);
//	}
//	
//	while ((count == fread(buffer, sizeof(char), 1024, fp1)) > 0)
//	{
//		fwrite(buffer, sizeof(char), count, fp2);
//	}
//	fclose(fp1);
//	fclose(fp2);
//}

//#include<stdio.h>
//#include<ctype.h>
//#include<stdlib.h>
//
//int main() {
//	FILE*fp;
//	char fname[100];
//	unsigned char buffer[16];
//	int address = 0;
//	int i, bytes;
//
//	printf("원본 파일 이름 :");
//	scanf("%s", fname);
//
//	if ((fp = fopen(fname, "rb")) == NULL)
//	{
//		fprintf(stderr, "원본 파일 %s를 열 수 없습니다", fname);
//		exit(1);
//	}
//	while (1) {
//		bytes = fread(buffer, 1, 16, fp);
//		if (bytes <= 0) break;
//		printf("%08X:  ,", address);
//		for (i = 0; i < bytes; i++) {
//			printf("%02X", buffer[i]);
//		}
//		for (i = 0; i < bytes; i++) {
//			if (isprint(buffer[i]))putchar(buffer[i]);
//			else putchar('.');
//			address += bytes;
//			putchar('\n');
//		}
//
//	}
//	fclose(fp);
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//#define SIZE 100
//void init_table(int table[], int size);
//
//int main() {
//	int table[SIZE];
//	int n, data;
//	long pos;
//	FILE*fp = NULL;
//
//	init_table(table, SIZE);
//	if ((fp = fopen("sample.dat", "wb")) == NULL)
//	{
//		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다\n");
//		exit(1);
//	}
//	fwrite(table, sizeof(int), SIZE, fp);
//	fclose(fp);
//
//	if ((fp = fopen("sample.dat", "rb")) == NULL)
//	{
//		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다\n");
//		exit(1);
//	}
//	
//	while (1)
//	{
//		printf("파일에서의 위치를 입력하십시요(0에서 %d,종료 -1):", SIZE - 1);
//		scanf("%d", &n);
//		if (n == -1)break;
//		pos = (long)n * sizeof(int);
//		fseek(fp, pos, SEEK_SET);
//		fread(&data, sizeof(int), 1, fp);
//		printf("%d 위치의 값은 %d입니다\n", n, data);
//	}
//	fclose(fp);
//	return 0;	
//}
//
//void init_table(int table[], int size)
//{
//	for (int i = 0; i < size; i++)
//		table[i] = i*i;
//}

//#include<stdio.h>
//#include<string.h>
//#define SIZE 100
//
//typedef struct person {
//	char name[SIZE];
//	char address[SIZE];
//	char mobile[SIZE];
//	char desc[SIZE];
//}person;
//
//void menu();
//void update_record(FILE*fp);
//person get_record();
//void print_record(person data);
//void add_record(FILE*fp);
//void search_record(FILE*fp);
//
//int main(void)
//{
//	FILE*fp;
//	int select;
//	if ((fp = fopen("address.dat", "a+")) == NULL) {
//		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다\n");
//		exit(1);
//	}
//	while (1)
//	{
//		menu();
//		printf("메뉴를 선택하세요 :");
//		scanf("%d", &select);
//		switch (select) {
//		case 1:add_record(fp); break;
//		case 2:search_record(fp); break;
//		case 3:update_record(fp); break;
//		case 4:return 0;
//		}
//	}
//}
//
//person get_record(){
//	person data;
//	fflush(stdin);
//	printf("이름"); gets(data.name);
//	printf("주소"); gets(data.address);
//	printf("휴대폰"); gets(data.mobile);
//	printf("특징"); gets(data.desc);
//	return data;
//}
//
//void print_record(person data)
//{
//	printf("이름 : %s\n", data.name);
//	printf("주소 : %s\n", data.address);
//	printf("휴대폰 : %s\n", data.mobile);
//	printf("특징 : %s\n", data.desc);
//}
//void menu() {
//	printf("=================\n");
//	printf("1. 추가\n 2. 수정 \n 3. 검색\n 4. 종료\n");
//	printf("=================\n");
//}
//void add_record(FILE*fp){
//	person data;
//	data = get_record();
//	fseek(fp, 0, SEEK_END);
//	fwrite(&data, sizeof(data), 1, fp);
//}
//void search_record(FILE*fp) {
//	char name[SIZE];
//	person data;
//
//	fseek(fp, 0, SEEK_END);
//	fflush(stdin);
//	printf("탐색하고자 하는 사람의 이름");
//	gets(name);
//	while (!feof(fp)) {
//		fread(&data, sizeof(data), 1, fp);
//		if (strcmp(data.name, name) == 0) {
//			print_record(data);
//			return;
//		}
//	}
//	printf("탐색이 실패하였습니다.\n");
//}
//void update_record(FILE*fp) {
//	char name[SIZE];
//	person data;
//	FILE*fp1;
//
//	if ((fp1 = fopen("address.dat", "w")) == NULL) {
//		fprintf(stderr, "파일을 열 수 없습니다\n");
//		exit(1);
//	}
//	fseek(fp, 0, SEEK_SET);
//	fflush(stdin);
//	printf("수정하고자 하는 사람의 이름");
//	gets(name);
//	while (fread(&data, sizeof(data), 1, fp) == 1) {
//		if (strcmp(data.name, name) == 0) {
//			data = get_record();
//		}
//		fwrite(&data, sizeof(data), 1, fp1);
//	}
//	fclose(fp1);
//	fclose(fp);
//	remove("addres.dat");
//	rename("tmp.dat", "address.dat");
//	if ((fp = fopen("address.dat", "a+")) == NULL) {
//		fprintf(stderr, "파일 address.dat를 열 수없습니다");
//		exit(1);
//	}
//}
//

//#include<stdio.h>
//#include<stdlib.h>
//
//#define INC 100
//double*scores = NULL;
//
//int add_score(double new_score) {
//	
//	static int limit = 0;
//	static int count = 0;
//	if (count < limit) {
//		scores[count++] = new_score;
//	}
//	else {
//		int new_limit = limit + INC;
//		double*new_array = realloc(scores, new_limit * sizeof(double));
//		if (new_array == NULL) {
//			fprintf(stderr, "메모리 할당 오류\n");
//		}
//		else {
//			scores = new_array;
//			limit = new_limit;
//			scores[count++] = new_score;
//		}
//		return count;
//	}
//}
//
//int main() {
//	int size;
//	double value, total = 0;
//
//	size = 3;
//	for (int i = 0; i < size; i++) {
//		printf("성적:");
//		scanf("%lf", &value);
//		add_score(value);
//	}
//	for (int i = 0; i < size; i++) {
//		total += scores[i];
//	}
//	printf("평균 %f\n", total / size);
//	free(scores);
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define SIZE 50
//
//typedef struct NODE {
//	char title[SIZE];
//	int year;
//	struct NODE*link;
//}NODE;
//
//int main() {
//	NODE*list = NULL;
//	NODE*prev, *p, *next;
//	char buffer[SIZE];
//	int year;
//
//	while (1)
//	{
//		printf("책의 제목을 입력하시오 : (종료하려면 엔터)");
//		gets(buffer);
//		if (buffer[0] == '\0')
//			break;
//
//		p = (NODE *)malloc(sizeof(NODE));
//		strcpy(p->title, buffer);
//		printf("책의 출판 연도를 입력하시오 :");
//		gets(buffer);
//		year = atoi(buffer);
//		p->year = year;
//
//		if (list == NULL)
//			list = p;
//		else
//			prev->link = p;
//		p->link = NULL;
//		prev = p;
//	}
//	printf("\n");
//	p = list;
//
//	while (p != NULL) {
//		printf("책의 제목 :%s 출판 연도 :%d\n", p->title, p->year);
//		p = p->link;
//	}
//
//	p = list;
//	while (p != NULL)
//	{
//		next = p->link;
//		free(p);
//		p = next;
//	}
//}

//#include<stdio.h>
//
//typedef struct movie {
//	char title[100];
//	double rating;
//}MOVIE;
//MOVIE*movie;
//int read_file();
//void save_file();
//int size;
//int main() {
//
//	MOVIE*movie;
//	
//	printf("몇 편이나 저장하시겠습니까?");
//	scanf("%d", &size);
//
//	movie = (MOVIE*)malloc(sizeof(MOVIE)*size);
//	if (movie == NULL) {
//		printf("동적 메모리 전달 오류");
//		exit(1);
//	}
//	if (read_file() == 0) {
//		for (int i = 0; i < size; i++) {
//			printf("영화 제목");
//			fflush(stdin);
//			scanf("%s", &(movie[i].title));
//			printf("영화 평점");
//			scanf("%lf", &(movie[i].rating));
//		}
//	}
//	printf("====================\n");
//	printf("제목       평점");
//	printf("====================\n");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%s \t %f", movie[i].title, movie[i].rating);
//	}
//	save_file();
//	free(movie);
//}
//void save_file() {
//	FILE*fp;
//
//	if ((fp = fopen("movie.dat", "w")) == NULL){
//	fprintf(stderr, "파일을 열 수 없습니다");
//	return;
//}
//
//	if (movie!= NULL)
//    fwrite(movie, sizeof(MOVIE), size, fp);
//    fclose(fp);
//}
//
//int read_file() {
//	FILE*fp;
//	if ((fp = fopen("movie.dat", "r")) == NULL)
//	{return 0;
//}
//	if (movie != NULL)
//		fread(movie, sizeof(MOVIE), size, fp);
//	return 1;
//}

//#include<stdio.h>
//#include<string.h>
//#define S_SIZE 5
//typedef struct subject {
//	int kor, eng, mat, sum;
//}subject;
//
//typedef struct student {
//	char name[20];
//	subject sub;
//}student;
//void Point(student *s);
//void PointSum(student *s);
//void intenger(student *s);
//
//int main() {
//	student sar[S_SIZE];
//	intenger(sar);
//	Point(sar);
//}
//void PointSum(student *s) {
//	s->sub.sum = s->sub.kor + s->sub.eng + s->sub.mat;
//}
//void intenger(student *s) {
//	for (int i = 0; i < S_SIZE; i++)
//	{
//		printf("이름 : ");
//		scanf("%s", &(s[i].name));
//		printf("국어, 영어, 수학 : ");
//		scanf("%d %d %d", &s[i].sub.kor, &s[i].sub.eng, &s[i].sub.mat);
//	}
//}
//void Point(student *s) {
//	
//	student p;
//	
//	int i;
//	p = s[0];
//	for (i = 0; i < S_SIZE; i++)
//	{
//		PointSum(&s[i]);
//		if (p.sub.sum < s[i].sub.sum)
//			p = s[i];
//	}
//	printf("평균이 가장 높은 학생은 %s 총점은 %d\n",p.name,p.sub.sum);
//}
//
//#include<stdio.h>
//#define S_SIZE 2
//typedef struct subject {
//	int kor, eng, sum;
//}subject;
//typedef struct student {
//	char name[20];
//	subject sub;
//}student;
////학생 한명의 정적 출력하는 함수
//void ShowInfo(student s) {
//	printf("%s의 성적\n", s.name);
//	printf("국어 : %d, 영어 : %d, 총점 : %d\n", s.sub.kor, s.sub.eng, s.sub.sum);
//}
////학생 한명의 총점 구하는 함수
//void Sum(student *ps) {
//	ps->sub.sum = (*ps).sub.kor + ps->sub.eng;
//}
//student Total(student s) {
//	s.sub.sum = s.sub.kor + s.sub.eng;
//	return s;
//}
//void PointSum(student *p);   //학생배열의 총점 구하는 함수 
//void PointShow(student *p);   //학생배열의 데이터 출력하는 함수
//int main() {
//	//student chopa = { "초파",89,95 };
//	//ShowInfo(chopa);
//	///*chopa=Total(chopa);*/     //리턴받는 함수
//	//Sum(&chopa);                //메인 함수값을 직접 변화시키는 함수
//	//ShowInfo(chopa);
//
//	student sar[S_SIZE] = { { "빌",88,89 },{ "마크",98,95 } };
//	PointSum(sar);
//	PointShow(sar);
//}
//void PointSum(student *p) {
//	for (int i = 0; i < S_SIZE; i++) {
//		Sum(&p[i
//		
//		]);       //Sum(p + i);
//	}
//
//
//}
//void PointShow(student *p) {
//	for (int i = 0; i < S_SIZE; i++) {
//		ShowInfo(p[i]);
//	}
//}

//#include<stdio.h>
//
//void intenger(char(*a)[10]);
//void choco(char(*a)[10]);
//int main() {
//	char s[5][10];
//	intenger(s);
//	choco(s);
//	return 0;
//
//
//}
//void intenger(char (*a)[10])
//{
//	for (int i = 0; i < 5; i++)
//	{
//		printf("문자를 입력하시오 :");
//		fflush(stdout);
//		scanf("%s", a[i]);
//	}
//}
//void choco(char(*a)[10]) {
//	for (int i = 0; i < 5; i++) {
//		printf("%s\n", a[i]);
//	}
//}

//#include<stdio.h>
//#include<math.h>
//#define ESP 0.001
//double get_root(double(*f)(double), double x0, double x1);
//double coef[4];
//
//double func(double x)
//{
//	return coef[3] * (x)*(x)*(x) + coef[2] *(x)*(x) + coef[1]*(x) + coef[0];
//}
//
//int main() {
//	double x0, x1;
//	double r;
//
//	printf("3차항의 계수를 입력하시오 :");
//	scanf("%lf", &coef[3]);
//	printf("2차항의 계수를 입력하시오 :");
//	scanf("%lf", &coef[2]);
//	printf("1차항의 계수를 입력하시오 :");
//	scanf("%lf", &coef[1]);
//	printf("상수의 계수를 입력하시오 :");
//	scanf("%lf", &coef[0]);
//
//	printf("a의 값을 입력하시오 :");
//	scanf("%lf", &x1);
//
//	printf("b의 값을 입력하시오 :");
//	scanf("%lf", &x0);
//
//	r = get_root(func, x0, x1);
//	printf("값은 %f\n", r);
//}
//
//double get_root(double(*f)(double), double x0, double x1)
//{
//	double x2;
//	int i = 1;
//	double f1, f2, f0;
//
//	do {
//		x2 = (x0 + x1) / 2;
//		f0 = f(x0);
//		f1 = f(x1);
//		f2 = f(x2);
//		if (f0*f2 < 0) {
//			x1 = x2;
//		}
//		else {
//			x0 = x2;
//		}
//		i++;
//	} while (fabs(f2) > ESP);
//		return x2;
//}

//#include<stdio.h>
//#define SIZE 5
//
//typedef struct student {
//	int number;
//	char name[20];
//	double grade;
//}STUDENT;
//
//void intenger(STUDENT *a);
//void get_mat_stu(STUDENT *a,int size);
//int main() {
//	STUDENT list[SIZE];
//	intenger(list);
//	int size = sizeof(list) / sizeof(list[0]);
//	get_mat_stu(list,size);
//}
//
//void intenger(STUDENT *a) {
//	for (int i = 0; i < SIZE; i++) {
//		printf("이름을 입력하세용 :");
//		scanf("%s", a[i].name);
//		printf("학번을 입력하세용 :");
//		scanf("%d", &a[i].number);
//		printf("학점을 입력하세용 :");
//		scanf("%lf", &a[i].grade);
//	}
//}
//void get_mat_stu(STUDENT *a,int size) {
//	STUDENT s;
//	for (int i = 0; i < size; i++)
//	{
//		if (s.grade < a[i].grade)
//			s = a[i];
//	}
//	printf("평점이 가장 높은 학생은 %s 학번은 %d 학점은 %f", s.name, s.number, s.grade);
//}

//#include<stdio.h>
//typedef struct movie{
//	char title[100];
//    int year;
//}MOVIE;
//typedef struct NODE {
//	MOVIE movie;
//	struct NODE*link;
//}NODE;
//MOVIE add();
//void choco(NODE*plist);
//NODE*insert(NODE*plist, NODE*pprev, MOVIE item) {
//	NODE*pnew = NULL;
//
//	if (!(pnew = (NODE*)malloc(sizeof(NODE))))
//	{
//		printf("메모리 동적 할당 오류\n");
//		exit(1);
//	}
//	pnew->movie = item;
//	if (pprev == NULL) {
//		pnew->link = plist;
//		plist = pnew;
//	}
//	else
//	{
//		pnew->link = pprev->link;
//		pprev->link = pnew;
//	}
//	return plist;
//}
//void destroy_nodes(NODE *plist)
//{
//	NODE *temp;
//	while (plist)
//	{
//		temp = plist;
//		plist = plist->link;
//		free(temp);
//	}
//}
//int main() {
//	int number;
//	NODE*plist = NULL;
//	MOVIE movie;
//	number = 0;
//	while (number!=3) {
//
//		printf("-----------------------\n");
//		printf("1.영화 정보 추가\n");
//		printf("2.영화 정도 출력\n");
//		printf("3.종료\n");
//		printf("-----------------------\n");
//	
//		printf("번호를 선택하시오 :");
//		scanf("%d", &number);
//		
//		switch(number)
//		{
//		case 1:
//		{
//			movie = add();
//			plist = insert(plist, NULL, movie);
//			break;
//			
//		}
//		case 2:
//		{
//			choco(plist);
//			break;
//		}
//		case 3:
//			destroy_nodes(plist);
//		break;
//		}	
//	}
//}
//MOVIE add() {
//
//	MOVIE k;
//	printf("영화의 제목을 입력하시오 :");
//	fflush(stdin);
//	scanf("%s", &k.title);
//	printf("영화의 개봉연도를 입력하시오 :");
//	scanf("%d", &k.year);
//	return k;
//}
//
//void choco(NODE*plist) {
//	NODE *p;
//	for (p = plist; p; p=p->link) {
//		printf("--------------------\n");
//		printf("제목 : %s\n", p->movie.title);
//		printf("개봉 연도 :%d\n", p->movie.year);
//	}
//	printf("--------------------\n");
//}








