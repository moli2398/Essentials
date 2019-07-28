#include <time.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
int chec;
int flag=0;
void uwrite();
void entry();
void signin();
void check();
void menu();
void fun();
void mr2();

class user{
			private:
				char mob[100];	
				char pas[100];
			public:
				void signup()
				{	
					cout<<"Sign Up:";
					cout<<"\nEnter your User Name (No Spaces): ";
					cin>>mob;					
					char temp[100];
					strcpy(temp,mob);
					check();
					if(chec==0)
					{
						cout<<"\nEnter your Password (No Spaces):";
						cin>>pas;
						strcpy(mob,temp);
						uwrite();
					}
					else
					{
						getch();
						system("cls");
						signin();
					}
				}
				char* mobret()
				{
					return mob;
				}
				char* pasret()
				{
					return pas;
				}
			}u;
			
//Admin Code Starts

void viewacc();
void startup();

void adminmenu()
{
	system("cls");
	int choice1;
	cout<<"\n1. View All Account(s)";
	cout<<"\n2. Log Out";
	cout<<"\n\nEnter Choice: ";
	here120:
	cin>>choice1;
	if(choice1==1)
		viewacc();
	else if(choice1==2)
	{	
		system("cls");
		startup();
	}
	else
	{	
		cout<<"Invalid Choice. Enter again: ";
		goto here120;
	}
}

void viewacc()
{
	system("cls");
	ifstream fin;
	fin.open("user1234.dat",ios::in);
	while(fin.read((char*)&u,sizeof(u)))
	{
		cout<<"User Name: ";
		cout<<u.mobret()<<"\n";
		cout<<"Password: ";
		cout<<u.pasret()<<"\n";
		cout<<endl;
	}
	fin.close();
	getch();
}

//Admin code ends

void check()
{
	char temp[100];
	strcpy(temp,u.mobret());
	ifstream use;
	use.open("user1234.dat",ios::in);
	while(!use.eof())
		{
			use.read((char*)&u,sizeof(u));
			if(strcmp(u.mobret(),temp)==0)
			{
				cout<<"User already exist. Proceed to SignIn.\n";
				chec=1;
				goto here1;
			}
			else chec=0;
		}
	here1:;
	use.close();
}

void uwrite()
{	
	char temp[100];
	strcpy(temp,u.mobret());
	ofstream users; 
	ofstream puser1,puser2,puser3,puser4,puser5;
	users.open("user1234.dat",ios::app);
	puser1.open(strcat(temp,"c"),ios::out);
	strcpy(temp,u.mobret());
	puser2.open(strcat(temp,"mn"),ios::out);
	strcpy(temp,u.mobret());
	puser3.open(strcat(temp,"n"),ios::out);
	strcpy(temp,u.mobret());
	puser4.open(strcat(temp,"s"),ios::out);
	strcpy(temp,u.mobret());
	puser5.open(strcat(temp,"mo"),ios::out);
	users.write((char*)&u,sizeof(u));
	cout<<"\nSign Up Successful! Proceed to SignIn.\n";
	getch();
	system("cls");
	users.close();
	puser1.close();
	puser2.close();
	puser3.close();
	puser4.close();
	puser5.close();
	signin();
}

int choice2;
char mobi[100];
char pass[100];

void authenticate()
{
	ifstream users;
	users.open("user1234.dat",ios::in);
	while(!users.eof())
		{
			users.read((char*)&u,sizeof(u));
			if(strcmp(mobi,u.mobret())==0 && strcmp(u.pasret(),pass)==0)
				{
					cout<<"Login Successful! ";
					flag=1;
					goto here;	
				}
			if(strcmp(mobi,"admin")==0 && strcmp(pass,"admin")==0)
				adminmenu();
		}
	int choice;
	cout<<"Login Failed! Please check the User Name or Password\n";
	cout<<"1. Try Again\n";
	cout<<"2. Sign Up\n";
	cout<<"Enter Choice: ";
	here5:
	cin>>choice;
	if(choice==1)
	{
		system("cls");
		signin();
	}
	else if(choice==2)
	{
		system("cls");
		u.signup();
	}
	else
	{
		cout<<"Invalid Choice. Enter Again: ";
		goto here5;
	}
	here:;
	getch();
	entry();
}

