#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

char ans=0;
int ok;
int b,valid=0;

void WelcomeScreen();
void title();
void Mainmenu();
void loginscreen();
void add_rec();
void func_list();
void search_rec();
void edit_rec();
void dlt_rec();
void ex_it();
void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

struct student
{
		int age;
		char gender;
		char first_name[20];
		char last_name[20];
		char contact_no[15];
		char address[20];
		char faculty[20];
		char ID[20];
};
struct student s,s1;

int main(){
	WelcomeScreen();
	title();
	loginscreen();
	return 0;
}
void WelcomeScreen(){
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t#########################################";
	cout<<"\n\t\t\t\t#\t\tWELCOME TO\t\t#";
	cout<<"\n\t\t\t\t#\tSTUDENT MANAGEMENT SYSTEM\t#";
	cout<<"\n\t\t\t\t#########################################";
	cout<<"\n\n\n\n\n\n\t\t\t\tPress any key to continue ...............";
	getch();
	system("cls");	
}

void title(){
	cout<<"\n\t\t\t------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t  STUDENT MANAGEMENT SYSTEM  ";
	cout<<"\n\t\t\t------------------------------------------------------------";
}

void Mainmenu(){
	system("cls");
	title();
	int choice;
	cout<<"\n\n\t\t\t____________________________________________________________\n";
    cout<<"\n\t\t\t 1. ADD STUDENTS RECORD.\n\n";
    cout<<"\t\t\t 2. LIST STUDENTS RECORD.\n\n";
    cout<<"\t\t\t 3. SEARCH STUDENTS RECORD.\n\n";
    cout<<"\t\t\t 4. EDIT STUDENTS RECORD.\n\n";
    cout<<"\t\t\t 5. DELETE STUDENTS RECORD.\n\n";
    cout<<"\t\t\t 6. EXIT.\n";
    cout<<"\t\t\t____________________________________________________________\n\n";
    while(1){
    cout<<"\n\t\t\tCHOOSE FROM 1 TO 6:";  
    cin>>choice;          
    switch(choice)
    {
                case 1:
                	add_rec();
                    break;
                case 2:
                	func_list();
                    break;
                case 3:
					search_rec();
                    break;
                case 4:
                	edit_rec();
                	break;
                case 5:
                	dlt_rec();
					break;
                case 6:
                    ex_it();
                    exit(6);
                default:
                cout<<"\n\n\t\t\t# Do read the instruction properly and Enter valid operator #\n\n";
        }
    }
}
void loginscreen(){
	int e=0;
	char Username[15];
	char Password[15];
	char original_username[15]="project";
	char original_password[15]="c++";
	do{
		cout<<"\n\n\n\n\t\t\t\t PLEASE ENTER USERNAME AND PASSWORD:\n";
		cout<<"\n\n\t\t\t\t USERNAME:";
		cin>>Username;
		cout<<"\n\t\t\t\t PASSWORD:";
		cin>>Password;
		if(strcmp(Username,original_username)==0 && strcmp(Password,original_password)==0)
		{
			cout<<"\n\n\n\t\t\t.....................LOGIN SUCCESSFULL......................";
			getch();
			Mainmenu();		
			break;
		}
		else
		{
			cout<<"\n\n\t\t\t\t PASSWORD IS INCORRECT (PLEASE TRY AGAIN).";
			e++;
			getch();
		}
	}while(e<=2);
	if(e>2)
	{
		cout<<"\n\n\n\t\t\t\t You have crossed the limit.You cannot login.";
		getch();
		ex_it();
	}
	system("cls");	
}

