#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;


class data
{
	public:	
		char gen,name[20],dob[11],date[11],in[6],out[6],add[50];
		int id,age; 

		void display();
		void getdata();
		void write();
		void read();
		void search();
		void del();
		void check();
		void mod();
}cus;

void data::getdata()
{
	cout<<"////////////////ZEUS RESTRO BAR///////////////\n";
	cout<<"\n Enter Name:- ";
	cin>>name;
	cout<<"\n Enter Aadhar ID Number:- ";
	cin>>id;
	cout<<"\n Enter Age:- ";
	cin>>age;
	cout<<"\n Enter Your Gender:- ";
	cin>>gen;
	cout<<"\n Enter Date Of Birth (dd-mm-yyyy):- ";
	cin>>dob;
	cout<<"\n Enter Address:- ";
	cin>>add;
	
}

void data::display()
{
	cout<<"////////////////ZEUS RESTRO BAR///////////////"<<endl<<endl;
	cout<<"\n \t \t *****Details of Customer*****";
	cout<<"\n Name:- "<<name;
	cout<<"\n Gender:- "<<gen;
	cout<<"\n Age:- "<<age;
	cout<<"\n Date Of Birth:- "<<dob;
	cout<<"\n Aadhar ID Number:- "<<id;
	cout<<"\n Address:- "<<add;
}

void data::check()
{
	if(age<18)
	{
		cout<<"\n\n\t\t\tSorry, Your age does not satistfy age criteria.";
		exit(0);
	}
	else
	{
		cout<<"\n\n\t\t\tWelcome to ZEUS RESTRO BAR!!!";
	}
}

void data::write()
{
	ofstream ofile;
	ofile.open("records.txt",ios::app);
	getdata();
	ofile.write((char*)&cus, sizeof(cus));
	ofile.close();
}

void data::read()
{
	ifstream ifile;
	ifile.open("records.txt");
	ifile.seekg(0,ios::beg);
	ifile.read((char*)&cus, sizeof(cus));
	while(ifile)
	{
		display();
		ifile.read((char*)&cus, sizeof(cus));
	}
	ifile.close();
}

void data::search()
{
	char sear[20];
	ifstream ifile("records.txt");
	cout<<"\n\t\t\t Enter name to be searched:- "<<endl;
	cin>>sear;
	ifile.seekg(0,ios::beg);
	ifile.read((char*)&cus, sizeof(cus));
	while(ifile)
	{
		if (strcmp(sear,name)==0)
		display();
		ifile.read((char*)&cus,sizeof(cus));
	}
}

void data::del()
{
	char dele[20];
	ifstream ifile;
	ifile.open("records.txt",ios::app);
	ofstream ofile;
	ofile.open("newrecords.txt",ios::app);
	cout<<"\nEnter the name to be deleted:- ";
	cin>>dele;
	ifile.seekg(0, ios::beg);
	ifile.read((char*)&cus, sizeof(cus));
	while(ifile)
	{
		if(strcmp(dele,name))
			ofile.write((char*)&cus, sizeof(cus));
		ifile.read((char*)&cus, sizeof(cus));
		cout<<"Entry Deleted.";
	}
	ifile.close();
	ofile.close();
	remove("records.txt");
	rename("newrecords.txt","records.txt");
}
void data::mod()
{
	char m[20];
	int ch;
	cout<<"Enter The Name You Want To Modify:-"<<endl;
	gets(m);
	fstream f;
	f.open("records.txt",ios::in|ios::out);
	f.seekg(0,ios::beg);
	f.read((char*)&cus, sizeof(cus));
	int a=f.tellg();
	while(!f.eof())
	{
		if(!strcmp(m,name))
		{
			puts("\n 1.Change Name. \n 2.Change Gender. \n 3.Change Date Of Birth. \n 4.Change Age \n 5.Change Aadhar ID. \n 6.Change Address. \n Enter Your Choice:- ");
			cin>>ch;
			switch(ch)
			{
				case 1:
					gets(name);
					break;
				case 2:
					cin>>gen;
					break;
				case 3:
					cin>>dob;
					break;
				case 4:
					cin>>age;
					check();
					break;
				case 5:
					cin>>id;
					break;
				case 6:
					cin>>add;
					break;
				default:
					cout<<"\n Invalid Input!!!";
			}
			f.seekg(a-sizeof(cus),ios::beg);
			f.write((char*)&cus, sizeof(cus));
		}
		f.read((char*)&cus, sizeof(cus));
		a=f.tellg();
	}
	f.close();
}
int main()
{
	int choice;
	char n;
	mainmenu:
	do
	{
		cout<<"\n\t////////////////ZEUS RESTRO BAR///////////////"<<endl<<endl;
		cout<<"\n\t\t\t 1.New Entry.";
		cout<<"\n\t\t\t 2.Delete Entry.";
		cout<<"\n\t\t\t 3.Search Entry.";
		cout<<"\n\t\t\t 4.View All Entrys.";
		cout<<"\n\t\t\t 5.Exit"<<endl;
		cout<<"Enter Your Choice:- ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cus.write();
				break;
			case 2:
				cus.del();
				break;
			case 3:
				cus.search();
				break;
			case 4:
				cus.read();
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"Invalid Input!!!"<<endl<<"Please try again";
		}
		cout<<"\n\n Go To Mainmenu??(y/n) \n";
		cin>>n;
	}while(n=='y');
		cout<<"Thank You For Coming!";
	return 0;
}