void signin()
{	
	cout<<"Sign In:";
	cout<<"\nUser Name: ";
	cin>>mobi;
	cout<<"\nPassword:";
	cin>>pass;
	authenticate();
}

void entry()
{
	if(flag==1)
	menu();
	else
	signin();	
}

void credits()
{
	system("cls");
	cout<<"Developed in Borland-Dev-C++ 5.11 by:\n1. Anmol Garg\n\n";
	exit();
}

void startup()
{	
	cout<<"\t\t\t\t\t\tWelcome";
	cout<<"\n1. Sign In";
	cout<<"\n2. Sign Up";
	cout<<"\n3. Exit";
	cout<<"\nEnter your choice:";
	here8:
	cin>>choice2;
	if(choice2==1)
		{
			system("cls");		
			signin();
		}	
	else if(choice2==2)
	{
		system("cls");
		u.signup();
	}
	else if(choice2==3)
		credits();
	else
		{
			cout<<"Invalid Choice! Enter Again: ";
			goto here8;
		}
}

char* cloc()
{
	time_t rawtime;
	struct tm * timeinfo;
  	time ( &rawtime );
 	timeinfo = localtime ( &rawtime );
 	return asctime(timeinfo);
}

void mr1()
{
	system("cls");
	char j[100];
	unsigned int random;
	time_t t;
	random=(unsigned) time(&t);
	srand(random);
	cout<<"\t\t\t\t\t\t\t   Mind Reader\n\n";
	for(int i=0;i<100;i++)
		if(i<9)
			cout<<" "<<i+1<<" - "<<(j[i]=rand())<<"\t";
		else if ((i+1)%9==0)
		    cout<<i+1<<" - "<<j[8]<<"\t";
		else
			cout<<i+1<<" - "<<(j[i]=rand())<<"\t";
	cout<<"\n\n\t\t\t\t\t\t   INSTRUCTIONS\n\nChoose any two digit number. Add together both the digits. Subtract the number you got after adding from the original number. The number you get finally is the MAGIC NUMBER. See the SYMBOL corresponding to your MAGIC NUMBER in the chart above and remember it.For Example - If your number is 24. Add 2+4=6. Subtract 24-6=18. Your MAGIC NUMBER is 18.";
	getch();
	int choice;
	cout<<"\n\nYour symbol is: "<<j[8]<<"\n SHOCKED? Press 1 to Play Again or 0 to Go Back: ";here24: cin>>choice;
	if(choice==1)
	mr1();
	else if(choice==0)
	fun();
	else
	cout<<"Invalid Choice. Enter Again: ";
	goto here24;
	
}

//Game 2 Code Starts
int card=0,total=0;
int num[] = {0,1,2,4,8,16,32};
int choice;


void yes()
{
	total = total + num[card];
}

void display()
{
	void yes();
	void next();
	if(card==1)
		cout<<"        CARD  ONE        \n  1  3  5  7  9 11 13 15 \n 17 19 21 23 25 27 29 31 \n 33 35 37 39 41 43 45 47 \n 49 51 53 55 57 59 61 63";
	else if(card==2)
		cout<<"       CARD  TWO        \n  2  3  6  7 10 11 14 15 \n 18 19 22 23 26 27 30 31 \n 34 35 38 39 42 43 46 47 \n 50 51 54 55 58 59 62 63";
	else if(card==3)
		cout<<"       CARD  THREE       \n  4  5  6  7 12 13 14 15 \n 20 21 22 23 28 29 30 31 \n 36 37 38 39 44 45 46 47 \n 52 53 54 55 60 61 62 63";
	else if(card==4)
		cout<<"        CARD FOUR        \n  8  9 10 11 12 13 14 15 \n 24 25 26 27 28 29 30 31 \n 40 41 42 43 44 45 46 47 \n 56 57 58 59 60 61 62 63";
	else if(card==5)
		cout<<"        CARD FIVE        \n 16 17 18 19 20 21 22 23 \n 24 25 26 27 28 29 30 31 \n 48 49 50 51 52 53 54 55 \n 56 57 58 59 60 61 62 63";
	else if(card==6)
		cout<<"        CARD  SIX        \n 32 33 34 35 36 37 38 39 \n 40 41 42 43 44 45 46 47 \n 48 49 50 51 52 53 54 55 \n 56 57 58 59 60 61 62 63";
	cout<<"\n\nPress 1 if your number is present in this card or Press 0 if it's not: ";
	here98: 
	cin>>choice;
	cout<<"\n";
	if(choice==1)
		yes();
	else if(choice==0)
		next();
	else
	{
		cout<<"Invalid Choice. Enter Again: ";
		goto here98;
	}
	next();
}