void add_rec()
{
	system("cls");
	title();
	ofstream outf("record1.txt",ios::app);//file open in append mode
	cout<<"\n\n\n\t\t\t******************* ADD STUDENTS DETIALS *******************\n";
	A:
		cout<<"\n\t\t\tFirst Name:";
		cin>>s.first_name;
		s.first_name[0]=toupper(s.first_name[0]);
		if(strlen(s.first_name)>20||strlen(s.first_name)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for first name is 20 and min range is 2\n";
			goto A;
		}
		else
		{
			for(b=0;b<strlen(s.first_name);b++)
		 	{
		 		if(isalpha(s.first_name[b]))
				 {
				 	valid=1;
					 }
				else
				{
					valid=0;
					break;
				}
		 	}
			 if(!valid)	
			 {
			 	cout<<"\n\t\t\tINVALID:First name contains invalid character.\n";
			 	goto A;
			 }
		}
	B:
		cout<<"\n\t\t\tLast Name:";
		cin>>s.last_name;
		s.last_name[0]=toupper(s.last_name[0]);
		if(strlen(s.last_name)>20||strlen(s.last_name)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for last name is 20 and min range is 2\n";
			goto B;
		}
		else
		{
			for(b=0;b<strlen(s.last_name);b++)
		 	{
		 		if(isalpha(s.last_name[b]))
				 {
				 	valid=1;
					}
				else
				{
					valid=0;
					break;
				}
		 	}
			 if(!valid)	
			 {
			 	cout<<"\n\t\t\tINVALID:Last name contains invalid character.\n";
			 	goto B;
			 }
		}
	
	C:
			cout<<"\n\t\t\tGender[M/F]:";
			cin>>s.gender;
			if(toupper(s.gender)=='M'|| toupper(s.gender)=='F')
			{
				ok=1;
			}
			else
			{
				ok=0;	
			}
			if(!ok)
			{
				cout<<"\n\t\t\tINVALID:Gender contains invalid character.\n";
				goto C;
			}		
		
		
		cout<<"\n\t\t\tAge:";
		cin>>s.age;
		
	D:
		cout<<"\n\t\t\tAddress:";
		cin>>s.address;
		s.address[0]=toupper(s.address[0]);
		if(strlen(s.address)>20||strlen(s.address)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for address is 20 and min range is 2.\n";
			goto D;
		}
		
	E:
		cout<<"\n\t\t\tContact no:";
		cin>>s.contact_no;
		if(strlen(s.contact_no)>10||strlen(s.contact_no)!=10)
		{
			cout<<"\n\t\t\tINVALID:The contact no. must contain 10 numbers.\n";
			goto E;
		}
	
	F:
		cout<<"\n\t\t\tFaculty:";
		cin>>s.faculty;
		s.faculty[0]=toupper(s.faculty[0]);
		if(strlen(s.last_name)>20||strlen(s.last_name)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for last name is 20 and min range is 2\n";
			goto F;
		}
		else
		{
			for(b=0;b<strlen(s.faculty);b++)
		 	{
		 		if(isalpha(s.faculty[b]))
				 {
				 	valid=1;
				 }
				else
				{
					valid=0;
					break;
				}
		 	}
		if(!valid)	
			 {
			 	cout<<"\n\t\t\tINVALID:Faculty contains invalid character.\n";
			 	goto F;
			 }
		}
		G:
		cout<<"\n\t\t\tID:";
		cin>>s.ID;
		if(strlen(s.ID)>5||strlen(s.ID)<3)
		{
			cout<<"\n\t\t\tINVALID:The max range for ID is 5 and min range is 3\n";
			goto G;
		}
		
		outf<<s.first_name<<' '<<s.last_name<<' '<<s.gender<<' '<<s.age<<' '<<s.address<<' '<<s.contact_no<<' '<<s.faculty<<' '<<s.ID<<endl;
		cout<<"\n\n\t\t\t************* INFORMATION RECORDED SUCCESSFULLY *************\n";
		outf.close();//file close
		
		sd:
			cout<<"\n\n\t\t\tDo you want to add more records?[Y/N]:";
			cin>>ans;
			if(toupper(ans)=='Y')
			{
				add_rec();
			}
			else if(toupper(ans)=='N')
			{
			 cout<<"\n\n\t\t\tTHANK YOU FOR ADDING RECORDS.";
			 getch();
			 Mainmenu();		
			}
			else
			{
			 cout<<"\n\t\t\tINVALID:Contains invalid input.\n";
			 goto sd;	
			}			
}
void func_list()
{
	int row;
	system("cls");
	title();
	ifstream inf("record1.txt",ios::in);
	cout<<"\n\n\n\t\t\t****************** LIST OF STUDENTS DETIALS ****************\n";
	gotoxy(17,11);
	cout<<"FULL NAME";
	gotoxy(37,11);
	cout<<"GENDER";
	gotoxy(49,11);
	cout<<"AGE";
	gotoxy(56,11);
	cout<<"ADDRESS";
	gotoxy(68,11);
	cout<<"CONTACT NO.";
	gotoxy(83,11);
	cout<<"FACULTY";
	gotoxy(94,11);
	cout<<"ID\n";
	cout<<"\t\t===================================================================================";
	row=13;
	while(inf>>s.first_name>>s.last_name>>s.gender>>s.age>>s.address>>s.contact_no>>s.faculty>>s.ID)
	{
		gotoxy(17,row);
		cout<<s.first_name<<' '<<s.last_name;
		gotoxy(37,row);
		cout<<s.gender;
		gotoxy(49,row);
		cout<<s.age;
		gotoxy(56,row);
		cout<<s.address;
		gotoxy(68,row);
		cout<<s.contact_no;
		gotoxy(83,row);
		cout<<s.faculty;
		gotoxy(94,row);
		cout<<s.ID;
		row++;
	}
	inf.close();
	cout<<"\n\t\t===================================================================================";
	getch();
	Mainmenu();				
}
void search_rec()
{
	char id1[20];
	system("cls");
	title();
	ifstream inf("record1.txt",ios::in);
	cout<<"\n\n\n\t\t\t******************* SEARCH STUDENTS DETIALS ****************\n";
	cout<<"\n\n\t\t\tEnter the ID of student to be viewed:";
	cin>>id1;
	fflush(stdin);
	while(inf>>s.first_name>>s.last_name>>s.gender>>s.age>>s.address>>s.contact_no>>s.faculty>>s.ID)
	{
	if(strcmp(s.ID,id1)==0)
	{
	gotoxy(17,13);
	cout<<"FULL NAME";
	gotoxy(37,13);
	cout<<"GENDER";
	gotoxy(49,13);
	cout<<"AGE";
	gotoxy(56,13);
	cout<<"ADDRESS";
	gotoxy(68,13);
	cout<<"CONTACT NO.";
	gotoxy(83,13);
	cout<<"FACULTY";
	gotoxy(94,13);
	cout<<"ID\n";
	cout<<"\t\t===================================================================================";
	gotoxy(17,15);
	cout<<s.first_name<<' '<<s.last_name;
	gotoxy(37,15);
	cout<<s.gender;
	gotoxy(49,15);
	cout<<s.age;
	gotoxy(56,15);
	cout<<s.address;
	gotoxy(68,15);
	cout<<s.contact_no;
	gotoxy(83,15);
	cout<<s.faculty;
	gotoxy(94,15);
	cout<<s.ID;
	cout<<"\n\t\t===================================================================================";
	break;
	}
	}
	if(strcmp(s.ID,id1)!=0)
		{
		cout<<"\n\t\t\tRecord of student not found.";
		getch();
	}
	inf.close();
	L:
		getch();
		cout<<"\n\n\n\t\t\tDo you want to view more records?[Y/N]:";
		cin>>ans;
		if(toupper(ans)=='Y')
		{
			search_rec();
		}
		else if(toupper(ans)=='N')
		{
		cout<<"\n\n\t\t\tTHANK YOU FOR VIEWING RECORDS.";
		getch();
		Mainmenu();		
		}
		else
		{
		cout<<"\n\t\t\tINVALID:Contains invalid input.\n";
		goto L;	
		}	
}
void edit_rec()
{
	int i,b,valid1=0;
	char id[20];
	system("cls");
	title();
	ifstream inf("record1.txt",ios::in);
	ofstream outf("temp1.txt",ios::out);
	cout<<"\n\n\n\t\t\t******************** EDIT STUDENTS DETIALS *****************\n";
	cout<<"\n\n\t\t\tEnter the ID of student to be edited:";
	cin>>id;
	fflush(stdin);
		while(inf>>s.first_name>>s.last_name>>s.gender>>s.age>>s.address>>s.contact_no>>s.faculty>>s.ID)
	{
	if(strcmp(s.ID,id)!=0)
	{
		outf<<s.first_name<<' '<<s.last_name<<' '<<s.gender<<' '<<s.age<<' '<<s.address<<' '<<s.contact_no<<' '<<s.faculty<<' '<<s.ID<<endl;	
	}
	else
	{
	valid1=1;
	cout<<"\n\t\t\tThe existing detials of the student is:";
	gotoxy(17,13);
	cout<<"FULL NAME";
	gotoxy(37,13);
	cout<<"GENDER";
	gotoxy(49,13);
	cout<<"AGE";
	gotoxy(56,13);
	cout<<"ADDRESS";
	gotoxy(68,13);
	cout<<"CONTACT NO.";
	gotoxy(83,13);
	cout<<"FACULTY";
	gotoxy(94,13);
	cout<<"ID\n";
	cout<<"\t\t===================================================================================";
	gotoxy(17,15);
	cout<<s.first_name<<' '<<s.last_name;
	gotoxy(37,15);
	cout<<s.gender;
	gotoxy(49,15);
	cout<<s.age;
	gotoxy(56,15);
	cout<<s.address;
	gotoxy(68,15);
	cout<<s.contact_no;
	gotoxy(83,15);
	cout<<s.faculty;
	gotoxy(94,15);
	cout<<s.ID;
	cout<<"\n\t\t===================================================================================\n";
	
	A:
	cout<<"\n\t\t\tEnter the new First Name:";
		cin>>s1.first_name;
		s1.first_name[0]=toupper(s1.first_name[0]);
		if(strlen(s1.first_name)>20||strlen(s1.first_name)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for first name is 20 and min range is 2\n";
			goto A;
		}
		else
		{
			for(b=0;b<strlen(s1.first_name);b++)
		 	{
		 		if(isalpha(s1.first_name[b]))
				 {
				 	valid=1;
					 }
				else
				{
					valid=0;
					break;
				}
		 	}
			 if(!valid)	
			 {
			 	cout<<"\n\t\t\tINVALID:First name contains invalid character.\n";
			 	goto A;
			 }
		}
	B:
		cout<<"\n\t\t\tEnter the new Last Name:";
		cin>>s1.last_name;
		s1.last_name[0]=toupper(s1.last_name[0]);
		if(strlen(s1.last_name)>20||strlen(s1.last_name)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for last name is 20 and min range is 2\n";
			goto B;
		}
		else
		{
			for(b=0;b<strlen(s1.last_name);b++)
		 	{
		 		if(isalpha(s1.last_name[b]))
				 {
				 	valid=1;
					}
				else
				{
					valid=0;
					break;
				}
		 	}
			 if(!valid)	
			 {
			 	cout<<"\n\t\t\tINVALID:Last name contains invalid character.\n";
			 	goto B;
			 }
		}
	
	C:
			cout<<"\n\t\t\tEnter the Gender[M/F]:";
			cin>>s1.gender;
			if(toupper(s1.gender)=='M'|| toupper(s1.gender)=='F')
			{
				ok=1;
			}
			else
			{
				ok=0;	
			}
			if(!ok)
			{
				cout<<"\n\t\t\tINVALID:Gender contains invalid character.\n";
				goto C;
			}		
		
		
		cout<<"\n\t\t\tEnter the Age:";
		cin>>s1.age;
		
	D:
		cout<<"\n\t\t\tEnter the Address:";
		cin>>s1.address;
		s1.address[0]=toupper(s1.address[0]);
		if(strlen(s1.address)>20||strlen(s1.address)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for address is 20 and min range is 2.\n";
			goto D;
		}
		
	E:
		cout<<"\n\t\t\tEnter the Contact no:";
		cin>>s1.contact_no;
		if(strlen(s1.contact_no)>10||strlen(s1.contact_no)!=10)
		{
			cout<<"\n\t\t\tINVALID:The contact no. must contain 10 numbers.\n";
			goto E;
		}
	
	F:
		cout<<"\n\t\t\tEnter the Faculty:";
		cin>>s1.faculty;
		s1.faculty[0]=toupper(s1.faculty[0]);
		if(strlen(s1.last_name)>20||strlen(s1.last_name)<2)
		{
			cout<<"\n\t\t\tINVALID:The max range for last name is 20 and min range is 2\n";
			goto F;
		}
		else
		{
			for(b=0;b<strlen(s1.faculty);b++)
		 	{
		 		if(isalpha(s1.faculty[b]))
				 {
				 	valid=1;
				 }
				else
				{
					valid=0;
					break;
				}
		 	}
		if(!valid)	
			 {
			 	cout<<"\n\t\t\tINVALID:Faculty contains invalid character.\n";
			 	goto F;
			 }
		}
		G:
		cout<<"\n\t\t\tEnter the ID:";
		cin>>s1.ID;
		if(strlen(s1.ID)>5||strlen(s1.ID)<3)
		{
			cout<<"\n\t\t\tINVALID:The max range for ID is 5 and min range is 3\n";
			goto G;
		}
		outf<<s1.first_name<<' '<<s1.last_name<<' '<<s1.gender<<' '<<s1.age<<' '<<s1.address<<' '<<s1.contact_no<<' '<<s1.faculty<<' '<<s1.ID<<endl;
		cout<<"\n\n\t\t\t************** INFORMATION EDITED SUCCESSFULLY **************";
	}
}
	if(!valid1)
		{
		cout<<"\n\t\t\tRecord of student not found.";
		getch();
				again:
			cout<<"\n\n\t\t\tDo you want to edit again records?[Y/N]:";
			cin>>ans;
			if(toupper(ans)=='Y')
			{
				edit_rec();
			}
			else if(toupper(ans)=='N')
			{
			 cout<<"\n\n\t\t\tTHANK YOU FOR EDITING RECORDS.";
			 getch();
			 Mainmenu();		
			}
			else
			{
			 cout<<"\n\t\t\tINVALID:Contains invalid input.\n";
			 goto again;	
			}
		}
	inf.close();
	outf.close();
	remove("record1.txt");
	rename("temp1.txt","record1.txt");
	getch();
	Mainmenu();		
}
void dlt_rec()
{
	int found=0;
	char id[20];
	system("cls");
	title();
	ifstream inf("record1.txt",ios::in);
	ofstream outf("temp2.txt",ios::out);
	cout<<"\n\n\n\t\t\t******************* DELETE STUDENTS DETIALS ****************\n";
	cout<<"\n\n\t\t\tEnter the ID of student to be deleted:";
	cin>>id;
	fflush(stdin);
	while(inf>>s.first_name>>s.last_name>>s.gender>>s.age>>s.address>>s.contact_no>>s.faculty>>s.ID)
	{
	if(strcmp(s.ID,id)!=0)
	{
		outf<<s.first_name<<' '<<s.last_name<<' '<<s.gender<<' '<<s.age<<' '<<s.address<<' '<<s.contact_no<<' '<<s.faculty<<' '<<s.ID<<endl;		
	}
	else
	{
		found=1;
	}
	}
	if(found==0)
	{
		cout<<"\n\t\t\tRecord of student not found.";
			again:
			cout<<"\n\n\t\t\tDo you want to delete again records?[Y/N]:";
			cin>>ans;
			if(toupper(ans)=='Y')
			{
				dlt_rec();
			}
			else if(toupper(ans)=='N')
			{
			 cout<<"\n\n\t\t\tTHANK YOU FOR DELETING RECORDS.";
			 getch();
			 Mainmenu();		
			}
			else
			{
			 cout<<"\n\t\t\tINVALID:Contains invalid input.\n";
			 goto again;	
			}
	}
	else
	{
		inf.close();
		outf.close();
		remove("record1.txt");
		rename("temp2.txt","record1.txt");
		cout<<"\n\n\t\t\t************** INFORMATION DELETED SUCCESSFULLY ************";
		getch();
		Mainmenu();
	}
		
}
void ex_it(){
	system("cls");
	title();
	cout<<"\n\n\n\n\n\t\t\t\t\tTHANK YOU FOR USING OUR SYSTEM.";
	getch();
}



