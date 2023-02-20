#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#include<fstream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

struct patient
{
    long long ID;
	string firstname;
	string lastname;
	int age;
	char blood[5];
	char gender;
    patient*next;
};
class linkedqueue
{
	patient *head,*last;
	public:
	linkedqueue() //constructor
	{
		head=NULL;
		last=NULL;
	}
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    void LoginScreen(void);
    char departmentname[50];
};

int linkedqueue :: search(int item)
{
	 if(head==NULL)
     return false;
     else
     {
     int flag=0;
     patient*p=new patient();
     p=head;

     while( p->next!=NULL && p->ID!=item )
     {
        p=p->next;
     }
     if(p->ID==item)
     {
	 	flag=1;
	 	return true;
     }
     if(flag==0)
     return false;
     }
}

int readnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

patient linkedqueue :: input()
{
    int flag=0;
   patient *p=new patient();
   cout << "\n\tPlease enter data for patient\n";
   cout<<"\n\tFirst name     : ";
   getline(cin,p->firstname);
   cout << "\tLast name      : ";
   getline(cin,p->lastname);
   again :
   cout << "\tBlood Group    : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\nWrong Entry...Enter a valid Blood Group..Try Again..";
        goto again;

    }
   cout<<"\tGender (m/f)     : ";
   cin>>p->gender;
   cout<<"\tAge              : ";
   cin>>p->age;
   cout<<"\tMobile number    : ";
   cin>>p->ID;


	if(search(p->ID))
	{
		p->ID=0;
		cout << "\n\tData not valid. Operation cancelled.";
	}
	return *p;
}