void fin()
{
	card=0;
	cout<<"Your Number is: "<<total;
	total=0;
	cout<<"\nAmazed? Press 1 to Play Again or Press 0 to Go Back: ";
	int choice;
	here97:
	cin>>choice;
	if(choice==1)
		mr2();
	else if(choice==0)
		fun();
	else 
		cout<<"Invalid Choice. Enter Again: ";
	goto here97;
}

void next()
{
	card++;
	if(card == 7)
		fin();
	else 
		display();
}

void mr2()
{	
	system("cls");
	cout<<"\t\t\t\t\t\t    >>INSTRUCTIONS<<\n\n";
	cout<<"Choose any number from 1-63 in your mind. Now, 6 cards will be shown to you each having a set of numbers. Press 1 if the card contains your number else press 0. See the Magic!";
	getch();
	system("cls");
	next();
}
//Game 2 Code Ends

void fun()
{
	system("cls");	
	int choice1;
	cout<<"1. GAME I";
	cout<<"\n2. GAME II";
	cout<<"\n3. Exit";
	cout<<"\n\nEnter choice: ";
	here10:
	cin>>choice1;
	if(choice1==1)
		mr1();
	else if(choice1==2)
		mr2();
	else if(choice1==3)
		menu();
	else
		cout<<"Invalid Choice. Enter Again: ";
		goto here10;
}

void calc()
{
	double num1,num2;
    char operation,redo;
    cout<<"Calculator"<<endl;
    do
    {
    	cout<<" Please enter an operation which you like to calculate (+,-,*,/) \nOr Press 0 to go Back: ";
    	cin>>operation ;
 		if(operation=='0')
 			menu();
    	cout<<endl<<endl;
     	cout<<" Please enter two numbers to apply your requested operation(";
    	cout<<operation<<"):"<<endl<<"1st num:";
    	cin>>num1;
    	cout<<"2nd num:" ;
    	cin>>num2;
    	cout<<endl;
    	switch (operation)
    	{
     		case'+':            
            	cout<<"The addition of two numbers ("<<num1<<","<<num2<<"):";
            	cout<<num1+num2<<endl;
            	break; 
     		case'-':
            	cout<<"The substraction of two numbers ("<<num1<<","<<num2<<"):";
            	cout<<num1-num2<<endl;
            	break;
      		case'*':
            	cout<<"The multiplication of two numbers ("<<num1<<","<<num2<<"):";
            	cout<<num1*num2<<endl;
            	break;
      		case'/':
            	cout<<"The division of two numbers ("<<num1<<","<<num2<<"):";
             	if(num2==0)
             		cout<<"not valid"<<endl;
             	cout<<(num1/num2)<<endl;
            	break;
      		default:
            	cout<<"unknown command"<<endl;
      	}         
        cout<<"enter y or Y to continue:";
        cin>>redo;
        cout<<endl<<endl;
    }
    while(redo=='y'||redo=='Y');
    menu();
}

void cont();
void note();
void msg();
void appoint();

