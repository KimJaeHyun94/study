#include<iostream>
#include<cstdlib>
using namespace std;
class Data{
	char data[200];
public:
	Data(){for(int i=0;i<200;i++)	data[i]=NULL; }
	void set_data(char* da){  strcpy(data,da);	}
	char * get_data(){	return data;}
	void display();
};
void Data::display(){
	int sel;
	char data[200];
	while(true){
		cout<<"1. data 입력 "<<endl;
		cout<<"2. data 출력 "<<endl;
		cout<<"3. 종 료 "<<endl;
		cout<<"숫자 입력 >>> ";
		cin>>sel;
		try{
			if(sel>3||sel<1)
				throw "잘못 입력 다시";
		}
		catch(char * str){
			cout<<str<<endl;
			system("pause");system("cls");
			continue;
		}
		switch(sel){
		case 1:cout << "data 입력 : "; cin >> data; cout << "입력 완료" << endl; getchar(); set_data(data); break;
			case 2:cout<<"입력 data : "<<get_data()<<endl;break;
			case 3:return ;
		}
		system("pause");system("cls");
	}
}
void main(){
	Data data;
	data.display();
}