void output(patient *p)
{
	cout<<"\n**********************************";
	cout<<"\n\nPatient data:";
	cout<<"\n\nFirst Name       : "<<p->firstname;
	cout<<"\nLast Name          : "<<p->lastname;
	cout<<"\nGender             : "<<p->gender;
	cout<<"\nAge                : "<<p->age;
	cout<<"\nBlood Group        : "<<p->blood;
	cout<<"\nMobile Number      : "<<p->ID;
	cout<<"\n\n**********************************";
}
void linkedqueue :: insertatbeg()
{
     patient*p=new patient();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)

     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void linkedqueue:: insertatend()
{
     patient*p=new patient();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)
     {
     	head=p;
        last=p;
        p->next=NULL;
     }
     else
     {
     	p->next=NULL;
        last->next=p;
        last=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void linkedqueue :: getpatientout()
{
	 system("cls");
     if(head==NULL)
     {
     	cout<<"\n\tNo Patient to operate";
     }
     else
     {
     	patient*p=new patient();
     	p=head;
     	head=head->next;
 	    cout << "\n\tPatient to operate:";
        output(p);
 	 }
}

void linkedqueue :: listofpatients()
{
     if(head==NULL)
     {
     	cout<<"\n\tNo patient";
 	 }
     patient*p=new patient;
     p=head;
     while(p!=NULL)
     {
        cout<<"\nPatient data:";
		cout<<"\nFirst Name       : "<<p->firstname;
		cout<<"\nLast Name        : "<<p->lastname;
		cout<<"\nGender           : "<<p->gender;
        cout<<"\nAge              : "<<p->age;
        cout<<"\nBlood Group      : "<<p->blood;
		cout<<"\nMobile Number    : "<<p->ID;
		cout<<"\n**********************************\n";
        p=p->next;
     }
     cout<<"\n";
}


void departmentmenu (linkedqueue * q)
{
    int choice = 0, success;
    patient p;
    while (choice != 5)
	{
    system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t 	  LIFE CARE HOSPITAL  \n\n";
	cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
	cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
	cout<<"\t\t\t\t\t\t|                                           	                  |\n";
	cout<<"\t\t\t\t\t\t|             1  >> Add normal patient                            |\n";
	cout<<"\t\t\t\t\t\t|             2  >> Add critically ill patient                    |\n";
	cout<<"\t\t\t\t\t\t|             3  >> Take patient to Doctor                        |\n";
	cout<<"\t\t\t\t\t\t|             4  >> Display list                                  |\n";
	cout<<"\t\t\t\t\t\t|             5  >> Change department or exit                     |\n";
	cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	cout<<"\n\n\tPlease enter your choice : ";
	choice=readnumber();

    switch (choice)
	{
	  case 1:	q->insertatend();
				cout << "\n\tPress any key";
	    		getch();
	 			break;

      case 2:	q->insertatbeg();
	    		cout << "\n\tPress any key";
	    		getch();
				break;

      case 3:	q->getpatientout();
	 			cout<<"\n\tPress any key";
     			getch();
	      		break;

      case 4:	system("cls");
	 			q->listofpatients();
	 			cout<<"\n\tPress any key";
	 			getch();
				break;
	 }
    }
}

int main ()
{
    int i, choice = 0;
	linkedqueue departments[4];

	//printing the welcome note
re:
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t@@*****************************************************************************************@@\n";
cout<<"\t\t\t\t@@||                                           		                                 ||@@\n";
cout<<"\t\t\t\t@@||                                           		                                 ||@@\n";
cout<<"\t\t\t\t@@||                                           		                                 ||@@\n";
cout<<"\t\t\t\t@@||                                           		                                 ||@@\n";
cout<<"\t\t\t\t@@||                                           		                                 ||@@\n";
cout<<"\t\t\t\t@@||                                           		                                 ||@@\n";
cout<<"\t\t\t\t@@||                                  WELCOME TO                                         ||@@\n";
cout<<"\t\t\t\t@@||                                                                                     ||@@\n";
cout<<"\t\t\t\t@@||                      LIFE CARE HOSPITAL MANAGEMENT SYSTEM                           ||@@\n";
cout<<"\t\t\t\t@@||                                                                                     ||@@\n";
cout<<"\t\t\t\t@@||                                                                                     ||@@\n";
cout<<"\t\t\t\t@@||                                                                                     ||@@\n";
cout<<"\t\t\t\t@@||                                                                                     ||@@\n";
cout<<"\t\t\t\t@@||                                                                                     ||@@\n";
cout<<"\t\t\t\t@@||_____________________________________________________________________________________||@@\n";
cout<<"\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
system("pause");
system("cls");

int p;
int login();
login();

	while(choice!=5)
	{
		strcpy(departments[0].departmentname,"General Checkup\n");
		strcpy(departments[1].departmentname,"Heart Specialist\n");
		strcpy(departments[2].departmentname,"Bone & joints Specialist\n");
		strcpy(departments[3].departmentname,"Skin care\n");
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\n\t\t\t\t\t\t\t\t   LIFE CARE   \n\n";
		cout<<"\t\t\t\t\t\t\t   HOSPITAL MANAGEMENT SYSTEM\t\n";
		cout<<"\n\t\t\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		cout<<"\n\t\t\t\tPlease,  Choose from the following Options: \n\n";
		for (i = 0; i < 4; i++)
		{
			cout<<"\t"<<(i+1)<<": "<<departments[i].departmentname;
		}
		cout<<"\t5: Exit";
		cout<<"\n\n\tPlease enter your choice : ";
		choice=readnumber();
		if(choice>=1 && choice<=4)
		{
			departmentmenu(&departments[choice-1]);
		}

	}
	if(choice==5)
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t\t@@*******************************************************************************************@@\n";
	cout<<"\t\t\t\t@@||                                           		                                   ||@@\n";
	cout<<"\t\t\t\t@@||                                           		                                   ||@@\n";
	cout<<"\t\t\t\t@@||                                           		                                   ||@@\n";
	cout<<"\t\t\t\t@@||                                           		                                   ||@@\n";
	cout<<"\t\t\t\t@@||                                           		                                   ||@@\n";
	cout<<"\t\t\t\t@@||                               THANK YOU FOR USING                                     ||@@\n";
	cout<<"\t\t\t\t@@||                                                                                       ||@@\n";
	cout<<"\t\t\t\t@@||                       LIFE CARE HOSPITAL MANAGEMENT SYSTEM                            ||@@\n";
	cout<<"\t\t\t\t@@||                                                                                       ||@@\n";
	cout<<"\t\t\t\t@@||                                                                                       ||@@\n";
	cout<<"\t\t\t\t@@||                                                                                       ||@@\n";
	cout<<"\t\t\t\t@@||                                                                                       ||@@\n";
	cout<<"\t\t\t\t@@||                                                                                       ||@@\n";
	cout<<"\t\t\t\t@@||                                                                   -Visit Again        ||@@\n";
	cout<<"\t\t\t\t@@||_______________________________________________________________________________________||@@\n";
	cout<<"\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
	exit(0);

}
int login(){
   string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t  LIFE CARE HOSPITAL MANAGEMENT SYSTEM \n\n";
   cout<<"\t\t\t\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
   cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n";
   cout << "\t\t\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "admin"){
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}