void menu()
{
	system("cls");
	int choice1;
	cout<<"\t\t\t\t\t\t    >>ESSENTIALS<<\n\n";
	cout<<"Welcome: "<<mobi<<"\t\t\t\t\t\t\t\t\t"<<cloc();
	cout<<"\n1. Appointments & Schedule";
	cout<<"\n2. Calculator";
	cout<<"\n3. Contacts";
	cout<<"\n4. FunBox";
	cout<<"\n5. Messages";
	cout<<"\n6. Notes";
	cout<<"\n7. Log Out";
	cout<<"\n\nEnter Choice: ";
	here12:
	cin>>choice1;
	if(choice1==1)
		appoint();
	else if(choice1==2)
	{
		system("cls");
		calc();
	}
	else if(choice1==3)
		cont();
	else if(choice1==4)
		fun();
	else if(choice1==5)
		msg();
	else if(choice1==6)
		note();
	else if(choice1==7)
	{
		system("cls");
		startup();
	}
	else
	{	
		cout<<"Invalid Choice. Enter again: ";
		goto here12;
	}
}
//Contacts Code Start
class contact{
				private:
					char name[100];
					char phone[100];
					char other[256];
				public:
					void input()
					{
						cout<<"Enter Contact Name: ";
						cin.ignore();
						gets(name);
						cout<<"Enter Contact Number: ";
						gets(phone);
						cout<<"Enter any other detail you want to add: ";
						gets(other);
					}
					char* nameret()
					{
						return name;
					}
					char* phoneret()
					{
						return phone;
					}
					char* otherret()
					{
						return other;
					}
}c;

void contadd();
void contedit();
void contdel();
void contsearch();
void contview();

void cont()
{	
	system("cls");
	cout<<"1. Add New Contact";
	cout<<"\n2. Edit Existing Contact";
	cout<<"\n3. Delete Existing Contact";
	cout<<"\n4. Search Contact";
	cout<<"\n5. View All Contact(s)";
	cout<<"\n6. Go Back";
	cout<<"\nEnter choice: ";
	int choice;
	here890:
	cin>>choice;
	if(choice==1)
	contadd();
	else if(choice==2)
	contedit();
	else if(choice==3)
	contdel();
	else if(choice==4)
	contsearch();
	else if(choice==5)
	contview();
	else if(choice==6)
	menu();
	else
	{
		cout<<"Invalid Choice. Enter Again: ";
		goto here890;
	}
}
	
	
void contadd()
{	
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"c");
	c.input();
	char tempn[100];
	strcpy(tempn,c.nameret());
	char tempp[100];
	strcpy(tempp,c.phoneret());
	char tempo[256];
	strcpy(tempo,c.otherret());
	ofstream fout;
	fout.open(temp,ios::app);
	ifstream fin;
	fin.open(temp,ios::in);
	int flag=0;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(strcmp(tempn,c.nameret())==0)
		{
			cout<<"A contact with same name already exist. Please check: ";
			cout<<"\nName: ";
				puts(c.nameret());
				cout<<"Phone Number: ";
				puts(c.phoneret());
				cout<<"Other Details:";
				puts(c.otherret());
				flag=1;
		}
		else if(strcmp(tempp,c.phoneret())==0)
		{
			cout<<"\n\nA contact with same number already exist. Please check: ";
			cout<<"\n\nName: ";
				puts(c.nameret());
				cout<<"Phone Number: ";
				puts(c.phoneret());
				cout<<"Other Details:";
				puts(c.otherret());
				flag=1;
		}
	}
	fin.close();
	strcpy(c.nameret(),tempn);
	strcpy(c.phoneret(),tempp);
	strcpy(c.otherret(),tempo);
	if(flag==0)
	{
	fout.write((char*)&c,sizeof(c));
	cout<<"\nContact Successfully Added.\n";
	fout.close();
	}
	getch();
	cont();
}

void contedit()
{
	system("cls");	
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"c");
	char name[100];
	here102:
	cout<<"Enter name of contact to be edited: ";
	cin.ignore();
	gets(name);
	fstream fp;
	int found=0;
	fp.open(temp,ios::in|ios::out);
	while(!fp.eof() && found==0)
	{
	fp.read((char*)&c,sizeof(c));	
	if(strcmp(c.nameret(),name)==0)
	{
	cout<<"\nEnter The New Details: \n";
	c.input();
	int pos=(-1)*sizeof(c);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&c,sizeof(c));
	found=1;
	}
	}
		if(found==0)
		{
			cout<<"\nNo Such Contact Found. Press 1 to Try Again or Press 0 to Go Back.";
			int choice;
			here101:
			cin>>choice;
			if(choice==1)
				goto here102;
			else if(choice==0)
				cont();
			else
			{
				cout<<"Invalid Choice. Enter Again: ";
				goto here101;
			}
		}
		fp.close();
		cout<<"\n\nContact Successfully Edited.";
		getch();
		cont();
}

