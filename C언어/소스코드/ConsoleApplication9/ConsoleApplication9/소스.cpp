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
		cout<<"1. data �Է� "<<endl;
		cout<<"2. data ��� "<<endl;
		cout<<"3. �� �� "<<endl;
		cout<<"���� �Է� >>> ";
		cin>>sel;
		try{
			if(sel>3||sel<1)
				throw "�߸� �Է� �ٽ�";
		}
		catch(char * str){
			cout<<str<<endl;
			system("pause");system("cls");
			continue;
		}
		switch(sel){
		case 1:cout << "data �Է� : "; cin >> data; cout << "�Է� �Ϸ�" << endl; getchar(); set_data(data); break;
			case 2:cout<<"�Է� data : "<<get_data()<<endl;break;
			case 3:return ;
		}
		system("pause");system("cls");
	}
}
void main(){
	Data data;
	data.display();
}