void contdel()
{	
	system("cls");
	char temp[100];
	int flag=0;
	strcpy(temp,mobi);
	strcat(temp,"c");
	char name[100];
	here104:
	cout<<"Enter name of contact to be deleted: ";
	cin.ignore();
	gets(name);
	ifstream fp1;
	fp1.open(temp,ios::in);
	while(fp1.read((char*)&c,sizeof(c)))
		if(strcmp(name,c.nameret())==0)
			flag=1;
	fp1.close();
	ifstream fp3;
	fp3.open(temp,ios::in);
	ofstream fp2;
	fp2.open("Temp",ios::out);
	while(fp3.read((char*)&c,sizeof(c)))
		if(strcmp(name,c.nameret())!=0)
			fp2.write((char*)&c,sizeof(c));
	if(flag==1)
	cout<<"\nContact Successfully Deleted.\n";
	fp3.close();
	fp2.close();
	remove(temp);
	rename("Temp",temp);
		if(flag==0)
		{
			cout<<"No Such Contact Found. Press 1 to Try Again or Press 0 to Go Back.";
			int choice;
			here103:
			cin>>choice;
			if(choice==1)
				goto here104;
			else if(choice==0)
				cont();
	 		else
			{
				cout<<"Invalid Choice. Enter Again: ";
				goto here103;
			}
		}
	getch();
	cont();
}

void contsearch()
{
	system("cls");
	char temp[100];
	int flag=0;
	strcpy(temp,mobi);
	strcat(temp,"c");
	char name[100];
	char phone[100];
	int choice;
	here567:
	cout<<"\n1. Search by Name";
	cout<<"\n2. Search by Number";
	cout<<"\nEnter Choice: ";
	here568:
	cin>>choice;
	if(choice==1)
	{
		char name[100];
		cout<<"Enter the Name of the Contact: ";
		cin.ignore();
		gets(name);
		ifstream fp1;
		fp1.open(temp,ios::in);
		int flag=0;
		while(fp1.read((char*)&c,sizeof(c)))
		{
			if(strcmp(name,c.nameret())==0)
			{
				cout<<"Name: ";
				puts(c.nameret());
				cout<<"\nPhone Number: ";
				puts(c.phoneret());
				cout<<"\nOther Details:";
				puts(c.otherret());
				flag=1;
			}
			
		}
		fp1.close();
		if(flag==0)
			{
				cout<<"No such contact found. Press 1 to try again or Press 0 to go back: ";
				here678:
				int choice;
				cin>>choice;
				if(choice==1)
				{
					goto here567;
				}
				else if(choice==0)
				{
					cont();
				}
				else
				{
					cout<<"Invalid Choice. Enter Again: ";
					goto here678;
				}
			}
			getch();
			cont();
	}
	else if(choice==2)
	{
		char phone[100];
		cout<<"Enter the Phone Number of the Contact: ";
		cin.ignore();
		gets(phone);
		ifstream fp1;
		fp1.open(temp,ios::in);
		int flag=0;
		while(fp1.read((char*)&c,sizeof(c)))
		{
			if(strcmp(phone,c.phoneret())==0)
			{
				cout<<"Name: ";
				puts(c.nameret());
				cout<<"\nPhone Number: ";
				puts(c.phoneret());
				cout<<"\nOther Details:";
				puts(c.otherret());
				flag=1;
			}
			
		}
		fp1.close();
		if(flag==0)
			{
				cout<<"No such contact found. Press 1 to try again or Press 0 to go back: ";
				here679:
				int choice;
				cin>>choice;
				if(choice==1)
				{
					goto here567;
				}
				else if(choice==0)
				{
					cont();
				}
				else
				{
					cout<<"Invalid Choice. Enter Again: ";
					goto here679;
				}
			}
	}
	else
	{
		cout<<"Invalid Choice. Enter Again: ";
		goto here568;
	}
}

void contview()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"c");
	ifstream fp1;
	fp1.open(temp,ios::in);
	while(fp1.read((char*)&c,sizeof(c)))
	{
	cout<<"Name: ";
	puts(c.nameret());
	cout<<"Phone Number: ";
	puts(c.phoneret());
	cout<<"Other Details:";
	puts(c.otherret());
	cout<<endl;
	}
	getch();
	cont();
}

//Contacts code ends

//Notes code starts

class notes
{
	private:
		char note[1000];
	public:
		void input()
		{
			cout<<"Enter Note: "<<endl;
			cin.ignore();
			gets(note);
		}
		char* noteret()
		{
			return note;
		}
}n;

void noteadd();
void noteedit();
void notedel();
void noteview();

void note()
{	
	system("cls");
	cout<<"1. Add New Note";
	cout<<"\n2. Edit Existing Note";
	cout<<"\n3. Delete Existing Note";
	cout<<"\n4. View All Note(s)";
	cout<<"\n5. Go Back";
	cout<<"\nEnter choice: ";
	int choice;
	here899:
	cin>>choice;
	if(choice==1)
	noteadd();
	else if(choice==2)
	noteedit();
	else if(choice==3)
	notedel();
	else if(choice==4)
	noteview();
	else if(choice==5)
	menu();
	else
	{
		cout<<"Invalid Choice. Enter Again: ";
		goto here899;
	}
}

void noteadd()
{	
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	n.input();
	ofstream fout;
	fout.open(temp,ios::app);
	fout.write((char*)&n,sizeof(n));
	cout<<"\nNote Successfully Added.\n";
	fout.close();
	getch();
	note();
}

void noteedit()
{	
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	fstream fp;
	fp.open(temp,ios::in|ios::out);
	int count=1;
	while(fp.read((char*)&n,sizeof(n)))
	{
		cout<<count<<". ";
		puts(n.noteret());
		count++;	
	}
	fp.close();
	cout<<"Enter note number for the note to be edited: ";
	int choice;
	here111:
	cin>>choice;
	if(choice>=count)
	{
		cout<<"Invalid number. Enter again: ";
		goto here111;
	}
	else
	{	
		fstream fp1;
		fp1.open(temp,ios::in|ios::out);
		cout<<"Enter New Note:\n";
		n.input();
		int pos=(1*(choice-1)*sizeof(n));
		fp1.seekp(pos,ios::beg);
		fp1.write((char*)&n,sizeof(n));
		cout<<"Note Successfully Edited\n";
		fp1.close();
	}
	getch();
	note();
}

void notedel()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	ifstream fp;
	fp.open(temp,ios::in);
	int count=1;
	while(fp.read((char*)&n,sizeof(n)))
	{
		cout<<count<<". ";
		puts(n.noteret());
		count++;	
	}
	fp.close();
	cout<<"Enter note number for the note to be deleted: ";
	int choice;
	here121:
	cin>>choice;
	if(choice>=count)
	{
		cout<<"Invalid number. Enter again: ";
		goto here121;
	}
	else
	{	
		ofstream fout;
		fout.open("Temp",ios::out);
		ifstream fin;
		fin.open(temp,ios::in);
		long int pos=(choice*sizeof(n));
		while(fin.read((char*)&n,sizeof(n)))
		{
			int p=fin.tellg();
			if(p!=pos)
				fout.write((char*)&n,sizeof(n));
		}
		fin.close();
		fout.close();
		remove(temp);
		rename("Temp",temp);
		cout<<"Note Successfully Deleted.\n";
	}
	getch();
	note();
}

void noteview()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"n");
	ifstream fp;
	fp.open(temp,ios::in);
	int count=1;
	while(fp.read((char*)&n,sizeof(n)))
	{
		cout<<count<<". ";
		puts(n.noteret());
		count++;	 
	}
	fp.close();
	getch();
	note();
}

//Note code Ends

//Messaging code starts

class message{
	private:
		char message[256];
		char sender[100];	
	public:
		char* messageret()
		{
			return message;
		}	
		char* senderret()
		{
			return sender;
		}
}m;

void msgnew();
void msgchk();
void msgold();
void msgdel();

void msg()
{
	system("cls");
	cout<<"1. Send New Message";
	cout<<"\n2. Check For New Message(s)";
	cout<<"\n3. View Old Message(s)";
	cout<<"\n4. Delete Old Message(s)";
	cout<<"\n5. Go Back";
	cout<<"\nEnter choice: ";
	int choice;
	here897:
	cin>>choice;
	if(choice==1)
	msgnew();
	else if(choice==2)
	msgchk();
	else if(choice==3)
	msgold();
	else if(choice==4)
	msgdel();
	else if(choice==5)
	menu();
	else
	{
		cout<<"Invalid Choice. Enter Again: ";
		goto here897;
	}
}

void msgnew()
{	
	system("cls");
	char name[100];
	cout<<"Enter Recepient User Name: ";
	here1234:
	cin.ignore();
	gets(name);
	ifstream fin;
	fin.open("user1234.dat",ios::in);
	int flag=0;
	while(fin.read((char*)&u,sizeof(u)))
	{
		if(strcmp(name,u.mobret())==0)
		flag=1;	
	}
	fin.close();
	if(flag==0)
	{
		cout<<"No Such User Exist. Press 1 to Try Again or Press 0 to Go Back: ";
		int choice;
		here4321:
		cin>>choice;
		if(choice==1)
			goto here1234;
		else if(choice==0)
			msg();
		else
			{
				cout<<"Invalid Choice. Enter Again: ";
				goto here4321;
			}
	}
	else
	{
		strcat(name,"mn");
		cout<<"Enter Message: ";
		gets(m.messageret());
		ofstream fout;
		fout.open(name,ios::app);
		strcpy(m.senderret(),mobi);
		fout.write((char*)&m,sizeof(m));
		fout.close();
		cout<<"Message Successfully Sent.\n";
	}
	getch();
	msg();
}

void msgchk()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"mn");
	ifstream fp;
	fp.open(temp,ios::in); 
	cout<<"You have the following new message(s): \n"<<endl;
	while(fp.read((char*)&m,sizeof(m)))
	{
		cout<<"From: ";
		puts(m.senderret());
		puts(m.messageret());
		cout<<endl;
	}
	fp.close();
	char tempo[100];
	strcpy(tempo,mobi);
	strcat(tempo,"mo");
	ofstream fout;
	fout.open(tempo,ios::app);
	ifstream fin;
	fin.open(temp,ios::in);
	while(fin.read((char*)&m,sizeof(m)))
		fout.write((char*)&m,sizeof(m));
	fin.close();
	fout.close();
	ofstream newn;
	newn.open(temp,ios::out);
	newn.close();
	getch();
	msg();
}

void msgold()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"mo");
	ifstream fp;
	fp.open(temp,ios::in);
	cout<<"You have the following old message(s): \n"<<endl;
	while(fp.read((char*)&m,sizeof(m)))
	{
		cout<<"From: ";
		puts(m.senderret());
		puts(m.messageret());
		cout<<endl;
	}
	fp.close();
	getch();
	msg();
}

void msgdel()
{
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"mo");
	ifstream fp;
	fp.open(temp,ios::in);
	int count=1;
	while(fp.read((char*)&m,sizeof(m)))
	{
		cout<<count<<". ";
		puts(m.senderret());
		puts(m.messageret());
		cout<<endl;	
		count++;
	}
	fp.close();
	cout<<"Enter message number for the message to be deleted: ";
	int choice;
	here127:
	cin>>choice;
	if(choice>=count)
	{
		cout<<"Invalid number. Enter again: ";
		goto here127;
	}
	else
	{	
		ofstream fout;
		fout.open("Temp",ios::out);
		ifstream fin;
		fin.open(temp,ios::in);
		long int pos=(choice*sizeof(m));
		while(fin.read((char*)&m,sizeof(m)))
		{
			int p=fin.tellg();
			if(p!=pos)
				fout.write((char*)&m,sizeof(m));
		}
		fin.close();
		fout.close();
		remove(temp);
		rename("Temp",temp);
		cout<<"Message Successfully Deleted.\n";
	}
	getch();
	msg();
}
	
//Messaging code ends

//Schedule code starts

class appointment{
	private:
		int year;
		int date;
		int month;
		char details[256];	
	public:
		void add();
		int yearret()
		{
			return year;
		}
		int dateret()
		{
			return date;
		}
		
		int monthret()
		{
			return month;
		}
		
		char* detailsret()
		{
			return details;
		}
}a;

void appointnew();
void appointchk();

void appointment::add()
{
	system("cls");
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	cout<<"Enter Appointment/Schedule/Event Details:\n";
	cout<<"Enter Year: ";
	here32:
	cin>>a.year;
	if(a.year<str_t.wYear || a.year<=0)
	{
		cout<<"This Year Has Passed. Enter Again: ";
		goto here32;
	}
	cout<<"Enter Month: ";
	here33:
	cin>>a.month;
	if(a.year==str_t.wYear && a.month<str_t.wMonth)
	{
		cout<<"This Month Has Passed. Enter Again: ";
		goto here33;
	}
	if(a.month>12 || a.month<=0)
	{
		cout<<"Invalid Month. Enter Again: ";
		goto here33;
	}
	cout<<"Enter Date: ";
 	here34:
 	cin>>a.date;
	if(a.year==str_t.wYear && a.month==str_t.wMonth	&& a.date<str_t.wDay)
	{
		cout<<"This Date Has Passed. Enter Again: ";
		goto here34;
	}
	if(a.date>31 || a.date<=0)
	{
		cout<<"Invalid Date. Enter Again: ";
		goto here34;
	}
	if((a.month==4 ||a.month==6 ||a.month==9 ||a.month==11) && a.date>30)
	{
		cout<<"Invalid Date. Enter Again: ";
		goto here34;
	}
	if(a.month==2 && a.year%4==0)
		if(a.date>29)
		{
			cout<<"Invalid Date. Enter Again: ";
			goto here34;
		}
	if(a.month==2 && a.year%4!=0)
		if(a.date>28)
		{
			cout<<"Invalid Date. Enter Again: ";
			goto here34;
		}
	cout<<"Enter Description of Appointment/Schedule/Event: ";
	cin.ignore();
	gets(a.details);
}
	
void appoint()
{
	system("cls");
	cout<<"1. Add New Appointment/Schedule";
	cout<<"\n2. Check For Upcoming Appointment(s)/Schedule(s)";
	cout<<"\n3. Go Back";
	cout<<"\nEnter choice: ";
	int choice;
	here895:
	cin>>choice;
	if(choice==1)
	appointnew();
	else if(choice==2)
	appointchk();
	else if(choice==3)
	menu();
	else
	{
		cout<<"Invalid Choice. Enter Again: ";
		goto here895;
	}
}

void appointnew()
{	
	a.add();
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"s");
	ofstream fp;
	fp.open(temp,ios::app); 
	fp.write((char*)&a,sizeof(a));
	cout<<"Appointment/Schedule/Event Added Successfully.\n";
	fp.close();
	getch();
	appoint();
}

void appointchk()
{
	system("cls");
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	system("cls");
	char temp[100];
	strcpy(temp,mobi);
	strcat(temp,"s");
	ifstream fp;
	fp.open(temp,ios::in);
	while(fp.read((char*)&a,sizeof(a)))
	{
		if(a.yearret()>str_t.wYear || (a.yearret()==str_t.wYear && a.monthret()>str_t.wMonth) ||(a.yearret()==str_t.wYear && a.monthret()==str_t.wMonth && a.dateret()>=str_t.wDay) )
		{
			cout<<"Date: "<<a.dateret()<<"/"<<a.monthret()<<"/"<<a.yearret()<<"\nDescription: ";
			puts(a.detailsret());
			cout<<endl;
		}
	}
	fp.close();
	getch();
	appoint();
}

//Schedule code ends

int main()
{
	startup();
}
